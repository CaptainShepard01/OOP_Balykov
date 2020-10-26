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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QAction *action_Delete_all;
    QAction *action_Archivate_selected;
    QAction *action_Delete_selected;
    QAction *actionTab_switcher;
    QAction *actionEnter_new_note;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *Insertion;
    QTextEdit *Input;
    QComboBox *comboBox_Input;
    QPushButton *save;
    QGroupBox *Notes;
    QTableWidget *Table;
    QPushButton *Delete;
    QPushButton *Archivator;
    QPushButton *DeleteAll;
    QComboBox *comboBox_Notes;
    QWidget *tab_2;
    QTableWidget *Archive;
    QPushButton *Dearchivate;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Edit;
    QMenu *menu_About;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(910, 610);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(910, 610));
        MainWindow->setMaximumSize(QSize(910, 610));
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
        action_Delete_all = new QAction(MainWindow);
        action_Delete_all->setObjectName(QString::fromUtf8("action_Delete_all"));
        action_Archivate_selected = new QAction(MainWindow);
        action_Archivate_selected->setObjectName(QString::fromUtf8("action_Archivate_selected"));
        action_Delete_selected = new QAction(MainWindow);
        action_Delete_selected->setObjectName(QString::fromUtf8("action_Delete_selected"));
        actionTab_switcher = new QAction(MainWindow);
        actionTab_switcher->setObjectName(QString::fromUtf8("actionTab_switcher"));
        actionEnter_new_note = new QAction(MainWindow);
        actionEnter_new_note->setObjectName(QString::fromUtf8("actionEnter_new_note"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 911, 601));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        Insertion = new QGroupBox(tab);
        Insertion->setObjectName(QString::fromUtf8("Insertion"));
        Insertion->setGeometry(QRect(10, 0, 401, 491));
        Insertion->setAlignment(Qt::AlignCenter);
        Input = new QTextEdit(Insertion);
        Input->setObjectName(QString::fromUtf8("Input"));
        Input->setGeometry(QRect(0, 50, 391, 271));
        comboBox_Input = new QComboBox(Insertion);
        comboBox_Input->addItem(QString());
        comboBox_Input->addItem(QString());
        comboBox_Input->setObjectName(QString::fromUtf8("comboBox_Input"));
        comboBox_Input->setGeometry(QRect(320, 20, 72, 22));
        save = new QPushButton(Insertion);
        save->setObjectName(QString::fromUtf8("save"));
        save->setGeometry(QRect(150, 320, 80, 21));
        Notes = new QGroupBox(tab);
        Notes->setObjectName(QString::fromUtf8("Notes"));
        Notes->setGeometry(QRect(420, 0, 481, 491));
        Notes->setAlignment(Qt::AlignCenter);
        Table = new QTableWidget(Notes);
        if (Table->columnCount() < 2)
            Table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        Table->setObjectName(QString::fromUtf8("Table"));
        Table->setGeometry(QRect(20, 50, 421, 401));
        Table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        Table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Table->setSelectionBehavior(QAbstractItemView::SelectRows);
        Table->setGridStyle(Qt::SolidLine);
        Table->setColumnCount(2);
        Table->horizontalHeader()->setMinimumSectionSize(30);
        Table->horizontalHeader()->setDefaultSectionSize(130);
        Table->horizontalHeader()->setStretchLastSection(true);
        Table->verticalHeader()->setDefaultSectionSize(19);
        Delete = new QPushButton(Notes);
        Delete->setObjectName(QString::fromUtf8("Delete"));
        Delete->setGeometry(QRect(130, 450, 91, 21));
        Archivator = new QPushButton(Notes);
        Archivator->setObjectName(QString::fromUtf8("Archivator"));
        Archivator->setGeometry(QRect(240, 450, 101, 21));
        sizePolicy.setHeightForWidth(Archivator->sizePolicy().hasHeightForWidth());
        Archivator->setSizePolicy(sizePolicy);
        DeleteAll = new QPushButton(Notes);
        DeleteAll->setObjectName(QString::fromUtf8("DeleteAll"));
        DeleteAll->setGeometry(QRect(360, 450, 80, 21));
        comboBox_Notes = new QComboBox(Notes);
        comboBox_Notes->addItem(QString());
        comboBox_Notes->addItem(QString());
        comboBox_Notes->setObjectName(QString::fromUtf8("comboBox_Notes"));
        comboBox_Notes->setGeometry(QRect(370, 20, 72, 22));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        Archive = new QTableWidget(tab_2);
        if (Archive->columnCount() < 2)
            Archive->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Archive->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Archive->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        Archive->setObjectName(QString::fromUtf8("Archive"));
        Archive->setGeometry(QRect(440, 50, 421, 401));
        Archive->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Archive->setSelectionBehavior(QAbstractItemView::SelectRows);
        Archive->setGridStyle(Qt::SolidLine);
        Archive->setColumnCount(2);
        Archive->horizontalHeader()->setDefaultSectionSize(130);
        Archive->horizontalHeader()->setStretchLastSection(true);
        Dearchivate = new QPushButton(tab_2);
        Dearchivate->setObjectName(QString::fromUtf8("Dearchivate"));
        Dearchivate->setGeometry(QRect(600, 450, 121, 21));
        tabWidget->addTab(tab_2, QString());
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
        menu_Edit->addAction(action_Paste);
        menu_Edit->addAction(action_Cut);
        menu_Edit->addAction(action_Copy);
        menu_Edit->addAction(action_Delete_selected);
        menu_Edit->addAction(action_Archivate_selected);
        menu_Edit->addSeparator();
        menu_Edit->addAction(action_Select_all);
        menu_Edit->addAction(action_Delete_all);
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
        QObject::connect(action_Delete_all, SIGNAL(triggered()), DeleteAll, SLOT(click()));
        QObject::connect(action_Archivate_selected, SIGNAL(triggered()), Archivator, SLOT(click()));
        QObject::connect(action_Delete_selected, SIGNAL(triggered()), Delete, SLOT(click()));
        QObject::connect(actionTab_switcher, SIGNAL(triggered()), tabWidget, SLOT(update()));
        QObject::connect(actionEnter_new_note, SIGNAL(triggered()), Input, SLOT(raise()));

        tabWidget->setCurrentIndex(0);


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
        action_Delete_all->setText(QCoreApplication::translate("MainWindow", "&Delete all", nullptr));
