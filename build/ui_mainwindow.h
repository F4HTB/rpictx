/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qmyspectrumwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QMySpectrumWidget *widgetFFT;
    QTabWidget *tabWidgetControls;
    QWidget *tabWidgetControlsPage1;
    QLabel *label;
    QPushButton *toggleAM;
    QLabel *label_2;
    QSpinBox *spinFreq;
    QSpinBox *spinOffset;
    QPushButton *toggleWFM;
    QPushButton *toggleUSB;
    QPushButton *toggleLSB;
    QPushButton *toggleNFM;
    QSpinBox *spinCenter;
    QLabel *label_3;
    QPushButton *toggleCW;
    QPushButton *toggleTransmit;
    QPushButton *toggleRun;
    QPushButton *FP10;
    QPushButton *FP1;
    QPushButton *FP100;
    QPushButton *FM100;
    QPushButton *FM10;
    QPushButton *FM1;
    QPushButton *VFOG;
    QPushButton *VFOM;
    QPushButton *VFOK;
    QPushButton *VFOH;
    QPushButton *FQM;
    QPushButton *FQK;
    QPushButton *FQG;
    QPushButton *FQH;
    QPushButton *OFK;
    QPushButton *OFH;
    QPushButton *OFM;
    QWidget *tabRTL;
    QLabel *label_4;
    QComboBox *comboSampRate;
    QComboBox *comboDirectSamp;
    QLabel *label_6;
    QCheckBox *RTLSAGC;
    QCheckBox *RTLHAGC;
    QSlider *RTLGSlider;
    QSpinBox *RTLGTXT;
    QCheckBox *UPConv;
    QComboBox *UPConvVal;
    QWidget *tabCW;
    QSpinBox *CWwpmtxt;
    QLabel *label_5;
    QLabel *label_7;
    QSpinBox *CWrttxt;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(640, 480));
        MainWindow->setMaximumSize(QSize(640, 480));
        QFont font;
        font.setPointSize(9);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        widgetFFT = new QMySpectrumWidget(centralWidget);
        widgetFFT->setObjectName(QStringLiteral("widgetFFT"));
        widgetFFT->setEnabled(true);
        tabWidgetControls = new QTabWidget(widgetFFT);
        tabWidgetControls->setObjectName(QStringLiteral("tabWidgetControls"));
        tabWidgetControls->setGeometry(QRect(0, 243, 622, 220));
        QFont font1;
        font1.setPointSize(14);
        tabWidgetControls->setFont(font1);
        tabWidgetControlsPage1 = new QWidget();
        tabWidgetControlsPage1->setObjectName(QStringLiteral("tabWidgetControlsPage1"));
        label = new QLabel(tabWidgetControlsPage1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 110, 51, 31));
        toggleAM = new QPushButton(tabWidgetControlsPage1);
        toggleAM->setObjectName(QStringLiteral("toggleAM"));
        toggleAM->setGeometry(QRect(250, 10, 61, 31));
        toggleAM->setCheckable(true);
        label_2 = new QLabel(tabWidgetControlsPage1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 140, 61, 31));
        spinFreq = new QSpinBox(tabWidgetControlsPage1);
        spinFreq->setObjectName(QStringLiteral("spinFreq"));
        spinFreq->setGeometry(QRect(460, 50, 151, 31));
        spinFreq->setMaximum(1999999999);
        spinFreq->setSingleStep(1000);
        spinFreq->setValue(125200000);
        spinOffset = new QSpinBox(tabWidgetControlsPage1);
        spinOffset->setObjectName(QStringLiteral("spinOffset"));
        spinOffset->setGeometry(QRect(500, 100, 111, 31));
        spinOffset->setMinimum(-1200000);
        spinOffset->setMaximum(1200000);
        spinOffset->setSingleStep(100);
        spinOffset->setValue(200000);
        toggleWFM = new QPushButton(tabWidgetControlsPage1);
        toggleWFM->setObjectName(QStringLiteral("toggleWFM"));
        toggleWFM->setGeometry(QRect(10, 10, 61, 31));
        toggleWFM->setCheckable(true);
        toggleWFM->setChecked(true);
        toggleUSB = new QPushButton(tabWidgetControlsPage1);
        toggleUSB->setObjectName(QStringLiteral("toggleUSB"));
        toggleUSB->setGeometry(QRect(130, 10, 61, 31));
        toggleUSB->setCheckable(true);
        toggleLSB = new QPushButton(tabWidgetControlsPage1);
        toggleLSB->setObjectName(QStringLiteral("toggleLSB"));
        toggleLSB->setGeometry(QRect(190, 10, 61, 31));
        toggleLSB->setCheckable(true);
        toggleNFM = new QPushButton(tabWidgetControlsPage1);
        toggleNFM->setObjectName(QStringLiteral("toggleNFM"));
        toggleNFM->setGeometry(QRect(70, 10, 61, 31));
        toggleNFM->setCheckable(true);
        spinCenter = new QSpinBox(tabWidgetControlsPage1);
        spinCenter->setObjectName(QStringLiteral("spinCenter"));
        spinCenter->setGeometry(QRect(10, 50, 151, 31));
        spinCenter->setMaximum(1999999999);
        spinCenter->setSingleStep(1000);
        spinCenter->setValue(125000000);
        label_3 = new QLabel(tabWidgetControlsPage1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 51, 31));
        toggleCW = new QPushButton(tabWidgetControlsPage1);
        toggleCW->setObjectName(QStringLiteral("toggleCW"));
        toggleCW->setGeometry(QRect(310, 10, 61, 31));
        toggleCW->setCheckable(true);
        toggleTransmit = new QPushButton(tabWidgetControlsPage1);
        toggleTransmit->setObjectName(QStringLiteral("toggleTransmit"));
        toggleTransmit->setEnabled(false);
        toggleTransmit->setGeometry(QRect(500, 10, 111, 31));
        toggleTransmit->setCheckable(true);
        toggleRun = new QPushButton(tabWidgetControlsPage1);
        toggleRun->setObjectName(QStringLiteral("toggleRun"));
        toggleRun->setGeometry(QRect(380, 10, 111, 31));
        toggleRun->setCheckable(true);
        FP10 = new QPushButton(tabWidgetControlsPage1);
        FP10->setObjectName(QStringLiteral("FP10"));
        FP10->setGeometry(QRect(310, 80, 61, 41));
        QFont font2;
        font2.setPointSize(12);
        FP10->setFont(font2);
        FP1 = new QPushButton(tabWidgetControlsPage1);
        FP1->setObjectName(QStringLiteral("FP1"));
        FP1->setGeometry(QRect(370, 80, 61, 41));
        FP1->setFont(font2);
        FP100 = new QPushButton(tabWidgetControlsPage1);
        FP100->setObjectName(QStringLiteral("FP100"));
        FP100->setGeometry(QRect(250, 80, 61, 41));
        FP100->setFont(font2);
        FM100 = new QPushButton(tabWidgetControlsPage1);
        FM100->setObjectName(QStringLiteral("FM100"));
        FM100->setGeometry(QRect(250, 130, 61, 41));
        FM100->setFont(font2);
        FM10 = new QPushButton(tabWidgetControlsPage1);
        FM10->setObjectName(QStringLiteral("FM10"));
        FM10->setGeometry(QRect(310, 130, 61, 41));
        FM10->setFont(font2);
        FM1 = new QPushButton(tabWidgetControlsPage1);
        FM1->setObjectName(QStringLiteral("FM1"));
        FM1->setGeometry(QRect(370, 130, 61, 41));
        FM1->setFont(font2);
        VFOG = new QPushButton(tabWidgetControlsPage1);
        VFOG->setObjectName(QStringLiteral("VFOG"));
        VFOG->setGeometry(QRect(60, 80, 41, 31));
        QFont font3;
        font3.setPointSize(12);
        font3.setUnderline(true);
        VFOG->setFont(font3);
        VFOG->setText(QStringLiteral("000"));
        VFOG->setFlat(true);
        VFOM = new QPushButton(tabWidgetControlsPage1);
        VFOM->setObjectName(QStringLiteral("VFOM"));
        VFOM->setGeometry(QRect(100, 80, 41, 31));
        VFOM->setFont(font3);
        VFOM->setText(QStringLiteral("028"));
        VFOM->setFlat(true);
        VFOK = new QPushButton(tabWidgetControlsPage1);
        VFOK->setObjectName(QStringLiteral("VFOK"));
        VFOK->setGeometry(QRect(140, 80, 41, 31));
        VFOK->setFont(font3);
        VFOK->setText(QStringLiteral("000"));
        VFOK->setFlat(true);
        VFOH = new QPushButton(tabWidgetControlsPage1);
        VFOH->setObjectName(QStringLiteral("VFOH"));
        VFOH->setGeometry(QRect(180, 80, 41, 31));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setUnderline(true);
        font4.setWeight(75);
        VFOH->setFont(font4);
        VFOH->setText(QStringLiteral("000"));
        VFOH->setFlat(true);
        FQM = new QPushButton(tabWidgetControlsPage1);
        FQM->setObjectName(QStringLiteral("FQM"));
        FQM->setGeometry(QRect(100, 110, 41, 31));
        FQM->setFont(font3);
        FQM->setText(QStringLiteral("028"));
        FQM->setFlat(true);
        FQK = new QPushButton(tabWidgetControlsPage1);
        FQK->setObjectName(QStringLiteral("FQK"));
        FQK->setGeometry(QRect(140, 110, 41, 31));
        FQK->setFont(font3);
        FQK->setText(QStringLiteral("200"));
        FQK->setFlat(true);
        FQG = new QPushButton(tabWidgetControlsPage1);
        FQG->setObjectName(QStringLiteral("FQG"));
        FQG->setGeometry(QRect(60, 110, 41, 31));
        FQG->setFont(font3);
        FQG->setText(QStringLiteral("000"));
        FQG->setFlat(true);
        FQH = new QPushButton(tabWidgetControlsPage1);
        FQH->setObjectName(QStringLiteral("FQH"));
        FQH->setGeometry(QRect(180, 110, 41, 31));
        FQH->setFont(font3);
        FQH->setText(QStringLiteral("000"));
        FQH->setFlat(true);
        OFK = new QPushButton(tabWidgetControlsPage1);
        OFK->setObjectName(QStringLiteral("OFK"));
        OFK->setGeometry(QRect(140, 140, 41, 31));
        OFK->setFont(font3);
        OFK->setText(QStringLiteral("200"));
        OFK->setFlat(true);
        OFH = new QPushButton(tabWidgetControlsPage1);
        OFH->setObjectName(QStringLiteral("OFH"));
        OFH->setGeometry(QRect(180, 140, 41, 31));
        OFH->setFont(font3);
        OFH->setText(QStringLiteral("000"));
        OFH->setFlat(true);
        OFM = new QPushButton(tabWidgetControlsPage1);
        OFM->setObjectName(QStringLiteral("OFM"));
        OFM->setGeometry(QRect(100, 140, 41, 31));
        OFM->setFont(font3);
        OFM->setText(QStringLiteral(""));
        OFM->setFlat(true);
        tabWidgetControls->addTab(tabWidgetControlsPage1, QString());
        tabRTL = new QWidget();
        tabRTL->setObjectName(QStringLiteral("tabRTL"));
        label_4 = new QLabel(tabRTL);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 121, 31));
        comboSampRate = new QComboBox(tabRTL);
        comboSampRate->setObjectName(QStringLiteral("comboSampRate"));
        comboSampRate->setGeometry(QRect(130, 10, 171, 31));
        comboDirectSamp = new QComboBox(tabRTL);
        comboDirectSamp->setObjectName(QStringLiteral("comboDirectSamp"));
        comboDirectSamp->setGeometry(QRect(10, 50, 291, 31));
        label_6 = new QLabel(tabRTL);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 130, 61, 31));
        RTLSAGC = new QCheckBox(tabRTL);
        RTLSAGC->setObjectName(QStringLiteral("RTLSAGC"));
        RTLSAGC->setGeometry(QRect(10, 90, 111, 31));
        RTLHAGC = new QCheckBox(tabRTL);
        RTLHAGC->setObjectName(QStringLiteral("RTLHAGC"));
        RTLHAGC->setGeometry(QRect(130, 90, 111, 31));
        RTLGSlider = new QSlider(tabRTL);
        RTLGSlider->setObjectName(QStringLiteral("RTLGSlider"));
        RTLGSlider->setGeometry(QRect(110, 130, 471, 21));
        RTLGSlider->setMouseTracking(true);
        RTLGSlider->setMinimum(0);
        RTLGSlider->setMaximum(40);
        RTLGSlider->setSingleStep(1);
        RTLGSlider->setPageStep(1);
        RTLGSlider->setValue(10);
        RTLGSlider->setOrientation(Qt::Horizontal);
        RTLGTXT = new QSpinBox(tabRTL);
        RTLGTXT->setObjectName(QStringLiteral("RTLGTXT"));
        RTLGTXT->setGeometry(QRect(70, 130, 31, 31));
        RTLGTXT->setWrapping(false);
        RTLGTXT->setFrame(true);
        RTLGTXT->setButtonSymbols(QAbstractSpinBox::NoButtons);
        RTLGTXT->setMaximum(40);
        RTLGTXT->setSingleStep(1);
        RTLGTXT->setValue(10);
        UPConv = new QCheckBox(tabRTL);
        UPConv->setObjectName(QStringLiteral("UPConv"));
        UPConv->setGeometry(QRect(320, 10, 141, 31));
        UPConvVal = new QComboBox(tabRTL);
        UPConvVal->setObjectName(QStringLiteral("UPConvVal"));
        UPConvVal->setGeometry(QRect(470, 10, 71, 31));
        tabWidgetControls->addTab(tabRTL, QString());
        tabCW = new QWidget();
        tabCW->setObjectName(QStringLiteral("tabCW"));
        CWwpmtxt = new QSpinBox(tabCW);
        CWwpmtxt->setObjectName(QStringLiteral("CWwpmtxt"));
        CWwpmtxt->setGeometry(QRect(70, 10, 31, 31));
        CWwpmtxt->setFrame(true);
        CWwpmtxt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        CWwpmtxt->setKeyboardTracking(true);
        CWwpmtxt->setMinimum(1);
        CWwpmtxt->setMaximum(50);
        CWwpmtxt->setSingleStep(1);
        CWwpmtxt->setValue(20);
        label_5 = new QLabel(tabCW);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 61, 31));
        label_7 = new QLabel(tabCW);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 50, 181, 31));
        CWrttxt = new QSpinBox(tabCW);
        CWrttxt->setObjectName(QStringLiteral("CWrttxt"));
        CWrttxt->setGeometry(QRect(190, 50, 41, 31));
        CWrttxt->setFrame(true);
        CWrttxt->setButtonSymbols(QAbstractSpinBox::NoButtons);
        CWrttxt->setKeyboardTracking(true);
        CWrttxt->setMinimum(1);
        CWrttxt->setMaximum(50);
        CWrttxt->setSingleStep(1);
        CWrttxt->setValue(20);
        tabWidgetControls->addTab(tabCW, QString());

        verticalLayout->addWidget(widgetFFT);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidgetControls->setCurrentIndex(0);
        comboSampRate->setCurrentIndex(0);
        UPConvVal->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "qtcsdr", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Freq:", Q_NULLPTR));
        toggleAM->setText(QApplication::translate("MainWindow", "AM", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Offset:", Q_NULLPTR));
        toggleWFM->setText(QApplication::translate("MainWindow", "WFM", Q_NULLPTR));
        toggleUSB->setText(QApplication::translate("MainWindow", "USB", Q_NULLPTR));
        toggleLSB->setText(QApplication::translate("MainWindow", "LSB", Q_NULLPTR));
        toggleNFM->setText(QApplication::translate("MainWindow", "NFM", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "VFO:", Q_NULLPTR));
        toggleCW->setText(QApplication::translate("MainWindow", "CW", Q_NULLPTR));
        toggleTransmit->setText(QApplication::translate("MainWindow", "TX", Q_NULLPTR));
        toggleRun->setText(QApplication::translate("MainWindow", "RX", Q_NULLPTR));
        FP10->setText(QApplication::translate("MainWindow", "+10", Q_NULLPTR));
        FP1->setText(QApplication::translate("MainWindow", "+1", Q_NULLPTR));
        FP100->setText(QApplication::translate("MainWindow", "+100", Q_NULLPTR));
        FM100->setText(QApplication::translate("MainWindow", "-100", Q_NULLPTR));
        FM10->setText(QApplication::translate("MainWindow", "-10", Q_NULLPTR));
        FM1->setText(QApplication::translate("MainWindow", "-1", Q_NULLPTR));
        tabWidgetControls->setTabText(tabWidgetControls->indexOf(tabWidgetControlsPage1), QApplication::translate("MainWindow", "Main", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Samp. rate:", Q_NULLPTR));
        comboSampRate->clear();
        comboSampRate->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "2400000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2048000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1200000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "1024000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "960000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "480000", Q_NULLPTR)
         << QApplication::translate("MainWindow", "240000", Q_NULLPTR)
        );
        comboDirectSamp->clear();
        comboDirectSamp->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Quadrature sampling", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Direct sampling (I branch)", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Direct sampling (Q branch)", Q_NULLPTR)
        );
        label_6->setText(QApplication::translate("MainWindow", "GAIN:", Q_NULLPTR));
        RTLSAGC->setText(QApplication::translate("MainWindow", "Soft AGC", Q_NULLPTR));
        RTLHAGC->setText(QApplication::translate("MainWindow", "RTL AGC", Q_NULLPTR));
        UPConv->setText(QApplication::translate("MainWindow", "UpConverter", Q_NULLPTR));
        UPConvVal->clear();
        UPConvVal->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "50", Q_NULLPTR)
         << QApplication::translate("MainWindow", "125", Q_NULLPTR)
         << QApplication::translate("MainWindow", "127", Q_NULLPTR)
        );
        tabWidgetControls->setTabText(tabWidgetControls->indexOf(tabRTL), QApplication::translate("MainWindow", "RTL", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "WPM:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Release time (ms):", Q_NULLPTR));
        tabWidgetControls->setTabText(tabWidgetControls->indexOf(tabCW), QApplication::translate("MainWindow", "CW", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
