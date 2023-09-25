#ifndef CARDIALOG_H
#define CARDIALOG_H

#include <QMainWindow>
#include <QDialog>
#include <QPainter>
#include <QPushButton>
#include <QImage>
#include <QLabel>
#include <QTimer>
#include <qsystemtrayicon.h>

QT_BEGIN_NAMESPACE
namespace Ui { class CarDialog; }
QT_END_NAMESPACE

class CarDialog : public QMainWindow
{
    Q_OBJECT

public:
    CarDialog(QWidget *parent = nullptr);
    ~CarDialog();


private slots:
    void on_beginBotton_clicked();

    void on_pauseBotton_clicked();

    void on_speedBotton_clicked();

    void on_slowBotton_clicked();

    void on_closeBotton_clicked();

    void updateCarPosition();

    void restoreWindow();

    void quitApplication();
private:
    // 绘图事件处理函数
    void paintEvent(QPaintEvent *);
    QLabel *picLabel;
    Ui::CarDialog *ui;
    double speed; // 速度
    QTimer timer;
    int carX;
    int carY;
    QSystemTrayIcon* trayIcon;
};
#endif // CARDIALOG_H
