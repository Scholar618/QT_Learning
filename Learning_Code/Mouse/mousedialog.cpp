#include "mousedialog.h"
#include "ui_mousedialog.h"

MouseDialog::MouseDialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MouseDialog)
{
    ui->setupUi(this);
    m_drag = false;
}

MouseDialog::~MouseDialog()
{
    delete ui;
}

// 按下
void MouseDialog::mousePressEvent(QMouseEvent *event) {
    // 判断是否为鼠标左键
    if(event->button() == Qt::LeftButton) {
        // 获取label所在的矩形区域
        QRect rect = ui->label->frameRect();
        // 坐标平移
        rect.translate(ui->label->pos());
        // 判断鼠标点击的位置是否在rect矩形区域中
        if(rect.contains(event->pos())) {
            m_drag = true;
            m_pos = ui->label->pos() - event->pos();

        }
    }

}
// 抬起
void MouseDialog::mouseReleaseEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        m_drag = false;
    }
}
// 移动
void MouseDialog::mouseMoveEvent(QMouseEvent *event) {
    if(m_drag) {
        // 计算label要移动的新位置
        QPoint newPos = event->pos() + m_pos;

        // 设置标签不超出窗口范围
        QSize s1 = size(); // 获取父窗口大小
        QSize s2 = ui->label->size();// 获取label大小
        // x:0~窗口宽-label宽
        if(newPos.x() < 0) {
            newPos.setX(0);
        } else if(newPos.x() > s1.width() - s2.width()) {
            newPos.setX(s1.width() - s2.width());
        }
        // y:1~窗口高-label高
        if(newPos.y() < 0) {
            newPos.setY(0);
        } else if(newPos.y() > s1.height() - s2.height()) {
            newPos.setY(s1.height() - s2.height());
        }

        // 移动label到新位置
        ui->label->move(newPos);
    }
}
