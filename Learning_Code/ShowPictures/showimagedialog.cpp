#include "showimagedialog.h"
#include "ui_showimagedialog.h"

ShowImageDialog::ShowImageDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowImageDialog)
{
    ui->setupUi(this);
    m_index = 1;
}

ShowImageDialog::~ShowImageDialog()
{
    delete ui;
}


void ShowImageDialog::on_m_btnPrev_clicked()
{
    if(--m_index < 1) {
        m_index = 10;
    }
    update(); // 触发绘图事件
}

void ShowImageDialog::on_m_btnNext_clicked()
{
    if(++m_index > 10) {
        m_index = 1;
    }
    update();
}

// Painting event (virtual)
void ShowImageDialog::paintEvent(QPaintEvent *) {
    // qDebug("paintEvent");
    // show
    // 1) create paint_object
    QPainter painter(this);
    // 2) get paint_area
    QRect rect = ui->frame->frameRect();
    // 坐标值平移,使得rect和paint的使用相同坐标系
    rect.translate(ui->frame->pos());
    // 3) get picture_object
    QImage image(":/Picture/" + QString::number(m_index) + ".jpg/");
    // 4) use painter paint image to rect
    painter.drawImage(rect, image);

}
