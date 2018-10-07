#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*QPushButton *button = new QpushButton("Quit");
    QObject::connect(button, SIGNAL(clicked(bool)), &a, SLOT(quit()));
    button->show();*/

    MainWindow w;
    w.show();





    return a.exec();
}
