#include "study.h"
#include "ui_study.h"
#include "learn.h"

study::study(QWidget *parent, QMainWindow *win,QMap<QString, QString> *words) :
    QWidget(parent),
    ui(new Ui::study)
{
    ui->setupUi(this);
    this->win=win;
    this->words = words;
    ui->lcdNumber->display (words->count ());
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
    if(words->size ()<5){
        QMessageBox box;
        box.warning (this, "Warning", "You have to have at least 5 words!");
        return;
    }
    learn *obj = new learn(win, win, 1, words);
    win->setCentralWidget (obj);
}

void study::on_pushButton_2_clicked()
{
    if(words->size ()<5){
        QMessageBox box;
        box.warning (this, "Warning", "You have to have at least 5 words!");
        return;
    }
    learn *obj = new learn(win, win, 2, words);
    win->setCentralWidget (obj);

}
