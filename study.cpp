#include "study.h"
#include "ui_study.h"

study::study(QWidget *parent, QMainWindow *win) :
    QWidget(parent),
    ui(new Ui::study)
{
    ui->setupUi(this);
    this->win=win;
}

study::~study()
{
    delete ui;
}

void study::on_pushButton_6_clicked()
{
    mainwin *obj = new mainwin(win, win);
    win->setCentralWidget (obj);
}
