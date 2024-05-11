#ifndef LOAD_PARAM_H
#define LOAD_PARAM_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#define DEFAULT_CONFIG_FILE ".\\res\\config.zyf"

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

extern const std::string param_str[param_COUNT];
extern QString param_Slider_Name[param_COUNT];
extern QString param_LineEdit_Name[param_COUNT];
extern int param_val_default[param_COUNT];

#endif // LOAD_PARAM_H
