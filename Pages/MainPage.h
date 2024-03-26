//
// Created by YF on 2024/3/5.
//

#ifndef UNTITLED1_MAINPAGE_H
#define UNTITLED1_MAINPAGE_H

#include "../UI/ui_untitled.h"


class MainPage : public QMainWindow{

    Q_OBJECT
public:
    explicit MainPage(QWidget *parent = nullptr);

    ~MainPage();

private:
    Ui_MainWindow ui;


private:
    // 美化calendarWidget
    void beautifyCalendarWidget();


private slots:
    void on_actionmask_triggered();
};


#endif //UNTITLED1_MAINPAGE_H
