#include "lib/edit.h"
#include "ui_edit.h"

edit::edit(QWidget *parent, QTableWidget *table, int row, QMap<QString, QString> *anki) :
    QDialog(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
    palette = ui->lineEdit->palette ();
    this->table=table;
    this->row=row;
    this->anki = anki;
    ui->lineEdit->setText (table->item (row, 0)->text ());
    current = ui->lineEdit->text ();
    ui->lineEdit_2->setText (table->item (row, 1)->text ());
    if(table->item (row,2)->text ()=="learned")ui->radioButton_2->setChecked (true);
    else ui->radioButton->setChecked (true);
}

edit::~edit()
{
    delete ui;
}

void edit::on_pushButton_clicked()
{
    close();
}

void edit::on_pushButton_2_clicked()
{
    table->item (row, 0)->setText (ui->lineEdit->text ());
    table->item (row, 1)->setText (ui->lineEdit_2->text ());
    if(ui->radioButton_2->isChecked ())table->item (row, 2)->setText ("learned");
    else table->item (row, 2)->setText ("on learning");
    on_pushButton_clicked ();
}

void edit::on_lineEdit_textEdited(const QString &arg1)
{
    if (((anki->contains (arg1)) && (arg1 != current)) || (arg1.size () > 30)){
    QColor red;
    QPalette pal = palette;
    red.setNamedColor ("red");
    pal.setColor (QPalette::Text, red);
    ui->lineEdit->setPalette (pal);
    ui->pushButton_2->setDisabled (true);
    }else {
        ui->lineEdit->setPalette (palette);
        ui->pushButton_2->setDisabled (false);
    }
}
