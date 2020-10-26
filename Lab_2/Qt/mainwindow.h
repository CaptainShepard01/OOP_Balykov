#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "fullnote.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_save_clicked();

    void on_Table_cellDoubleClicked(int row, int column);

    void StartReading();
    void on_DeleteAll_clicked();


    void on_Archivator_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
