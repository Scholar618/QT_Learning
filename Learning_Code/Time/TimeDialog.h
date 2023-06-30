#ifndef __TIMEDIALOG_H
#define __TIMEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout> // 垂直布局器
#include <QTime> // 时间
#include <QDebug> // 打印调试

class TimeDialog:public QDialog {
	Q_OBJECT //moc
public:
	// 构造函数
	TimeDialog(void);
public slots:
	// 获取系统时间的槽函数
	void getTime(void);
private:
	QLabel* m_label; // 显示时间label
	QPushButton* m_button; // 获取时间button
};

#endif // __TIMEDIALOG_H
