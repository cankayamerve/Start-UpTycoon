#include <QApplication>
#include "firstscreen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstScreen fScreen;
    fScreen.setModal(true);
    fScreen.exec();
    return a.exec();
}
