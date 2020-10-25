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

QT_BEGIN_NAMESPACE

class Ui_FullNote
{
public:
    QPlainTextEdit *NoteShow;

    void setupUi(QDialog *FullNote)
    {
        if (FullNote->objectName().isEmpty())
            FullNote->setObjectName(QString::fromUtf8("FullNote"));
        FullNote->resize(400, 300);
        NoteShow = new QPlainTextEdit(FullNote);
        NoteShow->setObjectName(QString::fromUtf8("NoteShow"));
        NoteShow->setGeometry(QRect(-10, 0, 411, 271));

        retranslateUi(FullNote);

        QMetaObject::connectSlotsByName(FullNote);
    } // setupUi

    void retranslateUi(QDialog *FullNote)
    {
        FullNote->setWindowTitle(QCoreApplication::translate("FullNote", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FullNote: public Ui_FullNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FULLNOTE_H
