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
    QString type = "Personal";
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
        in >> n.type;
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
        in >> n.type;

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
    out << note.type;

    file.close();
}

void MainWindow::StartReadingArchive()
{
    QVector<Note> notes;

    FileReadingArchive(notes);

    for (int i = 0; i < notes.length(); i++)
    {
        QString str = notes[i].time.toString();

        if(notes[i].type=="Personal"){

        ui->Archive->insertRow(0);

        auto time = new QTableWidgetItem(notes[i].time.toString());

        ui->Archive->setItem(0,0,time);

        auto data = new QTableWidgetItem(notes[i].data);

        ui->Archive->setItem(0,1,data);
        }

        else{
            ui->Work_Archive->insertRow(0);

            auto time = new QTableWidgetItem(notes[i].time.toString());

            ui->Work_Archive->setItem(0,0,time);

            auto data = new QTableWidgetItem(notes[i].data);

            ui->Work_Archive->setItem(0,1,data);
        }
    }

    ui->Archive->resizeColumnToContents(0);
    ui->Archive->resizeRowsToContents();

    ui->Work_Archive->resizeColumnToContents(0);
    ui->Work_Archive->resizeRowsToContents();
}

void MainWindow::StartReading()
{
    QVector<Note> notes;

    FileReading(notes);

    for (int i = 0; i < notes.length(); i++)
    {
        QString str = notes[i].time.toString();

        if(notes[i].type=="Personal"){
        ui->Table->insertRow(0);

        auto time = new QTableWidgetItem(notes[i].time.toString());

        ui->Table->setItem(0,0,time);

        auto data = new QTableWidgetItem(notes[i].data);

        ui->Table->setItem(0,1,data);
        }

        else{
            ui->Work_Table->insertRow(0);

            auto time = new QTableWidgetItem(notes[i].time.toString());

            ui->Work_Table->setItem(0,0,time);

            auto data = new QTableWidgetItem(notes[i].data);

            ui->Work_Table->setItem(0,1,data);
        }
    }
    ui->Table->resizeColumnToContents(0);
    ui->Table->resizeRowsToContents();

    ui->Work_Table->resizeColumnToContents(0);
    ui->Work_Table->resizeRowsToContents();
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
        in >> n.type;
    }

    file.close();

    return n.ID;
}

void MainWindow::on_save_clicked()
{
    Note note;
    note.data = ui->Input->toPlainText();
    if(note.data.length()>=200)
    {
        return;
    }

    if(note.data=="")
        return;

    note.type = ui->comboBox_Input->currentText();

    ui->Input->clear();

    if(note.type=="Personal"){
    ui->Table->insertRow(0);

    auto time = new QTableWidgetItem(note.time.toString());

    ui->Table->setItem(0,0,time);

    auto data = new QTableWidgetItem(note.data);

    ui->Table->setItem(0,1,data);

    ui->Table->resizeRowsToContents();
    ui->Table->resizeColumnToContents(0);
    }
    else{
        ui->Work_Table->insertRow(0);

        auto time = new QTableWidgetItem(note.time.toString());

        ui->Work_Table->setItem(0,0,time);

        auto data = new QTableWidgetItem(note.data);

        ui->Work_Table->setItem(0,1,data);

        ui->Work_Table->resizeRowsToContents();
        ui->Work_Table->resizeColumnToContents(0);
    }

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

    file.open(QIODevice::ReadWrite);

    Note temp;

    long long pos = 0;

    QDataStream in(&file);

    while (!in.atEnd())
       {
           pos = file.pos();

           in >> temp.time;
           in >> temp.data;
           in >> temp.ID;
           in >> temp.isArchived;
           in >> temp.type;

           for (int i = 0; i < indexes.length(); i++)
           {
               if (temp.time.toString() == ui->Archive->item(indexes[i], 0)->text() && temp.data == ui->Archive->item(indexes[i], 1)->text())
               {
                   file.seek(pos);

                   temp.isArchived = false;

                   in << temp.time;
                   in << temp.data;
                   in << temp.ID;
                   in << temp.isArchived;
                   in << temp.type;

                   break;
               }
           }
       }

    file.close();
}

void MainWindow::AddToArchive(QVector<int> indexes)
{
    QFile file(STORAGE);

    file.open(QIODevice::ReadWrite);

    Note temp;

    QDataStream in(&file);

    long long pos = 0;

    while (!in.atEnd())
       {
           pos = file.pos();

           in >> temp.time;
           in >> temp.data;
           in >> temp.ID;
           in >> temp.isArchived;
           in >> temp.type;

           for (int i = 0; i < indexes.length(); i++)
           {
               if (temp.time.toString() == ui->Table->item(indexes[i], 0)->text() && temp.data == ui->Table->item(indexes[i], 1)->text())
               {
                   file.seek(pos);

                   temp.isArchived = true;

                   in << temp.time;
                   in << temp.data;
                   in << temp.ID;
                   in << temp.isArchived;
                   in << temp.type;

                   break;
               }
           }
       }

    file.close();
}

void MainWindow::DeleteSelected(QVector<int> indexes, QString filename)
{
    QFile file(filename);
    QFile file_del("TEMP");

    file.open(QIODevice::ReadOnly);
    file_del.open(QIODevice::WriteOnly);

    Note temp;

    QVector<bool> isDeleted;

    bool toDelete = false;

    QDataStream in(&file);
    QDataStream in_del(&file_del);

    while (!in.atEnd()){
        Note n;

        in >> n.time;
        in >> n.data;
        in >> n.ID;
        in >> n.isArchived;
        in >> n.type;

        for (int i = 0; i < indexes.length(); i++)
        {
            if (temp.time.toString() == ui->Table->item(indexes[i], 0)->text() && temp.data == ui->Table->item(indexes[i], 1)->text())
            {
               toDelete = true;
               break;
            }
        }

        if(!toDelete){
            in_del << n.time << n.data << n.ID << n.isArchived << n.type;
        }

        toDelete = false;
    }

   file.close();
   file_del.close();

   remove(filename.toStdString().c_str());
   rename("TEMP", filename.toStdString().c_str());
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

    DeleteSelected(indexes, STORAGE);

    std::sort(indexes.begin(), indexes.end());

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

void MainWindow::on_Input_cursorPositionChanged()
{
    if(ui->Input->toPlainText().length()>200)
        return;
}
