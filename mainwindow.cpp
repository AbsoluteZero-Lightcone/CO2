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
enum param_config_enum{
    param_Compressor_val_1=0,
    param_Compressor_val_2,
    param_Evaporator_val_1,
    param_Evaporator_val_2,
    param_GasCooler_val_1,
    param_GasCooler_val_2,
    param_ThrottleValve_val_1,
    param_ThrottleValve_val_2,
    param_COUNT
};

const std::string param_str[param_COUNT]={
    "param_Compressor_val_1",
    "param_Compressor_val_2",
    "param_Evaporator_val_1",
    "param_Evaporator_val_2",
    "param_GasCooler_val_1",
    "param_GasCooler_val_2",
    "param_ThrottleValve_val_1",
    "param_ThrottleValve_val_2",
};
const QString param_Slider_Name[param_COUNT]={
    "Compressor_Slider_val_1",
    "Compressor_Slider_val_2",
    "Evaporator_Slider_val_1",
    "Evaporator_Slider_val_2",
    "GasCooler_Slider_val_1",
    "GasCooler_Slider_val_2",
    "ThrottleValve_Slider_val_1",
    "ThrottleValve_Slider_val_2",
};
const QString param_LineEdit_Name[param_COUNT]={
    "Compressor_LineEdit_val_1",
    "Compressor_LineEdit_val_2",
    "Evaporator_LineEdit_val_1",
    "Evaporator_LineEdit_val_2",
    "GasCooler_LineEdit_val_1",
    "GasCooler_LineEdit_val_2",
    "ThrottleValve_LineEdit_val_1",
    "ThrottleValve_LineEdit_val_2",
};
int param_val_default[param_COUNT];

int findInArray(const std::string s,const std::string* arr,const int length){
    for(int i = 0 ; i < length ;i++)
        if(arr[i]==s)return i;
    return -1;
}
/*
config.zyf:
# 节流阀默认参数
    "param_Compressor_val_1",
    "param_Compressor_val_2",
# 压缩机默认参数
# 气体冷却器默认参数
# 蒸发器默认参数
*/
void load_default_param(){
    for(int i = 0 ; i < param_COUNT; i++){
        param_val_default[i] = -1;
    }

    std::ifstream infile(".\\res\\config.zyf", std::ios::in);
    std::string configline;
    int val;
    while(!infile.eof()){
        infile >> configline;
        //if(configline=="")continue;
        if(configline.at(0)=='#')continue;
        int index = findInArray(configline,param_str,param_COUNT);
        if(index==-1)continue;
        infile >> val;
        param_val_default[index] = val;
    }

    for(int i = 0 ; i < param_COUNT; i++)
        if(param_val_default[i] == -1){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::NoIcon);
            msgBox.setWindowTitle("错误");
            msgBox.setText("程序初始化失败");
            msgBox.setStandardButtons(QMessageBox::Abort);
            msgBox.setDefaultButton(QMessageBox::Abort);
            msgBox.exec();
        }
}

void MainWindow::update_param_from_default(){
    for(int i = 0 ; i < param_COUNT ;i++){
        QSlider* ptrSlider = this->findChild<QSlider*>(param_Slider_Name[i]);
        QLineEdit* ptrLineEdit = this->findChild<QLineEdit*>(param_LineEdit_Name[i]);
        ptrSlider->setValue(param_val_default[i]);
        ptrLineEdit->setText(QString::number(param_val_default[i]));
    }
}

void MainWindow::on_pushButton_Default_clicked()
{
    update_param_from_default();
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::NoIcon);
    msgBox.setWindowTitle("设置成功");
    msgBox.setText("已经将所有参数恢复至默认值。");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

