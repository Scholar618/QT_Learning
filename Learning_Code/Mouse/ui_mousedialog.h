/********************************************************************************
** Form generated from reading UI file 'mousedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOUSEDIALOG_H
#define UI_MOUSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MouseDialog
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MouseDialog)
    {
        if (MouseDialog->objectName().isEmpty())
            MouseDialog->setObjectName(QString::fromUtf8("MouseDialog"));
        MouseDialog->resize(461, 600);
        centralwidget = new QWidget(MouseDialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 180, 91, 101));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(53, 132, 228);"));
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Raised);
        MouseDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MouseDialog);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 461, 28));
        MouseDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(MouseDialog);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MouseDialog->setStatusBar(statusbar);

        retranslateUi(MouseDialog);

        QMetaObject::connectSlotsByName(MouseDialog);
    } // setupUi

    void retranslateUi(QMainWindow *MouseDialog)
    {
        MouseDialog->setWindowTitle(QCoreApplication::translate("MouseDialog", "MouseDialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MouseDialog: public Ui_MouseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUSEDIALOG_H
