//
// Created by MSI on 2024/3/26.
//

#include "MaskPage.h"
#include <iostream>

#include <QFileDialog>
#include <QFile>
#include <opencv2/opencv.hpp>

#include <QMessageBox>

#include <qdebug.h>

#include <QMouseEvent>

MaskPage::MaskPage(){

    uiMask.setupUi(this);

    setWindowIcon(QIcon("../Icon/arrow_right.png"));

    uiMask.label_maskImg->setStyleSheet("QLabel{border:1px solid black;}");
    //uiMask.label_bgLine->setStyleSheet("QLabel{border:1px solid black;}");

    connect(uiMask.hSlider_gloMoAlgoTh, SIGNAL(valueChanged(int)),
            this, SLOT(on_hSlider_gloMoAlgoTh_valueChanged(int)));

    uiMask.cBox_gloMoAlgo->addItem("全局算法1");
    uiMask.cBox_gloMoAlgo->addItem("全局算法1");



}

MaskPage::~MaskPage(){

}

void MaskPage::on_btn_readImg_clicked(){
    std::cout << "btn_readImg_clicked\n";

    // 创建并显示一个文件对话框
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择图片"),
                                                    "../", tr("*.jpg;*.png;*.bmp"));

    if (!filePath.isEmpty()) {
        std::cout << "image path utf8 : " << filePath.toUtf8().toStdString() << "\n";

        _mosicalImgPath = filePath.toUtf8().toStdString();

        // 使用辅助函数加载和显示图片
        if (!loadAndDisplayImage(filePath)) {
            std::cerr << "Failed to load or display the image!\n";

            QMessageBox messageBox(this);
            messageBox.setWindowTitle(tr("提示"));
            messageBox.setText(tr("\n     图片格式错误或文件损坏    "));
            messageBox.setIcon(QMessageBox::Icon::Critical);
            messageBox.exec();
        }

    } else {
        std::cerr << "image path is empty!\n";

        QMessageBox messageBox(this);
        messageBox.setWindowTitle(tr("提示"));
        messageBox.setText(tr("\n     未选择图片    "));
        messageBox.setIcon(QMessageBox::Icon::Warning);
        messageBox.exec();
    }
}

// 新增：辅助函数用于加载和显示图片
bool MaskPage::loadAndDisplayImage(const QString &filePath) {
    QPixmap image(filePath);
    if (image.isNull()) {
        std::cout << "image is Null\n";
        return false;
    }

    // 读取图片
    _srcImg = cv::imread(filePath.toStdString());
    if(_srcImg.empty()){
        std::cout<<"image is Null\n";
        return false;
    }

    _mosicalImg = _srcImg.clone();

    QPixmap scaledImage = image.scaled(uiMask.label_maskImg->size(),
                                       Qt::KeepAspectRatio,
                                       Qt::SmoothTransformation);
    if (scaledImage.isNull()) {
        std::cout << "scaledImage is Null\n";
        return false;
    }

    uiMask.label_maskImg->setPixmap(scaledImage);
    uiMask.label_maskImg->setScaledContents(true);

    return true;
}

bool isValidInt(const std::string& str,const int maxValue){
    for(char c:str){
        if(c < '0' || c > '9'){
            return false;
        }
    }

    int value = std::atoi(str.c_str());
    if(value <= 0 || value > maxValue){
        return false;
    }

    return true;
}

