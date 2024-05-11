#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qmessagebox.h>

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

#include <fstream>
#include <string>
/*
config.zyf:
# 节流阀默认参数

# 压缩机默认参数
# 气体冷却器默认参数
# 蒸发器默认参数
*/
enum param_config_enum{
    param_val_1=0,
    param_count
};
void init_param(){
    std::ifstream infile(".\\res\\config.zyf", std::ios::in);
    std::string configline;
    while(!infile.eof()){
        infile >> configline;
        if(configline=="")continue;
        if(configline.at(0)=='#')continue;
    };


}

void MainWindow::on_pushButton_Default_clicked()
{
    //init_param();
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::NoIcon);
    msgBox.setWindowTitle("设置成功");
    msgBox.setText("已经将所有参数恢复至默认值。");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

