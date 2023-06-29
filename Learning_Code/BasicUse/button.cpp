#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QTextCodec>

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	
	// 创建编码对象
	QTextCodec *coder = QTextCodec::codecForName("gbk");
	
	// 将要显示的gbk编码字符串转换为unicode
	QLabel label(coder->toUnicode("我是标签"));
	label.show();

	QPushButton button(coder->toUnicode("我是按钮"));
	button.show();

	return app.exec();

}
