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
      ui->Table->resizeRowsToContents();
      ui->Table->resizeColumnToContents(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

struct Note{
    QString data = "";
    QDateTime time = QDateTime::currentDateTime();
    int ID = -1;
    bool isArchived = false;
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
        in >> n.ID;
        in >> n.isArchived;

        if (n.isArchived == false)
             {
                 notes.push_back(n);
             }
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
    out << note.ID;
    out << note.isArchived;

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

int LastIndex(QString filename)
{
    QFile file(filename);

    file.open(QIODevice::ReadOnly);

    QDataStream in(&file);

    Note n;

    while (!in.atEnd())
    {
        in >> n.time;
        in >> n.data;
        in >> n.ID;
        in >> n.isArchived;
    }

    file.close();

    return n.ID;
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
ui->Table->resizeColumnToContents(0);

note.ID=LastIndex(STORAGE)+1;

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

void AddToArchive(QVector<QString> notes)
{
    QFile file(STORAGE);

    file.open(QIODevice::ReadWrite);

    QVector<Note> temp;

    QDataStream in(&file);

    while (!in.atEnd()){
        Note n;

        in >> n.time;
        in >> n.data;
        in >> n.ID;
        in >> n.isArchived;

        temp.push_back(n);
    }

    file.close();

    for(int i=0;i<temp.length();++i){
        for(int j=0;j<notes.length();++j){
            if(temp[i].data==notes[j]){
                temp[i].isArchived=true;
            }
        }
    }

    file.open(QIODevice::ReadWrite);
    QDataStream out(&file);

    for(int i =0;i<temp.length();++i){
        out << temp[i].time << temp[i].data << temp[i].ID << temp[i].isArchived;
    }

    file.close();
}

void MainWindow::on_Archivator_clicked()
{
    QModelIndexList selection = ui->Table->selectionModel()->selectedRows();

    QVector<int> indexes;

    for(int i = 0; i < selection.count(); i++)
    {
        QModelIndex index = selection.at(i);
        indexes.push_back(index.row());

        //qDebug() << indexes[i];
    }

    QVector<QString> notes;

    std::sort(indexes.begin(), indexes.end());

    for (int i = 0; i < indexes.length(); i++)
    {
        notes.push_back(ui->Table->item(indexes[i],1)->text());
        qDebug() << indexes[i];
    }

    for(int i = indexes.length() - 1; i >= 0; i--)
    {
        ui->Table->removeRow(indexes[i]);
    }



    AddToArchive(notes);
}

