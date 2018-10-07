#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <QValidator>
#include <QString>
#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QTime>
using namespace std;
int whatup = 0; // Running change slider and linetext can living change
int ssignal = 0;// change LED 1 and 0 switch

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ButtonStop->setDisabled(true);
    ui->ButtonReset->setDisabled(true);
    ui->mySlider->setRange(0, 3);

    QTimer *timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(setsignal()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
int gpio_export(unsigned int gpio) //open
{
    int fd, len;
    char buf[64];

    fd=open("/sys/class/gpio/export", O_WRONLY);
    if(fd < 0)
    {
        perror("gpio/export");
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);
    close(fd);

    return 0;
}
int gpio_unexport(unsigned int gpio) //close
{
    int fd, len;
    char buf[64];

    fd=open("/sys/class/gpio/unexport", O_WRONLY);
    if(fd < 0)
    {
        perror("gpio/export");
        return fd;
    }

    len = snprintf(buf, sizeof(buf), "%d", gpio);
    write(fd, buf, len);
    close(fd);

    return 0;
}
int gpio_set_dir(unsigned int gpio, string dirStatus)
{
    int fd;
    char buf[64];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/direction", gpio);

    fd=open(buf, O_WRONLY);
    if(fd < 0)
    {
        perror("gpio/direction");
        return fd;
    }

    if(dirStatus == "out")
    {
        write(fd, "out", 4);
    }
    else
    {
        write(fd, "in", 3);

    }
    close(fd);
    return 0;
}
int gpio_set_value(unsigned int gpio, int value)
{
    int fd;
    char buf[64];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/value", gpio);

    fd=open(buf, O_WRONLY);
    if(fd < 0)
    {
        perror("gpio/set-value");
        return fd;
    }

    if(value == 0)
    {
        write(fd, "0", 2);
    }
    else
    {
        write(fd, "1", 2);

    }
    close(fd);
    return 0;
}

// Pin 46 = gpio162
// Pin 52 = gpio164
// Pin 58 = gpio166
void MainWindow::setsignal()
{
    if(ssignal == 0)
    {
        ui->signal1->setText("1");
        gpio_export(162);
        gpio_set_dir(162, "out");
        gpio_set_value(162, 1);

        ui->signal2->setText("1");
        gpio_export(164);
        gpio_set_dir(164, "out");
        gpio_set_value(164, 1);

        ui->signal3->setText("1");
        gpio_export(166);
        gpio_set_dir(166, "out");
        gpio_set_value(166, 1);
        ssignal = 1;
    }
    else if(ssignal == 1)
    {
        ui->signal1->setText("0");
        gpio_export(162);
        gpio_set_dir(162, "out");
        gpio_set_value(162, 0);

        ui->signal2->setText("0");
        gpio_export(164);
        gpio_set_dir(164, "out");
        gpio_set_value(164, 0);

        ui->signal3->setText("0");
        gpio_export(166);
        gpio_set_dir(166, "out");
        gpio_set_value(166, 0);

        ssignal = 0;
    }
    else
    {
    }
}

void MainWindow::on_ButtonStart_clicked() //onClick ButtonStart
{
    ui->ButtonStart->setDisabled(true);
    ui->ButtonStop->setDisabled(false);
    ui->ButtonReset->setDisabled(false);

    ui->signal1->setText("1");
    gpio_export(162);
    gpio_set_dir(162, "out");
    gpio_set_value(162, 1);
    whatup =1;
    ssignal = 2;

    if(ui->mySlider->value() == 1) //01
    {
        ui->signal2->setText("0");
        gpio_export(164);
        gpio_set_dir(164, "out");
        gpio_set_value(164, 0);

        ui->signal3->setText("1");
        gpio_export(166);
        gpio_set_dir(166, "out");
        gpio_set_value(166, 1);
    }
    else if(ui->mySlider->value() == 2)  //10
    {
        ui->signal2->setText("1");
        gpio_export(164);
        gpio_set_dir(164, "out");
        gpio_set_value(164, 1);

        ui->signal3->setText("0");
        gpio_export(166);
        gpio_set_dir(166, "out");
        gpio_set_value(166, 0);
    }
    else if(ui->mySlider->value() == 3) //11
    {
        ui->signal2->setText("1");
        gpio_export(164);
        gpio_set_dir(164, "out");
        gpio_set_value(164, 1);

        ui->signal3->setText("1");
        gpio_export(166);
        gpio_set_dir(166, "out");
        gpio_set_value(166, 1);
    }
    else
    {
        ui->signal2->setText("0");
        gpio_export(164);
        gpio_set_dir(164, "out");
        gpio_set_value(164, 0);

        ui->signal3->setText("0");
        gpio_export(166);
        gpio_set_dir(166, "out");
        gpio_set_value(166, 0);
    }

}

void MainWindow::on_ButtonStop_clicked() //onClick ButtonStop
{
    ui->ButtonStart->setDisabled(false);
    ui->ButtonStop->setDisabled(true);
    ui->ButtonReset->setDisabled(false);
    whatup = 0;
    //ssignal = 2;

    ui->signal1->setText("0");
    gpio_export(162);
    gpio_set_dir(162, "out");
    gpio_set_value(162, 0);

    ui->signal2->setText("0");
    gpio_export(164);
    gpio_set_dir(164, "out");
    gpio_set_value(164, 0);

    ui->signal3->setText("0");
    gpio_export(166);
    gpio_set_dir(166, "out");
    gpio_set_value(166, 0);
}

void MainWindow::on_ButtonReset_clicked() // onClick ButtonReset
{
    ssignal =0;

    ui->ButtonStart->setDisabled(false);
    ui->ButtonStop->setDisabled(true);
    ui->ButtonReset->setDisabled(true);
    ui->mySlider->setValue(0);
    ui->SliderValue->setText("0");


}

void MainWindow::on_mySlider_sliderMoved(int position) //move mySlider
{
    //int sliderValue = ui->mySlider->value();
    //QString qstr = QString::number(sliderValue);
    QString qstr = QString::number(position);
    ui->SliderValue->setText(qstr);

    if(whatup == 1)
    {
        if(ui->mySlider->value() == 1) //01
        {
            ui->signal2->setText("0");
            gpio_export(164);
            gpio_set_dir(164, "out");
            gpio_set_value(164, 0);

            ui->signal3->setText("1");
            gpio_export(166);
            gpio_set_dir(166, "out");
            gpio_set_value(166, 1);
        }
        else if(ui->mySlider->value() == 2)  //10
        {
            ui->signal2->setText("1");
            gpio_export(164);
            gpio_set_dir(164, "out");
            gpio_set_value(164, 1);

            ui->signal3->setText("0");
            gpio_export(166);
            gpio_set_dir(166, "out");
            gpio_set_value(166, 0);
        }
        else if(ui->mySlider->value() == 3) //11
        {
            ui->signal2->setText("1");
            gpio_export(164);
            gpio_set_dir(164, "out");
            gpio_set_value(164, 1);

            ui->signal3->setText("1");
            gpio_export(166);
            gpio_set_dir(166, "out");
            gpio_set_value(166, 1);
        }
        else
        {
            ui->signal2->setText("0");
            gpio_export(164);
            gpio_set_dir(164, "out");
            gpio_set_value(164, 0);

            ui->signal3->setText("0");
            gpio_export(166);
            gpio_set_dir(166, "out");
            gpio_set_value(166, 0);
        }
    }
}

void MainWindow::on_SliderValue_textChanged(const QString &arg1) //LineText sliderValue
{
    QString str1 = arg1;
    int SV = str1.toInt();  //ret1=12

    if(SV > 3)
    {
        ui->SliderValue->setText("3");
    }
    else if(SV < 0)
    {
        ui->SliderValue->setText("0");
    }
    else
    {
        ui->mySlider->setValue(SV);
    }

    if(whatup == 1)
    {
        if(ui->mySlider->value() == 1) //01
        {
            ui->signal2->setText("0");
            gpio_export(164);
            gpio_set_dir(164, "out");
            gpio_set_value(164, 0);

            ui->signal3->setText("1");
            gpio_export(166);
            gpio_set_dir(166, "out");
            gpio_set_value(166, 1);
        }
        else if(ui->mySlider->value() == 2)  //10
        {
            ui->signal2->setText("1");
            gpio_export(164);
            gpio_set_dir(164, "out");
            gpio_set_value(164, 1);

            ui->signal3->setText("0");
            gpio_export(166);
            gpio_set_dir(166, "out");
            gpio_set_value(166, 0);
        }
        else if(ui->mySlider->value() == 3) //11
        {
            ui->signal2->setText("1");
            gpio_export(164);
            gpio_set_dir(164, "out");
            gpio_set_value(164, 1);

            ui->signal3->setText("1");
            gpio_export(166);
            gpio_set_dir(166, "out");
            gpio_set_value(166, 1);
        }
        else
        {
            ui->signal2->setText("0");
            gpio_export(164);
            gpio_set_dir(164, "out");
            gpio_set_value(164, 0);

            ui->signal3->setText("0");
            gpio_export(166);
            gpio_set_dir(166, "out");
            gpio_set_value(166, 0);
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    gpio_unexport(162);
    gpio_unexport(164);
    gpio_unexport(166);
}

