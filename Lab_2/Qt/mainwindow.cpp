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
      StartReading();
}

MainWindow::~MainWindow()
{
    delete ui;
}

struct Note{
    QString data = "";
    QDateTime time = QDateTime::currentDateTime();
};

void MainWindow::on_DeleteAll_clicked()
{
    QFile file(STORAGE);
    file.open(QIODevice::WriteOnly);
    file.close();

    for (int i = ui->Table->rowCount(); i >= 0 ; i--)
    {
        ui->Table->removeRow(i);
    }
}

void FileReading(QVector<Note> &notes)
{
    QFile file(STORAGE);

    file.open(QIODevice::ReadOnly);

    QDataStream in(&file);

    while (!in.atEnd())
    {
        Note n;

        in >> n.time;
        in >> n.data;

        notes.push_back(n);
    }

    file.close();
}

void FileWriting(Note note)
{
    QFile file(STORAGE);

    file.open(QIODevice::Append);

    QDataStream out(&file);

    out << note.time;
    out << note.data;

    file.close();
}

void MainWindow::StartReading()
{
    QVector<Note> notes;

    FileReading(notes);

    for (int i = 0; i < notes.length(); i++)
    {
        QString str = notes[i].time.toString();

        ui->Table->insertRow(0);

        auto time = new QTableWidgetItem(notes[i].time.toString());

        ui->Table->setItem(0,0,time);

        auto data = new QTableWidgetItem(notes[i].data);

        ui->Table->setItem(0,1,data);
    }
}

void MainWindow::on_save_clicked()
{
Note note;
note.data = ui->Input->toPlainText();

if(note.data=="")
    return;

ui->Input->clear();

ui->Table->insertRow(0);

auto time = new QTableWidgetItem(note.time.toString());

ui->Table->setItem(0,0,time);

auto data = new QTableWidgetItem(note.data);

ui->Table->setItem(0,1,data);

ui->Table->resizeRowsToContents();

FileWriting(note);
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
