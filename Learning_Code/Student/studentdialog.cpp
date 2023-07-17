#include "studentdialog.h"
#include "ui_studentdialog.h"

StudentDialog::StudentDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentDialog)
{
    ui->setupUi(this);
    createDB();
    createTable();
    queryTable();
}

StudentDialog::~StudentDialog()
{
    delete ui;
}
// 创建数据库
void StudentDialog::createDB() {
    // 添加数据库驱动
    db = QSqlDatabase::addDatabase("QSQLITE");
    // 设置数据库名字
    db.setDatabaseName("student.db");
    // 打开数据库
    if(db.open() == true) {
        qDebug() << "创建/打开数据库成功!\n";
    } else {
        qDebug() << "创建/打开数据库失败!\n";
    }
}
// 创建数据表
void StudentDialog::createTable() {
    QSqlQuery query;
    QString str = QString("CREATE TABLE student ("
                          "id INT PRIMARY KEY NOT NULL,"
                          "name TEXT NOT NULL,"
                          "score REAL NOT NULL)");
    if(query.exec(str) == false) {
        qDebug() << str;
    } else {
        qDebug() << "创建student表成功!\n";
    }
}
// 查询
void StudentDialog::queryTable() {
    QString str = QString("SELECT * FROM student");
    model.setQuery(str);
    ui->tableView->setModel(&model);
}

// 插入操作槽函数
void StudentDialog::on_insertButton_2_clicked()
{
    QSqlQuery query;
    int id = ui->IDEdit->text().toInt();
    QString name = ui->nameEdit_2->text();
    double score = ui->scoreEdit_3->text().toDouble();
    QString str = QString("INSERT INTO student VALUES(%1, '%2', %3)").arg(id).arg(name).arg(score);
    if(query.exec(str) == false) {
        qDebug() << str;
    } else {
        qDebug() << "插入数据成功!\n";
        queryTable();
    }
}

// 删除操作槽函数:根据ID删除数据
void StudentDialog::on_deleteButton_3_clicked()
{
    QSqlQuery query;
    int id = ui->IDEdit->text().toInt();
    QString str = QString("DELETE FROM student WHERE id = %1").arg(id);
    if(query.exec(str) == false) {
        qDebug() << str;
    } else {
        qDebug() << "删除数据成功!\n";
        queryTable();
    }

}

// 修改操作槽函数:根据ID根据成绩
void StudentDialog::on_updateButton_5_clicked()
{
    QSqlQuery query;
    int id = ui->IDEdit->text().toInt();
    QString name = ui->nameEdit_2->text();
    double score = ui->scoreEdit_3->text().toDouble();
    QString str = QString("Update student SET score = %1, name = '%2' WHERE id = %3").arg(score).arg(name).arg(id);
    if(query.exec(str) == false) {
        qDebug() << str;
    } else {
        qDebug() << "修改成功!\n";
        queryTable();
    }

}

// 排序操作槽函数
void StudentDialog::on_sortButton_clicked()
{
    // 获取排序列名
    QString value = ui->valuecomboBox->currentText();
    // 获取排序方式
    QString condition;
    if(ui->conditioncomboBox_2->currentIndex() == 0) {
        condition = "ASC"; // 升序
    } else {
        condition = "DESC"; // 降序
    }
    QString str = QString("SELECT *FROM student ORDER BY %1 %2").arg(value).arg(condition);

    // 查询和显示
    model .setQuery(str);
    ui->tableView->setModel(&model);






}
