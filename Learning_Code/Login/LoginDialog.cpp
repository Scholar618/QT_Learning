#include "LoginDialog.h"
// 构造函数
LoginDialog::LoginDialog(void) {
	// 界面初始化
	setupUi(this);
	// 信号和槽的连接
	// 点击OK发送信号accepted;点击Cancel发送信号rejected
	connect(m_btnBox, SIGNAL(accepted(void)),
				this, SLOT(onAccepted(void)));
	connect(m_btnBox, SIGNAL(rejected(void)),
				this, SLOT(onRejected(void)));
}

// 处理OK按钮的槽函数
void LoginDialog::onAccepted(void) {
	// admin:123456，提示登陆成功，否则提示失败
	if(m_usrnameEdit->text() == "admin" && 
				m_passwordEdit->text() == "123456") {
		qDebug() << "登陆成功";
		close(); // 关闭登录窗口
	} else {
		QMessageBox msgBox(
					QMessageBox::Critical, // 图标
					"Error", // 标题
					"用户名或密码错误", // 提示信息
					QMessageBox::Ok, // 按钮
					this); // 父窗口
		// 显示消息提示框，并进入事件循环
		msgBox.exec();
	}

}

// 处理Cancel按钮的槽函数
void LoginDialog::onRejected(void) {
	QMessageBox msgBox(
				QMessageBox::Question,
				"登录",
				"是否确认取消登录?",
				QMessageBox::Yes|QMessageBox::No,
				this);
	// 显示消息提示框并进入事件循环，点击Yes或No都会退出事件循环
	// 但是返回结果不同，如果点击Yes则退出登录对话框
	if(msgBox.exec() == QMessageBox::Yes) {
		close();
	}

}
