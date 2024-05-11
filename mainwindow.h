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
private slots:
    void on_pushButton_Default_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
