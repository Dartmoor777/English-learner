#include "cardbrows.h"
#include "ui_cardbrows.h"

cardBrows::cardBrows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cardBrows)
{
    ui->setupUi(this);
}

cardBrows::~cardBrows()
{
    delete ui;
}
