#ifndef MOUSEDIALOG_H
#define MOUSEDIALOG_H

#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MouseDialog; }
QT_END_NAMESPACE

class MouseDialog : public QMainWindow
{
    Q_OBJECT

public:
    MouseDialog(QWidget *parent = nullptr);
    ~MouseDialog();

private:
    // 按下
    void mousePressEvent(QMouseEvent *);
    // 抬起
    void mouseReleaseEvent(QMouseEvent *);
    // 移动
    void mouseMoveEvent(QMouseEvent *);

private:
    Ui::MouseDialog *ui;
    bool m_drag;
    QPoint m_pos;
    // QRect(x, y, w, h) QPoint(x, y) QSize(w, h)
};
#endif // MOUSEDIALOG_H
