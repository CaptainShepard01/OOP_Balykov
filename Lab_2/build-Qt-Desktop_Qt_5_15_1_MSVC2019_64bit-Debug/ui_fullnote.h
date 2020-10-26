/********************************************************************************
** Form generated from reading UI file 'fullnote.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FULLNOTE_H
#define UI_FULLNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FullNote
{
public:
    QPlainTextEdit *NoteShow;
    QPushButton *pushButton;

    void setupUi(QDialog *FullNote)
    {
        if (FullNote->objectName().isEmpty())
            FullNote->setObjectName(QString::fromUtf8("FullNote"));
        FullNote->resize(703, 441);
        FullNote->setMinimumSize(QSize(703, 441));
        FullNote->setMaximumSize(QSize(703, 441));
        NoteShow = new QPlainTextEdit(FullNote);
        NoteShow->setObjectName(QString::fromUtf8("NoteShow"));
        NoteShow->setGeometry(QRect(10, 0, 681, 411));
        pushButton = new QPushButton(FullNote);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 410, 80, 21));

        retranslateUi(FullNote);
        QObject::connect(pushButton, SIGNAL(clicked()), FullNote, SLOT(close()));

        QMetaObject::connectSlotsByName(FullNote);
    } // setupUi

    void retranslateUi(QDialog *FullNote)
    {
        FullNote->setWindowTitle(QCoreApplication::translate("FullNote", "FullNote", nullptr));
        pushButton->setText(QCoreApplication::translate("FullNote", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FullNote: public Ui_FullNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FULLNOTE_H
