#include "cardialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CarDialog w;
    w.show();
    return a.exec();
}
