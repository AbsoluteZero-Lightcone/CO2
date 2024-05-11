#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include "load_param.h"
#include "physics_system.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QMessageBox::warning(this,"Debug:",QApplication::applicationDirPath()+"/"+DEFAULT_CONFIG_FILE);
    try{
        load_default_param_array_from_file();
        update_param_from_array(param_val_default);
    }
    catch(QString err){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::NoIcon);
        msgBox.setWindowTitle("错误");
        msgBox.setText(err);
        msgBox.setStandardButtons(QMessageBox::Abort);
        msgBox.setDefaultButton(QMessageBox::Abort);
        msgBox.exec();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Default_clicked()
{
    try{
        load_default_param_array_from_file();
        //int temp[param_COUNT]={10,10,10,10,10,10,10,10};
        update_param_from_array(param_val_default);

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::NoIcon);
        msgBox.setWindowTitle("设置成功");
        msgBox.setText("已经将所有参数设置为默认值。");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    catch(QString err){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::NoIcon);
        msgBox.setWindowTitle("错误");
        msgBox.setText(err);
        msgBox.setStandardButtons(QMessageBox::Abort);
        msgBox.setDefaultButton(QMessageBox::Abort);
        msgBox.exec();
    }
}

void MainWindow::on_Compressor_LineEdit_val_1_editingFinished()
{
    qDebug("on_Compressor_LineEdit_val_1_editingFinished\n");
    this->findChild<QSlider*>("Compressor_Slider_val_1")
        ->setValue(this->findChild<QLineEdit*>("Compressor_LineEdit_val_1")->text().toInt());
    updateGlobal();
}


void MainWindow::on_Compressor_Slider_val_1_sliderMoved(int position)
{
    qDebug("on_Compressor_Slider_val_1_sliderMoved\n");
    this->findChild<QLineEdit*>("Compressor_LineEdit_val_1")->setText(QString::number(position));
    updateGlobal();
}


