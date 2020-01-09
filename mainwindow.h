#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   // void makePLot();

    void on_pushButton_Parabol_clicked();

    void on_pushButtonExponansiyel_clicked();

    void on_pushButtonSin_clicked();

    void on_pushButtonSquare_clicked();

    void on_pushButtonLinear_clicked();

    void on_pushButtonTriangle_clicked();

    void on_pushButtonSawTooth_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
