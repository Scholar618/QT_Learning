#include "TimeDialog.h"
#include <QFont>
// 构造函数
TimeDialog::TimeDialog(void) {
	// 初始化界面
	m_label = new QLabel(this);
	// 设置label边框消息:凹陷面板
	m_label->setFrameStyle(QFrame::Panel|QFrame::Sunken);
	// 设置label文本对齐方式：水平/垂直居中
	m_label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
	// 设置label的字体大小
	QFont font;
	font.setPointSize(20);
	m_label->setFont(font);

	// 获取系统时间按钮
	m_button = new QPushButton("获取当前时间",this);
	m_button->setFont(font);

	// 创建垂直布局器
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(m_label);
	layout->addWidget(m_button);

	// 设置布局器
	setLayout(layout);

	// 信号和槽函数连接
	connect(m_button, SIGNAL(clicked(void)),
				this, SLOT(getTime(void)));
}

// 获取系统时间的槽函数
void TimeDialog::getTime(void) {
	qDebug("getTime");
	qDebug() << "getTime";
	// 获取当前系统时间
	QTime time = QTime::currentTime();
	// 将时间对象转换为字符串
	QString str = time.toString("hh::mm::ss");
	// 显示时间
	m_label->setText(str);
}


