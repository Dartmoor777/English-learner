#include "lib/repeat.h"
#include "ui_repeat.h"
#include "lib/mainwin.h"

repeat::repeat(QWidget *parent, QMainWindow *win, QMap<QString, QString> *words) :
    QWidget(parent),
    ui(new Ui::repeat)
{
    this->words=words;
    this->win = win;
    ui->setupUi(this);
}

repeat::~repeat()
{
    delete ui;
}

void repeat::on_pushButton_clicked()
{
    mainwin *obj = new mainwin(this, win, words);
    win->setCentralWidget (obj);
}
