#include "mainwin.h"
#include "ui_mainwin.h"

mainwin::mainwin(QWidget *parent, QMainWindow *win) :
    QWidget(parent),
    ui(new Ui::mainwin)
{
    ui->setupUi(this);
    this->win=win;
}

mainwin::~mainwin()
{
    delete ui;
}

void mainwin::on_pushButton_clicked()
{
   add *obj = new add(win);
   obj->setModal (true);
   obj->show ();
}

void mainwin::on_pushButton_2_clicked()
{
    study *obj = new study(win, win);
    win->setCentralWidget (obj);
}
