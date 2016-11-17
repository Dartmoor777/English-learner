#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "cardbrows.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    base.setFileName ("base.txt");
    if(!base.open (QIODevice::ReadOnly | QIODevice::Text)){
        base.open(QIODevice::Truncate| QIODevice::Text);
        base.close ();
    }else{
        QTextStream stream(&base);
        QString boof;
        while(!stream.atEnd ()){
            stream >> boof;
            words.insert (boof.section(';', 0, 0), boof.section (';',1,1));
        }
        QMap<QString, QString>::iterator it = words.begin ();
        if(it.key ()=="")words.erase (it);
        change = words.size ();
    }
    base.close ();
}

MainWindow::~MainWindow()
{
    if (words.isEmpty ())return;
    if(change== words.size())return;
    QMap<QString, QString>::const_iterator it = words.constBegin ();
    base.open (QIODevice::Truncate|QIODevice::WriteOnly|QIODevice::Text);
    QTextStream stream(&base);
    while(it != words.constEnd ()){
    stream << it.key () << ';' << it.value();
    if((it+1) !=words.constEnd())stream << endl;
    it++;
    }
    base.close();
    delete ui;
}

void MainWindow::on_actionBrowse_cards_triggered()
{
    cardBrows *obj = new cardBrows(this, &words);
    obj->setModal (true);
    obj->show ();
}

void MainWindow::on_action_Help_triggered()
{
    QMessageBox box;
    box.information (this, "Help", "I hope you will find out how it works :)");
    box.show ();
}

void MainWindow::on_action_Program_triggered()
{
    QMessageBox box;
    box.information (this, "About", "This program was created by Alex Putin.\n"
																																								"If you want to support me,\n"
                     "just make some donation or suggest your help\n"
                                    "to my project :)");
    box.show ();
}
