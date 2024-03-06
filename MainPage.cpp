//
// Created by YF on 2024/3/5.
//

#include "MainPage.h"
#include <iostream>
MainPage::MainPage(QWidget *parent): QMainWindow(parent) {
    ui.setupUi(this);
}

MainPage::~MainPage() {
    std::cout<<"deconstruct\n";
}