#include "CalculatorDialog.h"
// 构造函数
CalculatorDialog::CalculatorDialog(void) {
	// 界面初始化
	setWindowTitle("加法计算器"); // 设置窗口标题
	// 左操作数, this即为当前父窗口指针
	m_editX = new QLineEdit(this);
	// 设置文本对齐：右对齐
	m_editX->setAlignment(Qt::AlignRight);
	// 设置数字验证器	
	m_editX->setValidator(new QDoubleValidator(this));
	// 右操作数
	m_editY = new QLineEdit(this);
	m_editY->setAlignment(Qt::AlignRight);
	m_editY->setValidator(new QDoubleValidator(this));
	// 显示结果
	m_editZ = new QLineEdit(this);
	m_editZ->setAlignment(Qt::AlignRight);
	m_editZ->setReadOnly(true);
	
	// "+"
	m_label = new QLabel("+", this);

	// "="
	m_button = new QPushButton("=", this);
	m_button->setEnabled(false);

	// 创建布局器：自动调整每个控件大小位置
	QHBoxLayout* layout = new QHBoxLayout(this);
	// 按水平方向，依次将控件添加到布局器中
	layout->addWidget(m_editX);
	layout->addWidget(m_label);
	layout->addWidget(m_editY);
	layout->addWidget(m_button);
	layout->addWidget(m_editZ);
	// 设置布局器
	setLayout(layout);

	// 信号和槽函数连接
	// 左右操作数文本改变时，发送信号textChanged()
	connect(m_editX, SIGNAL(textChanged(QString)),
				this, SLOT(enableButton(void)));
	connect(m_editY, SIGNAL(textChanged(QString)),
                this, SLOT(enableButton(void)));
	// 点击按钮，发送信号clicked
	connect(m_button, SIGNAL(clicked(void)), 
				this, SLOT(calcClicked(void)));
}
// 使能等号按钮的槽操作数
void CalculatorDialog::enableButton(void) {
	bool bXok, bYok;
	// text():获取输入文本(QString)
	// toDouble():QString转换为double, 参数保存转为是否成功结果
	m_editX->text().toDouble(&bXok);
	m_editX->text().toDouble(&bYok);
	// 当左右操作数都输入了有效数据，则使能等号按钮，否则设置禁用
	 m_button->setEnabled(bXok && bYok);
}

// 计算结果和显示的槽函数
void CalculatorDialog::calcClicked(void) {
	double res = m_editX->text().toDouble() + m_editY->text().toDouble();
	// number():将double转换为QString
	QString str = QString::number(res);
	// 显示字符串形式结果
	m_editZ->setText(str);
}
	
