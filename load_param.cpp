#include "load_param.h"
#include <qmessagebox.h>
//#include <fstream>
//#include <iostream>
#include <QFile>
int param_val_default[param_COUNT];

const QString param_str[param_COUNT]={
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

int findInArray(const QString s,const QString* arr,const int length){
    for(int i = 0 ; i < length ;i++)
        if(arr[i]==s)return i;
    return -1;
}
/*
config.zyf:
# 节流阀默认参数
    param_Compressor_val_1 100
    param_Compressor_val_2 200
# 压缩机默认参数
    ...
# 气体冷却器默认参数
    ...
# 蒸发器默认参数
    ...
*/
void load_default_param_array_from_file(){
    for(int i = 0 ; i < param_COUNT; i++){
        param_val_default[i] = -1;
    }
    QFile file(QApplication::applicationDirPath()+"/"+DEFAULT_CONFIG_FILE);
    if(file.exists()){
        if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
            QTextStream infile(&file);
            QString configline;
            int val;
            while(!infile.atEnd()){
                infile >> configline;
                if(configline=="")continue;
                if(configline[0]=='#')continue;
                int index = findInArray(configline,param_str,param_COUNT);
                if(index==-1)continue;
                infile >> val;
                param_val_default[index] = val;
            }
        }
    }
    else{
        file.open(QIODevice::ReadWrite|QIODevice::Text);
        QTextStream outfile(&file);
        outfile <<"# 压缩机参数"<<"\n";
        outfile <<"param_Compressor_val_1 "<<10<<"\n";
        outfile <<"param_Compressor_val_2 "<<10<<"\n";
        outfile <<"# 蒸发器参数"<<"\n";
        outfile <<"param_Evaporator_val_1 "<<10<<"\n";
        outfile <<"param_Evaporator_val_2 "<<10<<"\n";
        outfile <<"# 气体冷却器参数"<<"\n";
        outfile <<"param_GasCooler_val_1 "<<10<<"\n";
        outfile <<"param_GasCooler_val_2 "<<10<<"\n";
        outfile <<"# 节流阀参数"<<"\n";
        outfile <<"param_ThrottleValve_val_1 "<<10<<"\n";
        outfile <<"param_ThrottleValve_val_2 "<<10<<"\n";
        file.close();
        throw QString("程序初始化失败，未找到配置信息，但已在")+QString(QApplication::applicationDirPath()+"/"+DEFAULT_CONFIG_FILE)+QString("创建空配置文件");
    }

    for(int i = 0 ; i < param_COUNT; i++)
        if(param_val_default[i] == -1)
            throw QString("程序初始化失败，配置信息不完整");
}
/*
void load_default_param_array_from_file(){
    for(int i = 0 ; i < param_COUNT; i++){
        param_val_default[i] = -1;
    }

    std::ifstream infile(DEFAULT_CONFIG_FILE, std::ios::in);
    if(infile.is_open()){
        std::string configline;
        int val;
        while(!infile.eof()){
            infile >> configline;
            std::cout << "configline:"<<configline<<std::endl;
            if(configline=="")continue;
            if(configline[0]=='#')continue;
            int index = findInArray(configline,param_str,param_COUNT);
            if(index==-1)continue;
            infile >> val;
            param_val_default[index] = val;
        }
    }
    else {
        std::ofstream outfile(DEFAULT_CONFIG_FILE,std::ios::out);
        if(!outfile.is_open())throw "程序初始化失败，空配置文件的创建亦失败";
        outfile <<"# 压缩机参数"<<std::endl;
        outfile <<"param_Compressor_val_1 "<<10<<std::endl;
        outfile <<"param_Compressor_val_2 "<<10<<std::endl;
        outfile <<"# 蒸发器参数"<<std::endl;
        outfile <<"param_Evaporator_val_1 "<<10<<std::endl;
        outfile <<"param_Evaporator_val_2 "<<10<<std::endl;
        outfile <<"# 气体冷却器参数"<<std::endl;
        outfile <<"param_GasCooler_val_1 "<<10<<std::endl;
        outfile <<"param_GasCooler_val_2 "<<10<<std::endl;
        outfile <<"# 节流阀参数"<<std::endl;
        outfile <<"param_ThrottleValve_val_1 "<<10<<std::endl;
        outfile <<"param_ThrottleValve_val_2 "<<10<<std::endl;
        throw "程序初始化失败，未找到配置信息，已创建空配置文件";
    }
    infile.close();
    for(int i = 0 ; i < param_COUNT; i++)
        if(param_val_default[i] == -1)
            throw "程序初始化失败，配置信息不完整";
}
*/
void MainWindow::update_param_from_array(int* array){
    for(int i = 0 ; i < param_COUNT ;i++){
        QSlider* ptrSlider = this->findChild<QSlider*>(param_Slider_Name[i]);
        QLineEdit* ptrLineEdit = this->findChild<QLineEdit*>(param_LineEdit_Name[i]);
        //std::cout << ptrSlider<<std::endl;
        //std::cout << ptrLineEdit <<std::endl;
        if(ptrSlider)ptrSlider->setValue(array[i]);
        if(ptrLineEdit)ptrLineEdit->setText(QString::number(array[i]));
    }
}
