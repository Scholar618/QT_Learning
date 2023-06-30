#ifndef __CALCULATORDIALOG_H
#define __CALCULATORDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit> // 行编辑控件
#include <QHBoxLayout> // 水平布局器
#include <QDoubleValidator> // 验证器

class CalculatorDialog:public QDialog {
	Q_OBJECT // moc
public:
	CalculatorDialog(void);
public slots:
	// 使能等号按钮的槽操作数
	void enableButton(void);
	// 计算结果和显示的槽函数
	void calcClicked(void);
private:
	QLineEdit* m_editX; // 左操作数
	QLineEdit* m_editY; // 右操作数
	QLineEdit* m_editZ; // 显示结果
	QLabel* m_label; // "+"
	QPushButton* m_button; // "="
};

#endif // __CALCULATORDIALOG_H
