//
// Created by MSI on 2024/3/26.
//

#include "MaskPage.h"
#include <iostream>

MaskPage::MaskPage(){

    uiMask.setupUi(this);

    setWindowIcon(QIcon("../Icon/arrow_right.png"));
}

MaskPage::~MaskPage(){

}

void MaskPage::on_btn_readImg_clicked(){

    std::cout<<"btn_readImg_clicked\n";


}