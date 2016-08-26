#include "mainwin.h"
#include "ui_mainwin.h"

mainwin::mainwin(QWidget *parent, QMainWindow *win) :
    QWidget(parent),
    ui(new Ui::mainwin)
{
    ui->setupUi(this);
    this->win=win;
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
        change = words.size ();
    }
    base.close ();
    connect(win, SIGNAL(destroyed()), this, SLOT(overwrite()));
}

mainwin::~mainwin()
{
    delete ui;
}

void mainwin::on_pushButton_clicked()
{
   add *obj = new add(win, &words);
   obj->setModal (true);
   obj->show ();
}

void mainwin::on_pushButton_2_clicked()
{
    study *obj = new study(win, win);
    win->setCentralWidget (obj);
}

void mainwin::overwrite (){
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
}
