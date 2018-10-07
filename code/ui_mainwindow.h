/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *ButtonStart;
    QPushButton *ButtonStop;
    QPushButton *ButtonReset;
    QSlider *mySlider;
    QLineEdit *SliderValue;
    QLabel *signal1;
    QLabel *signal2;
    QLabel *signal3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ButtonStart = new QPushButton(centralWidget);
        ButtonStart->setObjectName(QStringLiteral("ButtonStart"));
        ButtonStart->setGeometry(QRect(40, 180, 99, 27));
        ButtonStop = new QPushButton(centralWidget);
        ButtonStop->setObjectName(QStringLiteral("ButtonStop"));
        ButtonStop->setGeometry(QRect(150, 180, 99, 27));
        ButtonReset = new QPushButton(centralWidget);
        ButtonReset->setObjectName(QStringLiteral("ButtonReset"));
        ButtonReset->setGeometry(QRect(260, 180, 99, 27));
        mySlider = new QSlider(centralWidget);
        mySlider->setObjectName(QStringLiteral("mySlider"));
        mySlider->setGeometry(QRect(60, 70, 160, 29));
        mySlider->setOrientation(Qt::Horizontal);
        SliderValue = new QLineEdit(centralWidget);
        SliderValue->setObjectName(QStringLiteral("SliderValue"));
        SliderValue->setGeometry(QRect(240, 70, 113, 27));
        signal1 = new QLabel(centralWidget);
        signal1->setObjectName(QStringLiteral("signal1"));
        signal1->setGeometry(QRect(60, 30, 31, 17));
        signal2 = new QLabel(centralWidget);
        signal2->setObjectName(QStringLiteral("signal2"));
        signal2->setGeometry(QRect(140, 30, 67, 17));
        signal3 = new QLabel(centralWidget);
        signal3->setObjectName(QStringLiteral("signal3"));
        signal3->setGeometry(QRect(210, 30, 67, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        ButtonStart->setText(QApplication::translate("MainWindow", "Start", 0));
        ButtonStop->setText(QApplication::translate("MainWindow", "Stop", 0));
        ButtonReset->setText(QApplication::translate("MainWindow", "Reset", 0));
        SliderValue->setText(QApplication::translate("MainWindow", "0", 0));
        signal1->setText(QApplication::translate("MainWindow", "0", 0));
        signal2->setText(QApplication::translate("MainWindow", "0", 0));
        signal3->setText(QApplication::translate("MainWindow", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
