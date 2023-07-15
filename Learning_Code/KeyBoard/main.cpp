#include "keyboarddialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KeyBoardDialog w;
    w.show();
    return a.exec();
}
