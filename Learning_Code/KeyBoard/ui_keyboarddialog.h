/********************************************************************************
** Form generated from reading UI file 'keyboarddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARDDIALOG_H
#define UI_KEYBOARDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeyBoardDialog
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *KeyBoardDialog)
    {
        if (KeyBoardDialog->objectName().isEmpty())
            KeyBoardDialog->setObjectName(QString::fromUtf8("KeyBoardDialog"));
        KeyBoardDialog->resize(518, 541);
        centralwidget = new QWidget(KeyBoardDialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 160, 101, 121));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 163, 72);"));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Raised);
        KeyBoardDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(KeyBoardDialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 518, 28));
        KeyBoardDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(KeyBoardDialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        KeyBoardDialog->setStatusBar(statusbar);

        retranslateUi(KeyBoardDialog);

        QMetaObject::connectSlotsByName(KeyBoardDialog);
    } // setupUi

    void retranslateUi(QMainWindow *KeyBoardDialog)
    {
        KeyBoardDialog->setWindowTitle(QCoreApplication::translate("KeyBoardDialog", "KeyBoardDialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class KeyBoardDialog: public Ui_KeyBoardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARDDIALOG_H
