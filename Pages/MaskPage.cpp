//
// Created by MSI on 2024/3/26.
//

#include "MaskPage.h"
#include <iostream>

#include <QFileDialog>
#include <QFile>
#include <opencv2/opencv.hpp>

#include <QMessageBox>

MaskPage::MaskPage(){

    uiMask.setupUi(this);

    setWindowIcon(QIcon("../Icon/arrow_right.png"));
}

MaskPage::~MaskPage(){

}

void MaskPage::on_btn_readImg_clicked(){

    std::cout<<"btn_readImg_clicked\n";
    // 创建并显示一个文件对话框
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择图片"),
                                                    "../", tr("*.jpg *.png *.bmp"));

    // 检查是否有文件被选中
    if(!filePath.isEmpty()){

        std::cout<<"image path: "<<filePath.toStdString()<<"\n";
        _mosicalImgPath = filePath.toStdString();

        //显示图片
        QPixmap image(filePath);
        if(image.isNull()){
            std::cout<<"image is Null\n";
        }
        QPixmap scaledImage = image.scaled(uiMask.label_maskImg->size(), Qt::KeepAspectRatio,
                                           Qt::SmoothTransformation);
        if(scaledImage.isNull()){
            std::cout<<"scaledImage is Null\n";
        }
        uiMask.label_maskImg->setPixmap(scaledImage);

        // 随着label大小动态缩放图片
        uiMask.label_maskImg->setScaledContents(true);

    }else{
        std::cerr<<"image path is empty!\n";

        QMessageBox messageBox(this);
        messageBox.setWindowTitle(tr("提示"));
        messageBox.setText(tr("\n     未选择图片    "));
        messageBox.setIcon(QMessageBox::Icon::Warning);
        messageBox.exec();
    }

}

void MaskPage::on_btn_globalMosicalAlgo1_clicked(){

    int threshold{3};
    cv::Mat img = cv::imread(_mosicalImgPath);

    int rowLimit{img.rows/threshold};
    int rowRemain{img.rows%threshold};
    int colLimit{img.cols/threshold};
    int colRemain{img.cols%threshold};

    for(int row{0};row<rowLimit;row+=threshold){
        for(int col{0};col<colLimit;col+=threshold){

            for(int irow{row};irow<row+threshold;irow++){
                for(int icol{col};icol<col+threshold;icol++){
                    img.at<cv::Vec3b>(irow,icol)[0] = img.at<cv::Vec3b>(row+threshold/2,col+threshold/2)[0];
                    img.at<cv::Vec3b>(irow,icol)[1] = img.at<cv::Vec3b>(row+threshold/2,col+threshold/2)[1];
                    img.at<cv::Vec3b>(irow,icol)[2] = img.at<cv::Vec3b>(row+threshold/2,col+threshold/2)[2];
                }
            }

        }
    }

    QImage image(img.data, img.cols, img.rows,
                 img.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(image);
    uiMask.label_maskImg->setPixmap(pixmap);

}