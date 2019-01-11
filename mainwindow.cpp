/*
This software is part of qtcsdr.

Copyright (c) 2015, Andras Retzler <randras@sdr.hu>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ANDRAS RETZLER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QProcess>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <math.h>

#define CMD_IQSERVER "pgroup -9 rtl_tcp -a 127.0.0.1 -s %SAMP_RATE% -p 4950 -f 89500000"
#define CMD_DISTRIB "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4950; sleep .3; done) | nmux -p 4951 -a 127.0.0.1 -b %NMUX_BUFSIZE% -n %NMUX_BUFCNT%\""
#define CMD_MOD_WFM "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %WFM_DECIM% 0.05 HAMMING  | csdr fmdemod_quadri_cf | csdr fractional_decimator_ff 5 | csdr deemphasis_wfm_ff 48000 50e-6 | csdr convert_f_i16 |  %AUDIOPLAYER%\""
#define CMD_MOD_NFM "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr fmdemod_quadri_cf | csdr limit_ff | csdr deemphasis_nfm_ff 48000 | csdr fastagc_ff | csdr convert_f_i16 |       %AUDIOPLAYER%\""
#define CMD_MOD_AM  "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr amdemod_cf | csdr fastdcblock_ff | csdr agc_ff | csdr limit_ff | csdr convert_f_i16 |                           %AUDIOPLAYER%\""
#define CMD_MOD_CW "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr bandpass_fir_fft_cc 0 0.025 0.05 | csdr realpart_cf | csdr agc_ff | csdr limit_ff | csdr convert_f_i16 |          %AUDIOPLAYER%\""
#define CMD_MOD_USB "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr bandpass_fir_fft_cc 0 0.1 0.05 | csdr realpart_cf | csdr agc_ff | csdr limit_ff | csdr convert_f_i16 |          %AUDIOPLAYER%\""
#define CMD_MOD_LSB "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr shift_addition_cc --fifo %FIFO% | csdr fir_decimate_cc %DECIM% 0.005 HAMMING | csdr bandpass_fir_fft_cc -0.1 0 0.05 | csdr realpart_cf | csdr agc_ff | csdr limit_ff | csdr convert_f_i16 |         %AUDIOPLAYER%\""
#define CMD_FFT     "pgroup -9 bash -c \"(for anything in {0..10}; do ncat 127.0.0.1 4951; sleep .3; done) | csdr convert_u8_f | csdr fft_cc 2048 %FFT_READ_SIZE% | csdr logpower_cf -70 | csdr fft_exchange_sides_ff 2048\""

#define CMD_ARECORD "arecord %ADEVICE% -f S16_LE -r 48000 -c 1"
#define CMD_CW "sudo rpitxiambic -i -w 20 -f "

#define CMD_TX_WFM  "pgroup bash -c \"%ARECORDCMD% | csdr convert_i16_f | csdr gain_ff 70000 | csdr convert_f_samplerf 20833 | (gksu touch; sudo rpitx -i- -m RF -f %TXFREQ%)\""
#define CMD_TX_NFM  "pgroup bash -c \"%ARECORDCMD% | csdr convert_i16_f | csdr gain_ff 7000 | csdr convert_f_samplerf 20833 | (gksu touch; sudo rpitx -i- -m RF -f %TXFREQ%)\""
#define CMD_TX_AM   "pgroup bash -c \"%ARECORDCMD% | csdr convert_i16_f | csdr dsb_fc | csdr add_dcoffset_cc | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_AM%)\""
#define CMD_TX_CW   "pgroup bash -c \"%CWCMD% %TXFREQ_CW%\""
#define CMD_TX_USB  "pgroup bash -c \"%ARECORDCMD% | csdr convert_i16_f | csdr dsb_fc | csdr bandpass_fir_fft_cc 0 0.1 0.01 | csdr gain_ff 2 | csdr shift_addition_cc 0.2 | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_SSB%)\""
#define CMD_TX_LSB  "pgroup bash -c \"%ARECORDCMD% | csdr convert_i16_f | csdr dsb_fc | csdr bandpass_fir_fft_cc -0.1 0 0.01 | csdr gain_ff 2 | csdr shift_addition_cc 0.2 | (gksu touch; sudo rpitx -i- -m IQFLOAT -f %TXFREQ_SSB%)\""

#define NMUX_MEMORY_MBYTE 50

//#define CMD_WFM "pgroup -9 bash -c \"rtl_tcp -s 2400000 -p 4951 -f 89500000 & (sleep 1; nc localhost 4951 | csdr convert_u8_f | csdr shift_addition_cc -0.085 | csdr fir_decimate_cc 10 0.05 HAMMING | csdr fmdemod_quadri_cf | csdr fractional_decimator_ff 5 | csdr deemphasis_wfm_ff 48000 50e-6 | csdr convert_f_i16 | mplayer -cache 768 -quiet -rawaudio samplesize=2:channels=1:rate=48000 -demuxer rawaudio -)\""

int upconvvalue = 0;

QFont fon( "SansSerif", 12, QFont::Bold);
QFont foff( "SansSerif", 12, QFont::Normal);


QPushButton* iFch;



QString MainWindow::getNextArgAfter(QString what)
{
    if(QCoreApplication::arguments().contains(what))
    {
        int indexOfWhat = QCoreApplication::arguments().indexOf(what);
        if(QCoreApplication::arguments().count()>indexOfWhat+1)
        {
            if(!QCoreApplication::arguments().at(indexOfWhat+1).startsWith("--"))
            {
                return QCoreApplication::arguments().at(indexOfWhat+1);
            }
        }
    }
    return "";
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), qStdOut(stdout)
{
    ui->setupUi(this);

    if(QCoreApplication::arguments().contains("--rpitx"))
    {
        ui->toggleTransmit->setEnabled(true);
        ui->comboSampRate->setCurrentIndex(4);
        //this->resize(this->width(),ui->tabWidgetControls->height()+350);
    }

    QString nextArg;

    if(QCoreApplication::arguments().contains("--mplayer"))
    {
         audioPlayerCommand="mplayer -cache 1024 -quiet -rawaudio samplesize=2:channels=1:rate=48000 %ADEVICE% -demuxer rawaudio -";
         if(!(alsaDevice=getNextArgAfter("--mplayer")).isEmpty())
         {
             audioPlayerCommand=audioPlayerCommand.replace("%ADEVICE%",QString("-ao alsa:device=")+alsaDevice.replace(",",".").replace(":","="));
         }
         else
             audioPlayerCommand=audioPlayerCommand.replace("%ADEVICE%","");
    }
    else
    {
        audioPlayerCommand  = "csdr mono2stereo_i16 | aplay -f S16_LE -r48000 -c2 -D ";
        if (!(alsaDevice=getNextArgAfter("--alsa")).isEmpty())
            audioPlayerCommand+=alsaDevice;
        else
            audioPlayerCommand+="default";
    }
    qDebug() << audioPlayerCommand;

    modsButtons.append(ui->toggleAM);
    modsButtons.append(ui->toggleCW);
    modsButtons.append(ui->toggleNFM);
    modsButtons.append(ui->toggleWFM);
    modsButtons.append(ui->toggleLSB);
    modsButtons.append(ui->toggleUSB);

    modsButtonsF.append(ui->VFOH);
    modsButtonsF.append(ui->VFOK);
    modsButtonsF.append(ui->VFOM);
    modsButtonsF.append(ui->VFOG);
    modsButtonsF.append(ui->FQH);
    modsButtonsF.append(ui->FQK);
    modsButtonsF.append(ui->FQM);
    modsButtonsF.append(ui->FQG);
    modsButtonsF.append(ui->OFH);
    modsButtonsF.append(ui->OFK);
    modsButtonsF.append(ui->OFM);

    iFch = ui->VFOH;
    fon = ui->VFOH->font();
    foff = ui->VFOG->font();

    connect(&tmrRead, SIGNAL(timeout()), this, SLOT(tmrRead_timeout()));
    connect(ui->widgetFFT, SIGNAL(shiftChanged(int)), this, SLOT(on_shiftChanged(int)));
    tmrRead.start(10);
}

void MainWindow::untoggleOtherModButtonsThan(QPushButton* pb)
{
    static bool protect;
    if(protect) return;
    protect = true;
    foreach(QPushButton* ipb, modsButtons) if(ipb!=pb) ipb->setChecked(false); else pb->setChecked(true);
    protect = false;

    //we select the new demodulator
    if(ui->toggleRun->isChecked())
    {
        if(procDemod.pid()) kill(procDemod.pid(), SIGTERM);
        procDemod.waitForFinished(1000);
        procDemod.start(getDemodulatorCommand());
        procDemod.waitForStarted(1000);
        setShift();
    }

    updateFilterBw();
}


void MainWindow::untoggleOtherFbutton(QPushButton* pb)
{
    static bool protect;
    if(protect) return;
    protect = true;
    foreach(QPushButton* ipb, modsButtonsF) if(ipb!=pb) ipb->setFont(foff); else pb->setFont(fon);
    protect = false;
    iFch = pb;

}

void MainWindow::redirectProcessOutput(QProcess &proc, bool onlyStdErr)
{
    if(proc.pid()!=0)
    {
        QString temp = ((onlyStdErr)?"":proc.readAllStandardOutput()) + proc.readAllStandardError();
        if(temp.length()) qStdOut << temp;
    }
    qStdOut.flush();
}

void MainWindow::tmrRead_timeout()
{
    redirectProcessOutput(procDemod);
    redirectProcessOutput(procDistrib);
    redirectProcessOutput(procIQServer);
    redirectProcessOutput(procFFT, true);
    redirectProcessOutput(procTX);

    if(procFFT.pid()!=0)
    {
        FFTDataBuffer += procFFT.readAll();
        while(ui->widgetFFT->takeOneWaterfallLine(&FFTDataBuffer));
    }

}

MainWindow::~MainWindow()
{
    if(ui->toggleRun->isChecked()) on_toggleRun_toggled(false); //so that we kill all subprocesses
    delete ui;
}

void MainWindow::on_toggleWFM_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleWFM); }
void MainWindow::on_toggleNFM_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleNFM); }
void MainWindow::on_toggleAM_toggled(bool checked)  { untoggleOtherModButtonsThan(ui->toggleAM); }
void MainWindow::on_toggleUSB_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleUSB); }
void MainWindow::on_toggleLSB_toggled(bool checked) { untoggleOtherModButtonsThan(ui->toggleLSB); }
void MainWindow::on_toggleCW_toggled(bool checked)  { untoggleOtherModButtonsThan(ui->toggleCW); }


void MainWindow::on_VFOH_pressed() {untoggleOtherFbutton(ui->VFOH);}
void MainWindow::on_VFOK_pressed() {untoggleOtherFbutton(ui->VFOK);}
void MainWindow::on_VFOM_pressed() {untoggleOtherFbutton(ui->VFOM);}
void MainWindow::on_VFOG_pressed() {untoggleOtherFbutton(ui->VFOG);}

void MainWindow::on_FQH_pressed() {untoggleOtherFbutton(ui->FQH);}
void MainWindow::on_FQK_pressed() {untoggleOtherFbutton(ui->FQK);}
void MainWindow::on_FQM_pressed() {untoggleOtherFbutton(ui->FQM);}
void MainWindow::on_FQG_pressed() {untoggleOtherFbutton(ui->FQG);}

void MainWindow::on_OFH_pressed() {untoggleOtherFbutton(ui->OFH);}
void MainWindow::on_OFK_pressed() {untoggleOtherFbutton(ui->OFK);}
void MainWindow::on_OFM_pressed() {untoggleOtherFbutton(ui->OFM);}


void MainWindow::on_FP100_pressed(){modF(100,iFch);}
void MainWindow::on_FP10_pressed(){modF(10,iFch);}
void MainWindow::on_FP1_pressed(){modF(1,iFch);}
void MainWindow::on_FM100_pressed(){modF(-100,iFch);}
void MainWindow::on_FM10_pressed(){modF(-10,iFch);}
void MainWindow::on_FM1_pressed(){modF(-1,iFch);}


void MainWindow::updateVFOvalue(int value){
    QString QtotalVFO = QString::number(value);
    for (int i=QtotalVFO.length(); i<12; i++) QtotalVFO = "0" + QtotalVFO;
    ui->VFOG->setText(QtotalVFO.mid(0,3));
    ui->VFOM->setText(QtotalVFO.mid(3,3));
    ui->VFOK->setText(QtotalVFO.mid(6,3));
    ui->VFOH->setText(QtotalVFO.mid(9,3));
}

void MainWindow::updateFQvalue(int value){
    QString QtotalFQ = QString::number(value);
    for (int i=QtotalFQ.length(); i<12; i++) QtotalFQ = "0" + QtotalFQ;
    ui->FQG->setText(QtotalFQ.mid(0,3));
    ui->FQM->setText(QtotalFQ.mid(3,3));
    ui->FQK->setText(QtotalFQ.mid(6,3));
    ui->FQH->setText(QtotalFQ.mid(9,3));
}

void MainWindow::updateOFvalue(int value){
    QString QtotalOF = QString::number(value);
    for (int i=QtotalOF.length(); i<12; i++) QtotalOF = " " + QtotalOF;
    ui->OFM->setText(QtotalOF.mid(3,3));
    ui->OFK->setText(QtotalOF.mid(6,3));
    ui->OFH->setText(QtotalOF.mid(9,3));
}

int MainWindow::getVFOvalue(){
    return (ui->VFOG->text()+ui->VFOM->text()+ui->VFOK->text()+ui->VFOH->text()).toInt();
}

int MainWindow::getFQvalue(){
    return (ui->FQG->text()+ui->FQM->text()+ui->FQK->text()+ui->FQH->text()).toInt();
}

int MainWindow::getOFvalue(){
    return (ui->OFM->text()+ui->OFK->text()+ui->OFH->text()).toInt();
}

void MainWindow::modF(int value, QPushButton* pb){

    QString test = pb->objectName();
    QChar c = test.at(0);
    int chose = c.toLatin1();
    c = test.at((test.length()-1));
    int choseend = c.toLatin1();

    printf("a %i\n",chose);
    printf("b %i\n",choseend);

    int totalVFO = getVFOvalue();
    int totalFQ = getFQvalue();
    int totalOF = getOFvalue();



    switch(choseend) {
        case 72 : value = value; break;
        case 75 : value *= 1000; break;
        case 77 : value *= 1000000; break;
        case 69 : value *= 1000000000; break;
    }

    switch(chose) {
        case 86 : totalVFO +=  value; totalFQ = totalVFO + totalOF; break;
        case 70 : totalFQ +=  value; totalVFO =  totalFQ - totalOF; break;
        case 79 : totalOF +=  value; totalFQ = totalVFO + totalOF;break;
    }

    updateVFOvalue(totalVFO);
    updateFQvalue(totalFQ);
    updateOFvalue(totalOF);

    switch(chose) {
        case 86 : sendCommand(RTLTCP_SET_FREQ, totalVFO+upconvvalue); break;
        case 70 : sendCommand(RTLTCP_SET_FREQ, totalVFO+upconvvalue); break;
        case 79 : setShift();break;
    }


}



void MainWindow::on_shiftChanged(int newOffset)
{
    updateOFvalue(newOffset);setShift();
}

QString MainWindow::getDemodulatorCommand()
{
    QString myDemodCmd;
    if(ui->toggleWFM->isChecked()) myDemodCmd=CMD_MOD_WFM;
    if(ui->toggleNFM->isChecked()) myDemodCmd=CMD_MOD_NFM;
    if(ui->toggleAM->isChecked())  myDemodCmd=CMD_MOD_AM;
    if(ui->toggleCW->isChecked())  myDemodCmd=CMD_MOD_CW;
    if(ui->toggleLSB->isChecked()) myDemodCmd=CMD_MOD_LSB;
    if(ui->toggleUSB->isChecked()) myDemodCmd=CMD_MOD_USB;
    myDemodCmd=myDemodCmd
            .replace("%FIFO%", fifoPipePath)
            .replace("%AUDIOPLAYER%", audioPlayerCommand)
            .replace("%SAMP_RATE%",ui->comboSampRate->currentText())
            .replace("%DECIM%", QString::number(ui->comboSampRate->currentText().toInt()/48000))
            .replace("%WFM_DECIM%", QString::number(ui->comboSampRate->currentText().toInt()/240000));
    qDebug() << "myDemodCmd ="<<myDemodCmd;
    return myDemodCmd;
}

QString MainWindow::getModulatorCommand()
{
    QString myModCmd;
    if(ui->toggleWFM->isChecked()) myModCmd=CMD_TX_WFM;
    if(ui->toggleNFM->isChecked()) myModCmd=CMD_TX_NFM;
    if(ui->toggleAM->isChecked())  myModCmd=CMD_TX_AM;
    if(ui->toggleCW->isChecked())  myModCmd=CMD_TX_CW;
    if(ui->toggleLSB->isChecked()) myModCmd=CMD_TX_LSB;
    if(ui->toggleUSB->isChecked()) myModCmd=CMD_TX_USB;
    myModCmd=myModCmd
        .replace("%ARECORDCMD%", CMD_ARECORD)
        .replace("%CWCMD%", CMD_CW)
        .replace("%ADEVICE%", (alsaDevice.isEmpty())?"":"-D "+alsaDevice)
        .replace("%TXFREQ_AM%", QString::number((getFQvalue()+10000)/1000,'f',0))
        .replace("%TXFREQ%", QString::number(getFQvalue()/1000,'f',0))
        .replace("%TXFREQ_SSB%", QString::number((getFQvalue()+2000)/1000,'f',0))
        .replace("%TXFREQ_CW%", QString::number((getFQvalue()+600),'f',0));
    qDebug() << "myModCmd ="<<myModCmd;
    return myModCmd;
}


void MainWindow::updateFilterBw()
{
    ui->widgetFFT->offsetFreq = getOFvalue();setShift();
    if(ui->toggleWFM->isChecked()) { ui->widgetFFT->filterLowCut=-70000; ui->widgetFFT->filterHighCut=70000; }
    if(ui->toggleNFM->isChecked()) { ui->widgetFFT->filterLowCut=-4000; ui->widgetFFT->filterHighCut=4000; }
    if(ui->toggleAM->isChecked())  { ui->widgetFFT->filterLowCut=-4000; ui->widgetFFT->filterHighCut=4000; }
    if(ui->toggleLSB->isChecked()) { ui->widgetFFT->filterLowCut=-4000; ui->widgetFFT->filterHighCut=0; }
    if(ui->toggleUSB->isChecked()) { ui->widgetFFT->filterLowCut=0; ui->widgetFFT->filterHighCut=4000; }
    if(ui->toggleCW->isChecked()) { ui->widgetFFT->filterLowCut=0; ui->widgetFFT->filterHighCut=2000; }
}

void MainWindow::on_toggleRun_toggled(bool checked)
{
    if(checked)
    {
        ui->widgetFFT->sampleRate=ui->comboSampRate->currentText().toInt();
        ui->comboSampRate->setEnabled(false);
        fifoPipePath = QString("/tmp/qtcsdr_shift_pipe_")+QString::number(rand());
        mkfifo(fifoPipePath.toStdString().c_str(), 0600);
        fifoPipe=open(fifoPipePath.toStdString().c_str(), O_RDWR);
        setShift();
        QString IQCommand = QString(CMD_IQSERVER).replace("%SAMP_RATE%",ui->comboSampRate->currentText());
        qDebug() << "IQCommand =" << IQCommand;
        procIQServer.start(IQCommand);
        procIQServer.waitForStarted(1000);
        int nmuxBufsize = 0, nmuxBufcnt = 0, sampRate = ui->comboSampRate->currentText().toInt();
        while (nmuxBufsize < sampRate/4) nmuxBufsize += 4096; //taken from OpenWebRX
        while (nmuxBufsize * nmuxBufcnt < NMUX_MEMORY_MBYTE * 1e6) nmuxBufcnt += 1;
        QString distribCommand = QString(CMD_DISTRIB)
                .replace("%NMUX_BUFSIZE%", QString::number(nmuxBufsize))
                .replace("%NMUX_BUFCNT%", QString::number(nmuxBufcnt));
        qDebug() << "distribCommand =" << distribCommand;
        procDistrib.start(distribCommand);
        procDistrib.waitForStarted(1000);
        procDemod.start(getDemodulatorCommand());
        QString FFTCommand = QString(CMD_FFT).replace("%FFT_READ_SIZE%", QString::number(ui->comboSampRate->currentText().toInt()/10));
        qDebug() << "FFTCommand" << FFTCommand;
        procFFT.start(FFTCommand);
        //on_spinFreq_valueChanged(ui->spinFreq->value());
        sendCommand(RTLTCP_SET_FREQ, getVFOvalue()+upconvvalue);
        on_comboDirectSamp_currentIndexChanged(0);
        updateFilterBw();

        sendCommand(RTLTCP_SET_GAIN,ui->RTLGTXT->value()*10);

        if(ui->RTLHAGC->isChecked())
        {
            sendCommand(RTLTCP_SET_TUNER_GAIN_MODE,1);
        }
        if(ui->RTLSAGC->isChecked())
        {
            sendCommand(RTLTCP_SET_AGC_MODE,1);
        }

    }
    else
    {
        ui->comboSampRate->setEnabled(true);
        unlink(fifoPipePath.toStdString().c_str());
        if(procDemod.pid()!=0)    kill(procDemod.pid(), SIGTERM);
        if(procDistrib.pid()!=0)  kill(procDistrib.pid(), SIGTERM);
        if(procIQServer.pid()!=0) kill(procIQServer.pid(), SIGTERM);
        if(procFFT.pid()!=0)      kill(procFFT.pid(), SIGTERM);
        procFFT.readAll();
        FFTDataBuffer.clear();
    }
}

void MainWindow::on_toggleTransmit_toggled(bool checked)
{
    if(checked)
    {
        QString modCmd = getModulatorCommand();
        procTX.start(modCmd);
        procTX.waitForStarted(1000);
    }
    else
    {
        if(procTX.pid()!=0)
        {
            procKillTX.start("bash -c \"gksu touch; sudo killall rpitx\"");
            kill(procTX.pid(), SIGTERM);
        }
    }
}

void MainWindow::setShift()
{
    QString shiftString = QString::number(-((ui->OFM->text()+ui->OFK->text()+ui->OFH->text()).toInt())/(float)ui->comboSampRate->currentText().toInt())+"\n";
    write(fifoPipe,shiftString.toStdString().c_str(),shiftString.length());
    ui->widgetFFT->offsetFreq = ((ui->OFM->text()+ui->OFK->text()+ui->OFH->text()).toInt());
}

void MainWindow::sendCommand(unsigned char cmd_num, unsigned value)
{
    printf("%d\n",value);
    //docs: https://github.com/pinkavaj/rtl-sdr/blob/master/src/rtl_tcp.c#L324
    unsigned char cmd[5];
    cmd[0] = cmd_num; //set_freq
    cmd[1] = (value>>24)&0xff;
    cmd[2] = (value>>16)&0xff;
    cmd[3] = (value>>8)&0xff;
    cmd[4] = value&0xff;
    procDistrib.write((char*)cmd, 5);
}






void MainWindow::on_UPConv_toggled(bool checked)
{
    if(checked)
    {
        upconvvalue = ui->UPConvVal->currentText().toInt() * 1000000;
        ui->UPConvVal->setEnabled(false);
    }
    else
    {
        upconvvalue = 0;
        ui->UPConvVal->setEnabled(true);
    }
}

void MainWindow::on_RTLHAGC_toggled(bool checked)
{
    if(checked)
    {
        sendCommand(RTLTCP_SET_TUNER_GAIN_MODE,1);
    }
    else
    {
        sendCommand(RTLTCP_SET_TUNER_GAIN_MODE,0);
    }
}

void MainWindow::on_RTLSAGC_toggled(bool checked)
{
    if(checked)
    {
        sendCommand(RTLTCP_SET_AGC_MODE,1);
    }
    else
    {
        sendCommand(RTLTCP_SET_AGC_MODE,0);
    }
}

void MainWindow::on_RTLGSlider_valueChanged(int val)
{

    Qt::MouseButtons btns = QApplication::mouseButtons();
    QPoint localMousePos = ui->RTLGSlider->mapFromGlobal(QCursor::pos());
    bool clickOnSlider = (btns & Qt::LeftButton) &&
                         (localMousePos.x() >= 0 && localMousePos.y() >= 0 &&
                          localMousePos.x() < ui->RTLGSlider->size().width() &&
                          localMousePos.y() < ui->RTLGSlider->size().height());
    if (clickOnSlider)
    {
        // Attention! The following works only for Horizontal, Left-to-right sliders
        float posRatio = localMousePos.x() / (float )ui->RTLGSlider->size().width();
        int sliderRange = ui->RTLGSlider->maximum() - ui->RTLGSlider->minimum();
        int sliderPosUnderMouse = ui->RTLGSlider->minimum() + sliderRange * posRatio;

            ui->RTLGSlider->setValue(sliderPosUnderMouse);

    }

    ui->RTLGTXT->setValue(ui->RTLGSlider->value());
    sendCommand(RTLTCP_SET_GAIN,ui->RTLGTXT->value()*10);

}

void MainWindow::on_comboDirectSamp_currentIndexChanged(int index)
{
    sendCommand(RTLTCP_SET_DIRECT_SAMPLING,ui->comboDirectSamp->currentIndex());
}
