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
MaskPage::MaskPage(){

    uiMask.setupUi(this);

    setWindowIcon(QIcon("../Icon/arrow_right.png"));
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

    QPixmap scaledImage = image.scaled(uiMask.label_maskImg->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    if (scaledImage.isNull()) {
        std::cout << "scaledImage is Null\n";
        return false;
    }

    uiMask.label_maskImg->setPixmap(scaledImage);
    uiMask.label_maskImg->setScaledContents(true);

    return true;
}


void MaskPage::on_btn_globalMosicalAlgo1_clicked(){
    // 尝试读取图片，如果失败则显示错误信息并返回
    cv::Mat img = cv::imread(_mosicalImgPath.c_str());
    if (img.empty()) {
        // 显示错误信息
        std::cerr << "无法读取图像：" << _mosicalImgPath << std::endl;
        return;
    }

    int threshold{30};
    int rowLimit{img.rows / threshold};
    int rowRemain{img.rows % threshold};
    int colLimit{img.cols / threshold};
    int colRemain{img.cols % threshold};

    // 优化边界处理
    bool isRowRemain = (rowRemain != 0);
    bool isColRemain = (colRemain != 0);

    for(int row{0}; row < rowLimit * threshold; row += threshold) {
        for(int col{0}; col < colLimit * threshold; col += threshold) {
            // 使用区域变换进行优化
            cv::Mat patch = img(cv::Rect(col, row, threshold, threshold));
            cv::Vec3b centerPixel = img.at<cv::Vec3b>(row + threshold / 2, col + threshold / 2);

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
        for(int col{0}; col < img.cols; col += threshold) {
            cv::Mat patch = img(cv::Rect(col, rowLimit * threshold, threshold, rowRemain));
            cv::Vec3b centerPixel = img.at<cv::Vec3b>(rowLimit * threshold + rowRemain / 2, col + threshold / 2);

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
        for(int row{0}; row < img.rows; row += threshold) {
            cv::Mat patch = img(cv::Rect(colLimit * threshold, row, colRemain, threshold));
            cv::Vec3b centerPixel = img.at<cv::Vec3b>(row + threshold / 2, colLimit * threshold + colRemain / 2);

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

    QImage image(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    QPixmap pixmap = QPixmap::fromImage(image);
    uiMask.label_maskImg->setPixmap(pixmap);
}
