#ifndef SHOWIMAGEDIALOG_H
#define SHOWIMAGEDIALOG_H

#include <QDialog>
#include <QPainter>
#include <QImage>  // Load Pictures

QT_BEGIN_NAMESPACE
namespace Ui { class ShowImageDialog; }
QT_END_NAMESPACE

class ShowImageDialog : public QDialog
{
    Q_OBJECT

public:
    ShowImageDialog(QWidget *parent = nullptr);
    ~ShowImageDialog();

private slots:
    void on_m_btnPrev_clicked();

    void on_m_btnNext_clicked();
private:
    // Painting event (virtual)
    void paintEvent(QPaintEvent *);

private:
    Ui::ShowImageDialog *ui;
    int m_index; // pic_Index
};
#endif // SHOWIMAGEDIALOG_H
