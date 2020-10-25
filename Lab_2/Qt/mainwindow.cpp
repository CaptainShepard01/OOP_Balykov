#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fullnote.h"
#include "QDateTime"
#include <QDebug>
#include <QFile>

#define STORAGE "Storage_file.dat"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
      ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    saveToFile();
    delete ui;
}

struct Note{
    QString data = "";
    QString time = QDateTime::currentDateTime().toString();
};

void MainWindow::saveToFile()
{
    QFile file{STORAGE};
    if (!file.open(QIODevice::WriteOnly |QIODevice::Append | QIODevice::Text))
               return;
    QTextStream stream(&file);

    Note note;

    for(int i=0;i<ui->Table->rowCount();++i){
        note.data=ui->Table->item(i, 1)->text();
        note.time=ui->Table->item(i,0)->text();
        stream << note.time << note.data;
    }

    file.close();
}

void MainWindow::on_save_clicked()
{
Note note;
note.data = ui->Input->toPlainText();

if(note.data=="")
    return;

ui->Input->clear();

ui->Table->insertRow(0);

auto time = new QTableWidgetItem(note.time);

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

    //ui->Input->insertPlainText(str);

    FullNote full;
    full.Insert(str);
    //full.setModal(true);
    full.exec();
}
