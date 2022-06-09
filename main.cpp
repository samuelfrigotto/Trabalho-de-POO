#include "mainwindow.h"

#include <QApplication>

//main onde comeca o programa
int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    MainWindow* w = MainWindow::getInstancia();
    w->show();

    return a.exec();
}
