#include "learn.h"
#include "ui_learn.h"

learn::learn(QWidget *parent, QMainWindow *win, int but) :
    QWidget(parent),
    ui(new Ui::learn)
{
    ui->setupUi(this);
    this->win = win;
    switch(but){
    case (1):
        word_trans ();
        break;
    case (2):
        trans_word ();
        break;
    case (3):
        buttons();
        break;
    case (4):
        listen();
        break;
    default:
        qDebug() << "Holly shit!";
    }
}

learn::~learn()
{
    delete ui;
}

void learn::word_trans (){
    return;
}

void learn::trans_word (){
    return;
}

void learn::buttons (){
    return;
}

void learn::listen (){
    return;
}