#if QT_CONFIG(shortcut)
        action_Delete_all->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Del", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Archivate_selected->setText(QCoreApplication::translate("MainWindow", "&Archivate selected", nullptr));
#if QT_CONFIG(shortcut)
        action_Archivate_selected->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Ins", nullptr));
#endif // QT_CONFIG(shortcut)
        action_Delete_selected->setText(QCoreApplication::translate("MainWindow", "&Delete selected", nullptr));
#if QT_CONFIG(shortcut)
        action_Delete_selected->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTab_switcher->setText(QCoreApplication::translate("MainWindow", "Tab switcher", nullptr));
#if QT_CONFIG(shortcut)
        actionTab_switcher->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Tab", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEnter_new_note->setText(QCoreApplication::translate("MainWindow", "Enter new note", nullptr));
#if QT_CONFIG(shortcut)
        actionEnter_new_note->setShortcut(QCoreApplication::translate("MainWindow", "Alt+Return", nullptr));
#endif // QT_CONFIG(shortcut)
        Insertion->setTitle(QCoreApplication::translate("MainWindow", "Input section", nullptr));
        Input->setMarkdown(QString());
        Input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter your note here...", nullptr));
        comboBox_Input->setItemText(0, QCoreApplication::translate("MainWindow", "Personal", nullptr));
        comboBox_Input->setItemText(1, QCoreApplication::translate("MainWindow", "Work", nullptr));

        save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        Notes->setTitle(QCoreApplication::translate("MainWindow", "Notes", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Note", nullptr));
        Delete->setText(QCoreApplication::translate("MainWindow", "Delete selected", nullptr));
        Archivator->setText(QCoreApplication::translate("MainWindow", "Archivate selected", nullptr));
        DeleteAll->setText(QCoreApplication::translate("MainWindow", "DeleteAll", nullptr));
        comboBox_Notes->setItemText(0, QCoreApplication::translate("MainWindow", "Personal", nullptr));
        comboBox_Notes->setItemText(1, QCoreApplication::translate("MainWindow", "Work", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Input and Actual notes", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Archive->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Archive->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Note", nullptr));
        Dearchivate->setText(QCoreApplication::translate("MainWindow", "Dearchivate selected", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Archive", nullptr));
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
