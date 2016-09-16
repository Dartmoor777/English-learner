#include "mainwin.h"
#include "ui_mainwin.h"
#include "repeat.h"

mainwin::mainwin(QWidget *parent, QMainWindow *win, QMap<QString, QString> *words) :
    QWidget(parent),
    ui(new Ui::mainwin)
{
    ui->setupUi(this);
    this->words=words;
    this->win=win;
}

mainwin::~mainwin()
{
    delete ui;
}

void mainwin::on_pushButton_clicked()
{
   add *obj = new add(this, words);
   obj->setModal (true);
   obj->show ();
}

void mainwin::on_pushButton_2_clicked()
{
    study *obj = new study(this, win, words);
    win->setCentralWidget (obj);
}


void mainwin::on_pushButton_3_clicked()
{
   repeat *obj = new repeat(this, win, words);
    win->setCentralWidget (obj);
}
