/********************************************************************************
** Form generated from reading UI file 'mask.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASK_H
#define UI_MASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaskWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_readImg;
    QPushButton *btn_globalMask;
    QLabel *label_maskImg;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btn_readImg = new QPushButton(centralwidget);
        btn_readImg->setObjectName("btn_readImg");
        btn_readImg->setGeometry(QRect(20, 30, 121, 41));
        btn_globalMask = new QPushButton(centralwidget);
        btn_globalMask->setObjectName("btn_globalMask");
        btn_globalMask->setGeometry(QRect(20, 110, 121, 41));
        label_maskImg = new QLabel(centralwidget);
        label_maskImg->setObjectName("label_maskImg");
        label_maskImg->setGeometry(QRect(160, 10, 621, 531));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_readImg->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\345\203\217", nullptr));
        btn_globalMask->setText(QCoreApplication::translate("MainWindow", "\345\205\250\345\233\276\351\251\254\350\265\233\345\205\213", nullptr));
        label_maskImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MaskWindow: public Ui_MaskWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASK_H
