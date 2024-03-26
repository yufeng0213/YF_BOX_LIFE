//
// Created by YF on 2024/3/5.
//

#include "MainPage.h"
#include <iostream>

#include "MaskPage.h"

MainPage::MainPage(QWidget *parent): QMainWindow(parent) {
    ui.setupUi(this);

    setWindowIcon(QIcon("../Icon/Farmer-female.png"));
    beautifyCalendarWidget();

    connect(ui.actionmask, &QAction::triggered, this, &MainPage::on_actionmask_triggered);


}

MainPage::~MainPage() {
    std::cout<<"deconstruct\n";
}

void MainPage::beautifyCalendarWidget(){
    QString styleSheet = "QCalendarWidget {"
                         "  background-color: white;"
                         "  font-size: 11px;"
                         "  selection-background-color: red;"
                         "}"
                         "QCalendarWidget QAbstractItemView {"
                         "  alternate-background-color: #123456;"
                         "}"
                         "QCalendarWidget QAbstractItemView::item:today {"
                         "  background-color: #abcdef;"
                         "  border: 1px double white;"
                         "}"
                         "QCalendarWidget QAbstractItemView::item[Qt::UserRole+1=\"special\"]{"
                         "  background-color: lightgreen;"
                         "}"
                         "QCalendarWidget QToolButton{"
                         "  background-color: transparent;"
                         "  border: none;"
                         "  padding: 0;"
                         "  qproperty-icon: url(../Icon/arrow_left.png);"
                         "  qproperty-iconSize: 16px 16px;"
                         "}"
                         "QCalendarWidget QToolButton::right-arrow{"
                         "  qproperty-icon: url(../Icon/arrow_right.png);"
                         "}";

    ui.calendarWidget->setStyleSheet(styleSheet);
}

void MainPage::on_actionmask_triggered(){
    MaskPage *maskPage = new MaskPage();
    maskPage->show();
}