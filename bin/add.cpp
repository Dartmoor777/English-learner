#include "lib/add.h"
#include "ui_add.h"

add::add(QWidget *parent, QMap<QString, QString> *words) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    this->words=words;
    palette=ui->lineEdit->palette ();
    // parsing
    base.setFileName ("anki.txt");
    if(!base.open (QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }else{
        QTextStream stream(&base);
        QString boof;
        while(!stream.atEnd ()){
            stream >> boof;
            anki.insert (boof.section(';', 0, 0), boof.section (';',1,1));
        }
        QMap<QString, QString>::iterator it = anki.begin ();
        if(it.key ()=="")anki.erase (it);
        change = anki.size ();
    }
    base.close ();
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
    if(word!="" && trans!=""){
        words->insert(word, trans);
        anki.insert (word, trans);
    }
    else box.warning (this, "Warning", "There is should be word and translation!");
    ui->lineEdit->setText ("");
    ui->lineEdit_2->setText ("");
}


void add::on_lineEdit_textEdited(const QString &arg1)
{
    if ((anki.contains (arg1)) || (arg1.size () > 30)){
    QColor red;
    QPalette pal = palette;
    red.setNamedColor ("red");
    pal.setColor (QPalette::Text, red);
    ui->lineEdit->setPalette (pal);
    ui->pushButton->setDisabled (true);
    }else {
        ui->lineEdit->setPalette (palette);
        ui->pushButton->setDisabled (false);
    }
}


void add::on_add_finished()
{
    if (anki.isEmpty ())return;
    if(change== anki.size())return;
    QMap<QString, QString>::const_iterator it = anki.constBegin ();
    base.open (QIODevice::Truncate|QIODevice::WriteOnly|QIODevice::Text);
    QTextStream stream(&base);
    while(it != anki.constEnd ()){
    stream << it.key () << ';' << it.value();
    if((it+1) !=anki.constEnd())stream << endl;
    it++;
    }
    base.close();
}
