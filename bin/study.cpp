#include "lib/study.h"
#include "ui_study.h"
#include "lib/learn.h"
#include "lib/buttons.h"

study::study(QWidget *parent, QMainWindow *win,QMap<QString, QString> *words) :
    QWidget(parent),
    ui(new Ui::study)
{
    ui->setupUi(this);
    this->win=win;
    this->words = words;
    ui->lcdNumber->display (words->count ());
    ui->pushButton_4->setHidden (true);
}

study::~study()
{
    delete ui;
}

void study::on_pushButton_6_clicked()
{
    mainwin *obj = new mainwin(win, win, words);
    win->setCentralWidget (obj);
}

void study::on_pushButton_clicked()
{
    if(check())return;
    learn *obj = new learn(this, win, 1, words);
    win->setCentralWidget (obj);
}

void study::on_pushButton_2_clicked()
{
    if(check())return;
    learn *obj = new learn(this, win, 2, words);
    win->setCentralWidget (obj);

}

void study::on_pushButton_3_clicked(){
    if(check())return;
    QList<int> list;
    buttons *obj = new buttons(this, win, words, list);
    win->setCentralWidget (obj);
}

void study::on_pushButton_5_clicked()
{
    if(check())return;
    learn *obj = new learn(this, win, 3, words);
    win->setCentralWidget (obj);
}

bool study::check(){
    if(words->size ()<5){
        QMessageBox box;
        box.warning (this, "Warning", "You have to have at least 5 words!");
        return true;
    }else return false;
}

