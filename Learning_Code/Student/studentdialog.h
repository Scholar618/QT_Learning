#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class StudentDialog; }
QT_END_NAMESPACE

class StudentDialog : public QDialog
{
    Q_OBJECT

public:
    StudentDialog(QWidget *parent = nullptr);
    ~StudentDialog();

private:
    // 创建数据库
    void createDB();
    // 创建数据表
    void createTable();
    // 查询
    void queryTable();

private slots:
    // 插入操作槽函数
    void on_insertButton_2_clicked();
    // 删除操作槽函数
    void on_deleteButton_3_clicked();
    // 修改操作槽函数
    void on_updateButton_5_clicked();
    // 排序操作槽函数
    void on_sortButton_clicked();

private:
    Ui::StudentDialog *ui;
    QSqlDatabase db; // 建立Qt和数据库连接
    QSqlQueryModel model; // 保存结果集
};
#endif // STUDENTDIALOG_H
