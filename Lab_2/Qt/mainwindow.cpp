#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fullnote.h"
#include "QDateTime"

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

struct Note{
    QString data = "";
    QDateTime time = QDateTime::currentDateTime();
};



void MainWindow::on_save_clicked()
{
Note note;
note.data = ui->Input->toPlainText();

if(note.data=="")
    return;

ui->Table->insertRow(0);

auto time = new QTableWidgetItem(note.time.toString());

ui->Table->setItem(0,0,time);

auto data = new QTableWidgetItem(note.data);

ui->Table->setItem(0,1,data);

ui->Table->resizeRowsToContents();
}

void MainWindow::on_Table_cellDoubleClicked(int row, int column)
{
    if(column == 0)
        return;

    QString str = ui->Table->item(row, column)->text();

    FullNote full;
    full.setModal(true);
    full.exec();

    full.Insert(str);

    //full = new FullNote(this);
    //full->show();
}
