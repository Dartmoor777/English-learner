#include "lib/cardbrows.h"
#include "ui_cardbrows.h"
#include "lib/edit.h"


cardBrows::cardBrows(QWidget *parent, QMap<QString, QString> *words) :
    QDialog(parent),
    ui(new Ui::cardBrows)
{
    ui->setupUi(this);
    this->words=words;
    QTableWidgetItem *item;
    QFile base("anki.txt");
    QTextStream stream(&base);
    if(base.open (QIODevice::ReadWrite | QIODevice::Text)){
        for(int x=0, y = x;!stream.atEnd ();y++, x++){
            ui->tableWidget->setRowCount (y+1);
            QString text, boof, word, trans;
            stream >> text;
            word = text.section(';', 0, 0);
            item = new QTableWidgetItem(word);
            ui->tableWidget->setItem(y, x, item);
            boof = words->contains (word) ? "on learning" : "learned";
            item = new QTableWidgetItem(boof);
            ui->tableWidget->setItem(y, x+2, item);
            x++;
            trans = text.section(';', 1, 1);
            item = new QTableWidgetItem(trans);
            ui->tableWidget->setItem(y, x, item);
            x=-1;
            anki.insert (word, trans);
        }
        QMap<QString, QString>::iterator it = anki.begin ();
        if(it.key ()=="")anki.erase (it);
        base.close ();
    } else close();


}

cardBrows::~cardBrows()
{
    delete ui;
}

void cardBrows::on_pushButton_clicked()
{
    ui->tableWidget->removeRow (ui->tableWidget->currentRow ());
}

void cardBrows::on_pushButton_2_clicked()
{
    if(ui->tableWidget->currentRow() == -1)return;
    edit *obj = new edit(this, ui->tableWidget, ui->tableWidget->currentRow (), &anki);
    obj->setModal (true);
    obj->show ();
}

void cardBrows::on_cardBrows_finished()
{
    if (words->isEmpty ())return;
    QFile base("anki.txt");
    base.open (QIODevice::WriteOnly|QIODevice::Text);
    QTextStream stream(&base);
    words->clear ();
    for(int n = 0, size =ui->tableWidget->rowCount (); n<size;n++){
        QString word = ui->tableWidget->item (n, 0)->text ();
        QString trans = ui->tableWidget->item (n, 1)->text ();
        stream << word << ";" << trans;
        if (n!=(size-1))stream << endl;
        QString state = ui->tableWidget->item(n, 2)->text ();
        if(state == "on learning"){
            words->insert (word, trans);
        }
    }
    QMap<QString, QString>::iterator it = words->begin ();
    if(it.key ()=="")words->erase (it);
    base.close();
}
