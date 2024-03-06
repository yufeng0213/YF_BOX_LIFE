#include <QApplication>
#include <QPushButton>
#include "MainPage.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainPage mainPage;
    mainPage.show();

    return QApplication::exec();
}
