#include <QWidget>
#include <QDialog>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QApplication>

int main(int argc, char **argv) {
	QApplication app(argc, argv);
	
	//QWidget parent;
	QDialog parent;
	//QMainWindow parent;
	parent.move(50,50);
	parent.resize(320, 240);
//	parent.show();
	
	// 创建标签控件，停靠在父窗口上
	QLabel label("我是标签", &parent);
	label.move(100,40);
	// 创建按钮控件，停靠在父窗口上
	QPushButton button("我是按钮", &parent);
	button.move(20, 100);
	button.resize(80, 80);

	// new对象如果指定了父窗口指针，可以不写delete，在父窗口对象销毁时
	// 它会自动被销毁
	QPushButton* button2 = new QPushButton("我是按钮", &parent);
	button2->move(170, 100);
	button2->resize(80,80);

	parent.show();// 父窗口显示，上面停靠的控件也一起显示

	return app.exec();
}
