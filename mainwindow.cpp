#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include "load_param.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Default_clicked()
{
    int array[param_COUNT]={10,10,10,10,10,10,10,10};
    update_param_from_array(param_val_default);
    //update_param_from_array(array);
    //QSlider* ptrSlider = this->findChild<QSlider*>("Compressor_Slider_val_1");
    //ptrSlider->setValue(100);

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::NoIcon);
    msgBox.setWindowTitle("设置成功");
    msgBox.setText("已经将所有参数恢复至默认值。");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}
