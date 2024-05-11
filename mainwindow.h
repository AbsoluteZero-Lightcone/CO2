#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void update_param_from_array(int* array);

    void updateGlobal();
private slots:
    void on_pushButton_Default_clicked();

    void on_Compressor_LineEdit_val_1_editingFinished();
    void on_Compressor_Slider_val_1_sliderMoved(int position);
    void on_Compressor_LineEdit_val_2_editingFinished();
    void on_Compressor_Slider_val_2_sliderMoved(int position);

    void on_Evaporator_LineEdit_val_1_editingFinished();
    void on_Evaporator_Slider_val_1_sliderMoved(int position);
    void on_Evaporator_LineEdit_val_2_editingFinished();
    void on_Evaporator_Slider_val_2_sliderMoved(int position);

    void on_GasCooler_LineEdit_val_1_editingFinished();
    void on_GasCooler_Slider_val_1_sliderMoved(int position);
    void on_GasCooler_LineEdit_val_2_editingFinished();
    void on_GasCooler_Slider_val_2_sliderMoved(int position);

    void on_ThrottleValve_LineEdit_val_1_editingFinished();
    void on_ThrottleValve_Slider_val_1_sliderMoved(int position);
    void on_ThrottleValve_LineEdit_val_2_editingFinished();
    void on_ThrottleValve_Slider_val_2_sliderMoved(int position);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
