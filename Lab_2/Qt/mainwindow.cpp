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
      StartReadingArchive();

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

    for (int i = ui->Archive->rowCount(); i >= 0 ; i--)
    {
        ui->Archive->removeRow(i);
    }
}

void FileReadingArchive(QVector<Note> &notes)
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

        if (n.isArchived == true)
             {
                 notes.push_back(n);
             }
    }

    file.close();
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

void MainWindow::StartReadingArchive()
{
    QVector<Note> notes;

    FileReadingArchive(notes);

    for (int i = 0; i < notes.length(); i++)
    {
        QString str = notes[i].time.toString();

        ui->Archive->insertRow(0);

        auto time = new QTableWidgetItem(notes[i].time.toString());

        ui->Archive->setItem(0,0,time);

        auto data = new QTableWidgetItem(notes[i].data);

        ui->Archive->setItem(0,1,data);
    }

    ui->Archive->resizeColumnToContents(0);
    ui->Archive->resizeRowsToContents();
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
    ui->Table->resizeColumnToContents(0);
    ui->Table->resizeRowsToContents();
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

void MainWindow::RemoveFromArchive(QVector<int> indexes)
{
    QFile file(STORAGE);

    file.open(QIODevice::ReadOnly);

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
        for(int j=0;j<indexes.length();++j){
            if(temp[i].time.toString()==ui->Archive->item(indexes[j], 0)->text() && temp[i].data==ui->Archive->item(indexes[j], 1)->text()){
                temp[i].isArchived=false;
            }
        }
    }

    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    for(int i =0;i<temp.length();++i){
        out << temp[i].time << temp[i].data << temp[i].ID << temp[i].isArchived;
    }

    file.close();
}

void MainWindow::AddToArchive(QVector<int> indexes)
{
    QFile file(STORAGE);

    file.open(QIODevice::ReadOnly);

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
        for(int j=0;j<indexes.length();++j){
            if(temp[i].time.toString()==ui->Table->item(indexes[j], 0)->text() && temp[i].data==ui->Table->item(indexes[j], 1)->text()){
                temp[i].isArchived=true;
            }
        }
    }

    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    for(int i =0;i<temp.length();++i){
        out << temp[i].time << temp[i].data << temp[i].ID << temp[i].isArchived;
    }

    file.close();
}

void MainWindow::DeleteSelected(QVector<int> indexes)
{
    QFile file(STORAGE);

    file.open(QIODevice::ReadOnly);

    QVector<Note> temp;

    QVector<bool> isDeleted;

    QDataStream in(&file);

    while (!in.atEnd()){
        Note n;

        in >> n.time;
        in >> n.data;
        in >> n.ID;
        in >> n.isArchived;

        temp.push_back(n);
        isDeleted.push_back(false);
    }

    file.close();

    for(int i=0;i<temp.length();++i){
        for(int j=0;j<indexes.length();++j){
            if(temp[i].time.toString()==ui->Table->item(indexes[j], 0)->text() && temp[i].data==ui->Table->item(indexes[j], 1)->text()){
                isDeleted[i]=true;
            }
        }
    }

    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    for(int i =0;i<temp.length();++i){
        if(isDeleted[i]){
            continue;
        }
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

    AddToArchive(indexes);

    std::sort(indexes.begin(), indexes.end());

    for(int i = indexes.length() - 1; i >= 0; i--)
    {
        ui->Table->removeRow(indexes[i]);
    }

    for (int i = ui->Archive->rowCount(); i >= 0 ; i--)
    {
        ui->Archive->removeRow(i);
    }

    StartReadingArchive();
}

void MainWindow::on_Delete_clicked()
{
    QModelIndexList selection = ui->Table->selectionModel()->selectedRows();

    QVector<int> indexes;

    for(int i = 0; i < selection.count(); i++)
    {
        QModelIndex index = selection.at(i);
        indexes.push_back(index.row());

        //qDebug() << indexes[i];
    }

    DeleteSelected(indexes);

    for(int i = indexes.length() - 1; i >= 0; i--)
    {
        ui->Table->removeRow(indexes[i]);
    }
}

void MainWindow::on_Dearchivate_clicked()
{
    QModelIndexList selection = ui->Archive->selectionModel()->selectedRows();

    QVector<int> indexes;

    for(int i = 0; i < selection.count(); i++)
    {
        QModelIndex index = selection.at(i);
        indexes.push_back(index.row());

        //qDebug() << indexes[i];
    }

     RemoveFromArchive(indexes);

    std::sort(indexes.begin(), indexes.end());

    for(int i = indexes.length() - 1; i >= 0; i--)
    {
        ui->Archive->removeRow(indexes[i]);
    }

    for (int i = ui->Table->rowCount(); i >= 0 ; i--)
    {
        ui->Table->removeRow(i);
    }

    StartReading();
}

void MainWindow::on_Archive_cellDoubleClicked(int row, int column)
{
    if(column == 0)
        return;

    QString str = ui->Archive->item(row, column)->text();

    //ui->Input->insertPlainText(str);

    FullNote full;
    full.Insert(str);
    //full.setModal(true);
    full.exec();
}

//TO DO get used to functionality of pop-up menu
void MainWindow::on_Table_customContextMenuRequested(const QPoint &pos)
{
        QMenu *menu=new QMenu(this);
        menu->addAction(new QAction("Action 1", this));
        menu->addAction(new QAction("Action 2", this));
        menu->addAction(new QAction("Action 3", this));
        menu->popup(ui->Table->viewport()->mapToGlobal(pos));
}
