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
    QSlider *spinSlider;
    QWidget *widget;
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
        label->setGeometry(QRect(220, 140, 51, 31));
        toggleAM = new QPushButton(tabWidgetControlsPage1);
        toggleAM->setObjectName(QStringLiteral("toggleAM"));
        toggleAM->setGeometry(QRect(10, 100, 61, 31));
        toggleAM->setCheckable(true);
        label_2 = new QLabel(tabWidgetControlsPage1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 140, 61, 31));
        spinFreq = new QSpinBox(tabWidgetControlsPage1);
        spinFreq->setObjectName(QStringLiteral("spinFreq"));
        spinFreq->setGeometry(QRect(270, 140, 151, 31));
        spinFreq->setMaximum(1999999999);
        spinFreq->setSingleStep(1000);
        spinFreq->setValue(125200000);
        spinOffset = new QSpinBox(tabWidgetControlsPage1);
        spinOffset->setObjectName(QStringLiteral("spinOffset"));
        spinOffset->setGeometry(QRect(500, 140, 111, 31));
        spinOffset->setMinimum(-1200000);
        spinOffset->setMaximum(1200000);
        spinOffset->setSingleStep(100);
        spinOffset->setValue(200000);
        toggleWFM = new QPushButton(tabWidgetControlsPage1);
        toggleWFM->setObjectName(QStringLiteral("toggleWFM"));
        toggleWFM->setGeometry(QRect(10, 40, 61, 31));
        toggleWFM->setCheckable(true);
        toggleWFM->setChecked(true);
        toggleUSB = new QPushButton(tabWidgetControlsPage1);
        toggleUSB->setObjectName(QStringLiteral("toggleUSB"));
        toggleUSB->setGeometry(QRect(10, 70, 61, 31));
        toggleUSB->setCheckable(true);
        toggleLSB = new QPushButton(tabWidgetControlsPage1);
        toggleLSB->setObjectName(QStringLiteral("toggleLSB"));
        toggleLSB->setGeometry(QRect(70, 70, 61, 31));
        toggleLSB->setCheckable(true);
        toggleNFM = new QPushButton(tabWidgetControlsPage1);
        toggleNFM->setObjectName(QStringLiteral("toggleNFM"));
        toggleNFM->setGeometry(QRect(70, 40, 61, 31));
        toggleNFM->setCheckable(true);
        spinCenter = new QSpinBox(tabWidgetControlsPage1);
        spinCenter->setObjectName(QStringLiteral("spinCenter"));
        spinCenter->setGeometry(QRect(60, 140, 151, 31));
        spinCenter->setMaximum(1999999999);
        spinCenter->setSingleStep(1000);
        spinCenter->setValue(125000000);
        label_3 = new QLabel(tabWidgetControlsPage1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 140, 51, 31));
        toggleCW = new QPushButton(tabWidgetControlsPage1);
        toggleCW->setObjectName(QStringLiteral("toggleCW"));
        toggleCW->setGeometry(QRect(70, 100, 61, 31));
        toggleCW->setCheckable(true);
        toggleTransmit = new QPushButton(tabWidgetControlsPage1);
        toggleTransmit->setObjectName(QStringLiteral("toggleTransmit"));
        toggleTransmit->setEnabled(false);
        toggleTransmit->setGeometry(QRect(480, 50, 111, 41));
        toggleTransmit->setCheckable(true);
        toggleRun = new QPushButton(tabWidgetControlsPage1);
        toggleRun->setObjectName(QStringLiteral("toggleRun"));
        toggleRun->setGeometry(QRect(360, 50, 111, 41));
        toggleRun->setCheckable(true);
        spinSlider = new QSlider(tabWidgetControlsPage1);
        spinSlider->setObjectName(QStringLiteral("spinSlider"));
        spinSlider->setGeometry(QRect(20, 10, 581, 16));
        spinSlider->setMinimum(1000);
        spinSlider->setMaximum(1500000000);
        spinSlider->setSingleStep(500);
        spinSlider->setPageStep(10000);
        spinSlider->setValue(125000000);
        spinSlider->setOrientation(Qt::Horizontal);
        tabWidgetControls->addTab(tabWidgetControlsPage1, QString());
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 10, 121, 31));
        comboSampRate = new QComboBox(widget);
        comboSampRate->setObjectName(QStringLiteral("comboSampRate"));
        comboSampRate->setGeometry(QRect(130, 10, 171, 31));
        comboDirectSamp = new QComboBox(widget);
        comboDirectSamp->setObjectName(QStringLiteral("comboDirectSamp"));
        comboDirectSamp->setGeometry(QRect(10, 50, 291, 31));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 130, 61, 31));
        RTLSAGC = new QCheckBox(widget);
        RTLSAGC->setObjectName(QStringLiteral("RTLSAGC"));
        RTLSAGC->setGeometry(QRect(10, 90, 111, 31));
        RTLHAGC = new QCheckBox(widget);
        RTLHAGC->setObjectName(QStringLiteral("RTLHAGC"));
        RTLHAGC->setGeometry(QRect(130, 90, 111, 31));
        RTLGSlider = new QSlider(widget);
        RTLGSlider->setObjectName(QStringLiteral("RTLGSlider"));
        RTLGSlider->setGeometry(QRect(110, 130, 471, 21));
        RTLGSlider->setMouseTracking(true);
        RTLGSlider->setMinimum(0);
        RTLGSlider->setMaximum(40);
        RTLGSlider->setSingleStep(1);
        RTLGSlider->setPageStep(1);
        RTLGSlider->setValue(10);
        RTLGSlider->setOrientation(Qt::Horizontal);
        RTLGTXT = new QSpinBox(widget);
        RTLGTXT->setObjectName(QStringLiteral("RTLGTXT"));
        RTLGTXT->setGeometry(QRect(70, 130, 31, 31));
        RTLGTXT->setWrapping(false);
        RTLGTXT->setFrame(true);
        RTLGTXT->setButtonSymbols(QAbstractSpinBox::NoButtons);
        RTLGTXT->setMaximum(40);
        RTLGTXT->setSingleStep(1);
        RTLGTXT->setValue(10);
        UPConv = new QCheckBox(widget);
        UPConv->setObjectName(QStringLiteral("UPConv"));
        UPConv->setGeometry(QRect(320, 10, 141, 31));
        UPConvVal = new QComboBox(widget);
        UPConvVal->setObjectName(QStringLiteral("UPConvVal"));
        UPConvVal->setGeometry(QRect(470, 10, 71, 31));
        tabWidgetControls->addTab(widget, QString());

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
        toggleTransmit->setText(QApplication::translate("MainWindow", "Transmit", Q_NULLPTR));
        toggleRun->setText(QApplication::translate("MainWindow", "Receive", Q_NULLPTR));
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
        tabWidgetControls->setTabText(tabWidgetControls->indexOf(widget), QApplication::translate("MainWindow", "RTL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
