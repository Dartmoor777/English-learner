#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

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
