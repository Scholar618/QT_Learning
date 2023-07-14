#ifndef ERNIEDIALOG_H
#define ERNIEDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QDir>
#include <QVector>
#include <QImage>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class ErnieDialog; }
QT_END_NAMESPACE

class ErnieDialog : public QWidget
{
    Q_OBJECT

public:
    ErnieDialog(QWidget *parent = nullptr);
    ~ErnieDialog();

private slots:
    void on_pushButton_clicked();
    // 定时器到时后要执行的函数
    void onTimeout(void);

private:
    void loadPhotos(const QString& path);

    // void timerEvent(QTimerEvent *);

    void paintEvent(QPaintEvent *);

private:
    Ui::ErnieDialog *ui;
    QVector<QImage> m_vecPhotos; // 保存图片的容器
    int m_index; // 图片在容器索引
    // int m_time; // 定时器ID
    QTimer m_timer; // 定时器
    bool isStarted; // 标记

};
#endif // ERNIEDIALOG_H
