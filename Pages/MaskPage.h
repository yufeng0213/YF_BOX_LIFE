//
// Created by MSI on 2024/3/26.
//

#ifndef UNTITLED1_MASKPAGE_H
#define UNTITLED1_MASKPAGE_H

#include "../UI/ui_mask.h"

class MaskPage: public QMainWindow{

Q_OBJECT
public:
    MaskPage();

    ~MaskPage();

private:
    Ui_MaskWindow uiMask;


private slots:
    // 读取图片
    void on_btn_readImg_clicked();
};


#endif //UNTITLED1_MASKPAGE_H
