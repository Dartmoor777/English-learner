#include "lib/add.h"
#include "ui_add.h"
#include "lib/cardbrows.h"

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
        QStringList browsedWords;

        while(!stream.atEnd ()){
            browsedWords = stream.readLine().split(';');
            if (browsedWords.count() != WORDS_AMOUNT) {
                continue;
            }
            anki.insert (browsedWords.at(WORD),
                         browsedWords.at(TRANSLATION));
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
    else box.warning (this, "Попередження!", "Мають бути присутніми і слово, і переклад!");
    ui->lineEdit->setText ("");
    ui->lineEdit_2->setText ("");
}


void add::on_lineEdit_textEdited(const QString &arg1)
{
    if ( checkLineEdit(ui->lineEdit, ui->lineEdit->text()) &&
    checkLineEdit(ui->lineEdit_2, ui->lineEdit_2->text()) ) {
        ui->pushButton->setDisabled (false);
    } else {
        ui->pushButton->setDisabled (true);
    }
}

void add::on_lineEdit_2_textEdited(const QString &arg1)
{
    bool line1 = checkLineEdit(ui->lineEdit, ui->lineEdit->text());
    bool line2 = checkLineEdit(ui->lineEdit_2, ui->lineEdit_2->text());
    if ( line1 && line2) {
        ui->pushButton->setDisabled (false);
    } else {
        ui->pushButton->setDisabled (true);
    }
}

bool add::checkLineEdit(QLineEdit *lineEdit, const QString &arg1)
{
    if (lineEdit == NULL) {
        qDebug() << "Failed to check null lineEdit!";
        return false;
    }

    if ((anki.contains (arg1)) || (arg1.size () > 30)){
        QColor red;
        QPalette pal = palette;
        red.setNamedColor ("red");
        pal.setColor (QPalette::Text, red);
        lineEdit->setPalette (pal);
        return false;
    } else {
        lineEdit->setPalette (palette);
        return true;
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
        if((it+1) !=anki.constEnd())
            stream << endl;
        it++;
    }

    base.close();
}
