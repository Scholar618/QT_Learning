#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QDialog>

int main(int argc, char **argv) {
	QApplication app(argc, argv);

	QDialog parent;// 父窗口
	parent.resize(320, 240);

	QLabel label("我是标签", &parent);
	label.move(50, 40);
	QPushButton button("关闭标签", &parent);
	button.move(50, 140);
	QPushButton button2("退出", &parent);
	button2.move(200, 140);
	parent.show();
	// 点击按钮关闭标签
	QObject::connect(&button, SIGNAL(clicked(void)), 
			&label, SLOT(close(void)));
	// 增加退出按钮，实现点击按钮退出应用程序
	QObject::connect(&button2, SIGNAL(clicked(void)),
			&app, SLOT(closeALLWindows(void)));
//			&app, SLOT(quit(void)));
//			&parent, SLOT(close(void)));
	return app.exec();

}
