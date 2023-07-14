#include "erniedialog.h"
#include "ui_erniedialog.h"

ErnieDialog::ErnieDialog(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ErnieDialog)
{
    ui->setupUi(this);
    m_index = 0;
    isStarted = false;
    //设计随机数种子
    qsrand(QTime::currentTime().msec());
    // 加载“./Picture”所有图片到容器的功能
    loadPhotos("./Picture");
    qDebug() << "加载图片个数：" << m_vecPhotos.size();
}

ErnieDialog::~ErnieDialog()
{
    delete ui;
}


void ErnieDialog::on_pushButton_clicked()
{
    if(isStarted == false) {
        isStarted = true;
        m_time = startTimer(50);
        ui->pushButton->setText("Stop");
    } else {
        isStarted = false;
        killTimer(m_time);
        ui->pushButton->setText("Begin");
    }
}

void ErnieDialog::loadPhotos(const QString& path) {
    QDir dir(path);
    // 遍历当前目录中所有图片
    QStringList list1 = dir.entryList(QDir::Files);
    for(int i = 0; i < list1.size(); i++) {
        QImage image(path+"/"+list1.at(i));
        m_vecPhotos << image;
    }
    // 递归遍历子目录中的图片
    QStringList list2 = dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot);
    for(int i = 0; i < list2.size(); i++) {
        loadPhotos(path+"/"+list2.at(i));
    }

}

// 定时器处理函数
void ErnieDialog::timerEvent(QTimerEvent *) {
    m_index = qrand() % m_vecPhotos.size();
    update();
}

// 绘图事件处理函数
void ErnieDialog::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QRect rect = ui->frame->frameRect();
    rect.translate(ui->frame->pos());
    painter.drawImage(rect, m_vecPhotos[m_index]);

}
