#include <QApplication>
#include <QDialog>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char **argv) {
	QApplication app(argc, argv);

	QDialog parent;
	parent.resize(320, 240);

	// 创建水平滑块
	QSlider slider(Qt::Horizontal, &parent);
	slider.move(20, 100);
	slider.setRange(0, 200);
	// 创建选值框
	QSpinBox spin(&parent);
	spin.move(220, 100);
	spin.setRange(0, 200);
	// 滑块滑动让选值框数值随之改变
	QObject::connect(&slider, SIGNAL(valueChanged(int)), 
				&spin, SLOT(setValue(int)));
	// 选值框数值改变让滑块随之滑动
    QObject::connect(&spin, SIGNAL(valueChanged(int)), 
           		 &slider, SLOT(setValue(int)));


	parent.show();

	return app.exec();

}
