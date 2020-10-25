/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_New;
    QAction *action_Open;
    QAction *action_Save;
    QAction *action_Exit;
    QAction *action_Undo;
    QAction *action_Redo;
    QAction *action_Cut;
    QAction *action_Copy;
    QAction *action_Paste;
    QAction *action_Select_all;
    QAction *action_About_program;
    QWidget *centralwidget;
    QTableWidget *Table;
    QTextEdit *Input;
    QPushButton *save;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QMenu *menu_About;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(910, 586);
        action_New = new QAction(MainWindow);
        action_New->setObjectName(QString::fromUtf8("action_New"));
        action_Open = new QAction(MainWindow);
        action_Open->setObjectName(QString::fromUtf8("action_Open"));
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        action_Undo = new QAction(MainWindow);
        action_Undo->setObjectName(QString::fromUtf8("action_Undo"));
        action_Redo = new QAction(MainWindow);
        action_Redo->setObjectName(QString::fromUtf8("action_Redo"));
        action_Cut = new QAction(MainWindow);
        action_Cut->setObjectName(QString::fromUtf8("action_Cut"));
        action_Copy = new QAction(MainWindow);
        action_Copy->setObjectName(QString::fromUtf8("action_Copy"));
        action_Paste = new QAction(MainWindow);
        action_Paste->setObjectName(QString::fromUtf8("action_Paste"));
        action_Select_all = new QAction(MainWindow);
        action_Select_all->setObjectName(QString::fromUtf8("action_Select_all"));
        action_About_program = new QAction(MainWindow);
        action_About_program->setObjectName(QString::fromUtf8("action_About_program"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Table = new QTableWidget(centralwidget);
        if (Table->columnCount() < 2)
            Table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        Table->setObjectName(QString::fromUtf8("Table"));
        Table->setGeometry(QRect(430, 0, 481, 541));
        Table->setGridStyle(Qt::SolidLine);
        Table->setColumnCount(2);
        Table->horizontalHeader()->setDefaultSectionSize(130);
        Table->horizontalHeader()->setStretchLastSection(true);
        Input = new QTextEdit(centralwidget);
        Input->setObjectName(QString::fromUtf8("Input"));
        Input->setGeometry(QRect(10, 0, 391, 231));
        save = new QPushButton(centralwidget);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(160, 230, 80, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 910, 20));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Edit = new QMenu(menubar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menu_About = new QMenu(menubar);
        menu_About->setObjectName(QString::fromUtf8("menu_About"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_Edit->menuAction());
        menubar->addAction(menu_About->menuAction());
        menu_File->addAction(action_New);
        menu_File->addAction(action_Open);
        menu_File->addAction(action_Save);
        menu_File->addSeparator();
        menu_File->addAction(action_Exit);
        menu_Edit->addAction(action_Undo);
        menu_Edit->addAction(action_Redo);
        menu_Edit->addSeparator();
        menu_Edit->addAction(action_Cut);
        menu_Edit->addAction(action_Copy);
        menu_Edit->addAction(action_Paste);
        menu_Edit->addSeparator();
        menu_Edit->addAction(action_Select_all);
        menu_About->addAction(action_About_program);

        retranslateUi(MainWindow);
        QObject::connect(action_Exit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(Input, SIGNAL(copyAvailable(bool)), action_Copy, SLOT(setEnabled(bool)));
        QObject::connect(Input, SIGNAL(copyAvailable(bool)), action_Cut, SLOT(setEnabled(bool)));
        QObject::connect(Input, SIGNAL(undoAvailable(bool)), action_Undo, SLOT(setEnabled(bool)));
        QObject::connect(Input, SIGNAL(redoAvailable(bool)), action_Redo, SLOT(setEnabled(bool)));
        QObject::connect(action_Copy, SIGNAL(triggered()), Input, SLOT(copy()));
        QObject::connect(action_Paste, SIGNAL(triggered()), Input, SLOT(paste()));
        QObject::connect(action_Undo, SIGNAL(triggered()), Input, SLOT(undo()));
        QObject::connect(action_Redo, SIGNAL(triggered()), Input, SLOT(redo()));
        QObject::connect(action_Select_all, SIGNAL(triggered()), Input, SLOT(selectAll()));
        QObject::connect(Input, SIGNAL(textChanged()), MainWindow, SLOT(update()));
        QObject::connect(action_Save, SIGNAL(triggered()), save, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_New->setText(QCoreApplication::translate("MainWindow", "&New", nullptr));
        action_Open->setText(QCoreApplication::translate("MainWindow", "&Open", nullptr));
        action_Save->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
#if QT_CONFIG(shortcut)
        action_Save->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Exit->setText(QCoreApplication::translate("MainWindow", "&Exit", nullptr));
#if QT_CONFIG(shortcut)
        action_Exit->setShortcut(QCoreApplication::translate("MainWindow", "Alt+Del", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Undo->setText(QCoreApplication::translate("MainWindow", "&Undo", nullptr));
#if QT_CONFIG(shortcut)
        action_Undo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Redo->setText(QCoreApplication::translate("MainWindow", "&Redo", nullptr));
#if QT_CONFIG(shortcut)
        action_Redo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Cut->setText(QCoreApplication::translate("MainWindow", "&Cut", nullptr));
#if QT_CONFIG(shortcut)
        action_Cut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Copy->setText(QCoreApplication::translate("MainWindow", "&Copy", nullptr));
#if QT_CONFIG(shortcut)
        action_Copy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Paste->setText(QCoreApplication::translate("MainWindow", "&Paste", nullptr));
#if QT_CONFIG(shortcut)
        action_Paste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Select_all->setText(QCoreApplication::translate("MainWindow", "&Select all", nullptr));
#if QT_CONFIG(shortcut)
        action_Select_all->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        action_About_program->setText(QCoreApplication::translate("MainWindow", "&About program", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Note", nullptr));
        save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        menu_File->setTitle(QCoreApplication::translate("MainWindow", "&File", nullptr));
        menu_Edit->setTitle(QCoreApplication::translate("MainWindow", "&Edit", nullptr));
        menu_About->setTitle(QCoreApplication::translate("MainWindow", "&About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
