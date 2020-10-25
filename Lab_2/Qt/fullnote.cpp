#include "fullnote.h"
#include "ui_fullnote.h"

FullNote::FullNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FullNote)
{
    ui->setupUi(this);
}

FullNote::~FullNote()
{
    delete ui;
}

void FullNote::Insert(QString str){
    ui->NoteShow->insertPlainText(str);
}
