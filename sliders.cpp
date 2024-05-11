#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "physics_system.h"

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

void MainWindow::on_Compressor_LineEdit_val_2_editingFinished()
{
    qDebug("on_Compressor_LineEdit_val_2_editingFinished\n");
    this->findChild<QSlider*>("Compressor_Slider_val_2")
        ->setValue(this->findChild<QLineEdit*>("Compressor_LineEdit_val_2")->text().toInt());
    updateGlobal();
}


void MainWindow::on_Compressor_Slider_val_2_sliderMoved(int position)
{
    qDebug("on_Compressor_Slider_val_2_sliderMoved\n");
    this->findChild<QLineEdit*>("Compressor_LineEdit_val_2")->setText(QString::number(position));
    updateGlobal();
}

