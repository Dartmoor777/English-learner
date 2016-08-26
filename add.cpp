#include "add.h"
#include "ui_add.h"

add::add(QWidget *parent, QMap<QString, QString> *words) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    this->words=words;
}

add::~add()
{
    delete ui;
}

void add::on_pushButton_2_clicked()
{
   close();
}

void add::on_pushButton_clicked()
{
    QString word = ui->lineEdit->text ();
    QString trans = ui->lineEdit_2->text ();
    QMessageBox box;
    if(word!="" && trans!="")words->insert(word, trans);
    else if (word!="")words->insert (word, "");
    else box.warning (this, "Warnign", "There is should be some main word!");
    ui->lineEdit->setText ("");
    ui->lineEdit_2->setText ("");
}

