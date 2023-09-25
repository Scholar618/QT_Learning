#include "cardialog.h"
#include "ui_cardialog.h"


CarDialog::CarDialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CarDialog)
    , speed(1.5)
    , carX(0)
    , carY(0)
{
    ui->setupUi(this);
    resize(648, 648);
    picLabel = new QLabel(this);
    picLabel->setFixedSize(100, 40);
    picLabel->setStyleSheet("board: none;");
    timer.setInterval(10);

    // 创建系统托盘图标
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/car.png"));
    trayIcon->setVisible(true);

    // 创建托盘图标菜单
    QMenu* trayMenu = new QMenu(this);
    QAction* restoreAction = new QAction("恢复", trayMenu);
    QAction* quitAction = new QAction("退出", trayMenu);
    trayMenu->addAction(restoreAction);
    trayMenu->addAction(quitAction);

    // 连接菜单项的信号槽
    connect(restoreAction, &QAction::triggered, this, &CarDialog::restoreWindow);
    connect(quitAction, &QAction::triggered, this, &CarDialog::quitApplication);

    // 将菜单设置给托盘图标
    trayIcon->setContextMenu(trayMenu);
}

CarDialog::~CarDialog()
{
    delete ui;
}


// 开始
void CarDialog::on_beginBotton_clicked()
{
    // 断开之前的连接
    disconnect(&timer, &QTimer::timeout, this, &CarDialog::updateCarPosition);
    carX = 0;
    carY = 0;
    timer.setInterval(10 / speed); // 根据速度调整定时器的间隔
    //move(0, 0); // 将小车移动到左上角
    timer.start(); // 启动定时器
    connect(&timer, &QTimer::timeout, this, &CarDialog::updateCarPosition); // 连接定时器的timeout信号与更新小车位置的槽函数
}

// 暂停
void CarDialog::on_pauseBotton_clicked()
{
    timer.stop(); // 停止定时器
    hide(); // 隐藏小车
}

// 加速
void CarDialog::on_speedBotton_clicked()
{
    speed += 0.2;
    timer.setInterval(10 / speed); // 根据速度调整定时器的间隔
}

// 减速
void CarDialog::on_slowBotton_clicked()
{
    speed -= 0.2;
    timer.setInterval(10 / speed); // 根据速度调整定时器的间隔
}

// 关闭
void CarDialog::on_closeBotton_clicked()
{
    hide(); // 隐藏窗口
    trayIcon->show(); // 显示托盘图标
}

void CarDialog::paintEvent(QPaintEvent *)
{
    // qDebug("paintEvent");
    // 显示图片
    // 创建画家对象
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/car.png");
    painter.drawPixmap(carX, carY, picLabel->width(),picLabel->height(),pix);
}

void CarDialog::updateCarPosition()
{
    // 更新小车的位置
    carX += speed; // 根据速度更新X坐标
    carY += speed; // 根据速度更新Y坐标

    // 重新绘制窗口
    update();
}

void CarDialog::restoreWindow()
{
    show(); // 显示窗口
    trayIcon->hide(); // 隐藏托盘图标
}

void CarDialog::quitApplication()
{
    trayIcon->hide(); // 隐藏托盘图标
    qApp->quit(); // 退出应用程序
}




