#include "mainwindow.h"
#include <QApplication>
#include "mainwin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    mainwin *obj = new mainwin(&w, &w);
    w.setCentralWidget (obj);
    w.show();

    return a.exec();
}
