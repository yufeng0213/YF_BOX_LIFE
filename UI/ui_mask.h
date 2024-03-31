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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MaskWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_readImg;
    QFrame *line;
    QPushButton *btn_globalMosicalAlgo1;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_gloMoAlgoTh;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *cBox_gloMoAlgo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSlider *hSlider_gloMoAlgoTh;
    QSpacerItem *verticalSpacer;
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
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 10, 791, 541));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        btn_readImg = new QPushButton(horizontalLayoutWidget);
        btn_readImg->setObjectName("btn_readImg");

        verticalLayout->addWidget(btn_readImg);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        btn_globalMosicalAlgo1 = new QPushButton(horizontalLayoutWidget);
        btn_globalMosicalAlgo1->setObjectName("btn_globalMosicalAlgo1");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_globalMosicalAlgo1->sizePolicy().hasHeightForWidth());
        btn_globalMosicalAlgo1->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(btn_globalMosicalAlgo1);

        line_2 = new QFrame(horizontalLayoutWidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEdit_gloMoAlgoTh = new QLineEdit(horizontalLayoutWidget);
        lineEdit_gloMoAlgoTh->setObjectName("lineEdit_gloMoAlgoTh");

        horizontalLayout->addWidget(lineEdit_gloMoAlgoTh);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        cBox_gloMoAlgo = new QComboBox(horizontalLayoutWidget);
        cBox_gloMoAlgo->setObjectName("cBox_gloMoAlgo");

        horizontalLayout_4->addWidget(cBox_gloMoAlgo);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        hSlider_gloMoAlgoTh = new QSlider(horizontalLayoutWidget);
        hSlider_gloMoAlgoTh->setObjectName("hSlider_gloMoAlgoTh");
        hSlider_gloMoAlgoTh->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(hSlider_gloMoAlgoTh);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);

        label_maskImg = new QLabel(horizontalLayoutWidget);
        label_maskImg->setObjectName("label_maskImg");
        label_maskImg->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_maskImg->sizePolicy().hasHeightForWidth());
        label_maskImg->setSizePolicy(sizePolicy2);
        label_maskImg->setMinimumSize(QSize(640, 512));
        label_maskImg->setMaximumSize(QSize(640, 512));
        label_maskImg->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(label_maskImg);

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
        label->setText(QCoreApplication::translate("MaskWindow", "\351\230\210\345\200\274\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MaskWindow", "\345\205\250\345\261\200\347\256\227\346\263\225\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MaskWindow", "\351\230\210\345\200\274\357\274\232", nullptr));
        label_maskImg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MaskWindow: public Ui_MaskWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASK_H
