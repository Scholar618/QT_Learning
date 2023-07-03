#ifndef __LOGINDIALOG_H
#define __LOGINDIALOG_H

#include "ui_LoginDialog.h"
#include <QMessageBox> // 消息提示框
#include <QDebug> // 打印显示

class LoginDialog:public QDialog, public Ui::LoginDialog {
	Q_OBJECT
public:
	LoginDialog(void);
public slots:
	// 处理OK按钮的槽函数
	void onAccepted(void);
	// 处理Cancel按钮的槽函数
	void onRejected(void);
};

#endif // __LOGINDIALOG_H