cv::Mat globalMosicalAlgoOne(cv::Mat& srcImg,const int threshold){

    cv::Mat dstImg(cv::Size(srcImg.cols,srcImg.rows),srcImg.type());
    if(srcImg.empty()){
        return dstImg;
    }

    if(threshold <= 0){
        cv::cvtColor(srcImg,dstImg,cv::COLOR_RGB2BGR);
        return dstImg;
    }

    int rowLimit{srcImg.rows / threshold};
    int rowRemain{srcImg.rows % threshold};
    int colLimit{srcImg.cols / threshold};
    int colRemain{srcImg.cols % threshold};

    // 优化边界处理
    bool isRowRemain = (rowRemain != 0);
    bool isColRemain = (colRemain != 0);

    std::cout<<"threshold: "<<threshold<<"\n";
    for(int row{0}; row < rowLimit * threshold; row += threshold) {
        for(int col{0}; col < colLimit * threshold; col += threshold) {
            // 使用区域变换进行优化
            cv::Mat patch = dstImg(cv::Rect(col, row, threshold, threshold));
            cv::Vec3b centerPixel = srcImg.at<cv::Vec3b>(row + threshold / 2, col + threshold / 2);

            for(int irow{0}; irow < patch.rows; ++irow) {
                for(int icol{0}; icol < patch.cols; ++icol) {
                    cv::Vec3b& pixel = patch.at<cv::Vec3b>(irow, icol);
                    pixel[0] = centerPixel[2];
                    pixel[1] = centerPixel[1];
                    pixel[2] = centerPixel[0];
                }
            }
        }
    }

    // 如果存在剩余行或列，手动处理
    if (isRowRemain) {
        for(int col{0}; col < colLimit * threshold; col += threshold) {
            cv::Mat patch = dstImg(cv::Rect(col, rowLimit * threshold, threshold, rowRemain));
            cv::Vec3b centerPixel = srcImg.at<cv::Vec3b>(rowLimit * threshold + rowRemain / 2, col + threshold / 2);

            for(int irow{0}; irow < patch.rows; ++irow) {
                for(int icol{0}; icol < patch.cols; ++icol) {
                    cv::Vec3b& pixel = patch.at<cv::Vec3b>(irow, icol);
                    pixel[0] = centerPixel[2];
                    pixel[1] = centerPixel[1];
                    pixel[2] = centerPixel[0];
                }
            }
        }
    }

    if (isColRemain) {
        for(int row{0}; row < rowLimit * threshold; row += threshold) {
            cv::Mat patch = dstImg(cv::Rect(colLimit * threshold, row, colRemain, threshold));
            cv::Vec3b centerPixel = srcImg.at<cv::Vec3b>(row + threshold / 2, colLimit * threshold + colRemain / 2);

            for(int irow{0}; irow < patch.rows; ++irow) {
                for(int icol{0}; icol < patch.cols; ++icol) {
                    cv::Vec3b& pixel = patch.at<cv::Vec3b>(irow, icol);
                    pixel[0] = centerPixel[2];
                    pixel[1] = centerPixel[1];
                    pixel[2] = centerPixel[0];
                }
            }
        }
    }

    return dstImg;
}

void MaskPage::on_btn_globalMosicalAlgo1_clicked(){
    // 尝试读取图片，如果失败则显示错误信息并返回
    //cv::Mat img = cv::imread(_mosicalImgPath.c_str());
    if (_mosicalImg.empty()) {
        // 显示错误信息
        std::cerr << "无法读取图像：" << _mosicalImgPath << std::endl;
        return;
    }

    if(!isValidInt(uiMask.lineEdit_gloMoAlgoTh->text().toStdString(),
                   std::min(_mosicalImg.rows,_mosicalImg.cols))){
        QMessageBox messageBox(this);
        messageBox.setWindowTitle(tr("提示"));
        messageBox.setText(tr("\n     阈值输入错误    "));
        messageBox.setIcon(QMessageBox::Icon::Warning);
        messageBox.exec();
        return;
    }

    int threshold{uiMask.lineEdit_gloMoAlgoTh->text().toInt()};

    _mosicalImg = globalMosicalAlgoOne(_mosicalImg,threshold);

    QImage image(_mosicalImg.data, _mosicalImg.cols, _mosicalImg.rows,
                 _mosicalImg.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(image);
    uiMask.label_maskImg->setPixmap(pixmap);
}

void MaskPage::on_hSlider_gloMoAlgoTh_valueChanged(const int value){
    std::cout<<"changed value : "<<value<<"\n";
    //cv::Mat img = cv::imread(_mosicalImgPath.c_str());
    if (_mosicalImg.empty()) {
        // 显示错误信息
        std::cerr << "无法读取图像：" << _mosicalImgPath << std::endl;
        return;
    }

    int threshold = value * 0.01 * std::min(_mosicalImg.rows,_mosicalImg.cols);
    _mosicalImg = globalMosicalAlgoOne(_mosicalImg,threshold);

    QImage image(_mosicalImg.data, _mosicalImg.cols, _mosicalImg.rows,
                 _mosicalImg.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(image);
    uiMask.label_maskImg->setPixmap(pixmap);
}

void MaskPage::mousePressEvent(QMouseEvent *event) {

    std::cout<<"label_maskImg: "<< mapToGlobal(uiMask.label_maskImg->pos()).x()<<"\t"
    <<mapToGlobal(uiMask.label_maskImg->pos()).y()<<"\ n";

    std::cout<<"mousePressEvent: "<< event->pos().x()<<"\t"
             <<event->globalPosition().y()<<"\n";

}
