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
    QPushButton *btn_globalMosicalAlgo1;
    QLabel *label_maskImg;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MaskWindow)
    {
        if (MaskWindow->objectName().isEmpty())
            MaskWindow->setObjectName("MaskWindow");
        MaskWindow->resize(826, 599);
        centralwidget = new QWidget(MaskWindow);
        centralwidget->setObjectName("centralwidget");
        btn_readImg = new QPushButton(centralwidget);
        btn_readImg->setObjectName("btn_readImg");
        btn_readImg->setGeometry(QRect(20, 30, 121, 41));
        btn_globalMosicalAlgo1 = new QPushButton(centralwidget);
        btn_globalMosicalAlgo1->setObjectName("btn_globalMosicalAlgo1");
        btn_globalMosicalAlgo1->setGeometry(QRect(20, 110, 121, 41));
        label_maskImg = new QLabel(centralwidget);
        label_maskImg->setObjectName("label_maskImg");
        label_maskImg->setGeometry(QRect(170, 30, 640, 512));
        MaskWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MaskWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 826, 21));
        MaskWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MaskWindow);
        statusbar->setObjectName("statusbar");
        MaskWindow->setStatusBar(statusbar);

        retranslateUi(MaskWindow);

        QMetaObject::connectSlotsByName(MaskWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MaskWindow)
    {
        MaskWindow->setWindowTitle(QCoreApplication::translate("MaskWindow", "MainWindow", nullptr));
        btn_readImg->setText(QCoreApplication::translate("MaskWindow", "\346\211\223\345\274\200\345\233\276\345\203\217", nullptr));
        btn_globalMosicalAlgo1->setText(QCoreApplication::translate("MaskWindow", "\345\205\250\345\233\276\351\251\254\350\265\233\345\205\213-\347\256\227\346\263\2251", nullptr));
        label_maskImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MaskWindow: public Ui_MaskWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASK_H
