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
    void StartReadingArchive();
    void on_DeleteAll_clicked();

    void AddToArchive(QVector<int> indexes);
    void RemoveFromArchive(QVector<int> indexes);
    void DeleteSelected(QVector<int> indexes, QString filename);
    void on_Archivator_clicked();

    void on_Delete_clicked();

    void on_Dearchivate_clicked();

    void on_Archive_cellDoubleClicked(int row, int column);

    void on_Table_customContextMenuRequested(const QPoint &pos);

    void on_Input_cursorPositionChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
