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
    // 新增：用于加载和显示图片的辅助函数
    bool loadAndDisplayImage(const QString &filePath);

private:
    Ui_MaskWindow uiMask;

    std::string _mosicalImgPath;

private slots:
    // 读取图片
    void on_btn_readImg_clicked();
    // 全局马赛克算法1
    void on_btn_globalMosicalAlgo1_clicked();
    // 全局阈值拉杆
    void on_hSlider_gloMoAlgoTh_valueChanged(const int value);
};


#endif //UNTITLED1_MASKPAGE_H
