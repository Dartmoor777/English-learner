#include "lib/mainwindow.h"
#include <QApplication>
#include "lib/mainwin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    mainwin *obj = new mainwin(&w, &w, &w.words);
    w.setCentralWidget (obj);
    w.show();

    return a.exec();
}
