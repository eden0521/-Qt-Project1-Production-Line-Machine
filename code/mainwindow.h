#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //int gpio_export(unsigned int );

private slots:
    void setsignal();
    void on_ButtonStart_clicked();

    void on_ButtonStop_clicked();

    void on_ButtonReset_clicked();

    void on_mySlider_sliderMoved(int position);

    void on_SliderValue_textChanged(const QString &arg1);

    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
