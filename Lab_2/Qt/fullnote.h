#ifndef FULLNOTE_H
#define FULLNOTE_H

#include <QDialog>

namespace Ui {
class FullNote;
}

class FullNote : public QDialog
{
    Q_OBJECT

public:
    explicit FullNote(QWidget *parent = nullptr);
    ~FullNote();
    void Insert(QString str);

private:
    Ui::FullNote *ui;
};

#endif // FULLNOTE_H
