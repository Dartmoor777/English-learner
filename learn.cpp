#include "learn.h"
#include "ui_learn.h"

learn::learn(QWidget *parent, QMainWindow *win, int but, QMap<QString, QString> *words) :
    QWidget(parent),
    ui(new Ui::learn)
{
    ui->setupUi(this);
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(next()), Qt::UniqueConnection);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(disable()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(disable()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(disable()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(disable()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(disable()));

    pal =ui->pushButton->palette();
    this->win = win;
    this->words=words;
    switch(but){
    case (1):
        word_trans ();
        break;
    case (2):
        trans_word ();
        break;
    case (3):
        buttons();
        break;
    case (4):
        listen();
        break;
    default:
        qDebug() << "Holly shit!";
    }
}

learn::~learn()
{
    delete ui;
}

void learn::word_trans (){
    int size = words->count ();
    while(list.count ()!=5){
        int buf = qrand() % size;
        if(!list.contains (buf))list.append (buf);
    }
    reverse = true;
    next();
    return;
}

void learn::next(){
        if(list.isEmpty ()){
            on_pushButton_6_clicked ();
            return;
        }
        ui->pushButton->setFocus ();
        ui->pushButton->setDisabled (false);
        ui->pushButton_2->setDisabled (false);
        ui->pushButton_3->setDisabled (false);
        ui->pushButton_4->setDisabled (false);
        ui->pushButton_5->setDisabled (false);
        ui->pushButton->setPalette (pal);
        ui->pushButton_2->setPalette (pal);
        ui->pushButton_3->setPalette (pal);
        ui->pushButton_4->setPalette (pal);
        ui->pushButton_5->setPalette (pal);
        QMap<QString, QString>::iterator it = words->begin ();
        int buf= list.first ();
        list.removeFirst ();
        it+=buf;
        if (reverse)ui->label->setText (it.key());
        else ui->label->setText (it.value());
        QString textbut=reverse ? it.value ():it.key ();
        int answer = qrand() % 5+1;
        QList<QString> rand;
        int t=0;
        do{
            QString boof=getrand(reverse,textbut);
            if(!rand.contains (boof)){
                rand.append (boof);
                t++;
            }
        }while(t!=4);
        if(answer!=1){
            ui->pushButton->setText(rand.first ()) ;
            rand.removeFirst ();
        }
        else {
            ui->pushButton->setText (textbut);
            ui->pushButton->setPalette (palette_change ());
        }

        if(answer!=2){
            ui->pushButton_2->setText (rand.first ());
            rand.removeFirst ();
        }
        else {
            ui->pushButton_2->setText (textbut);
            ui->pushButton_2->setPalette (palette_change ());
        }

        if(answer!=3){
            ui->pushButton_3->setText (rand.first());
                    rand.removeFirst();
        }
        else {
            ui->pushButton_3->setText (textbut);
            ui->pushButton_3->setPalette (palette_change ());
        }

        if(answer!=4){
            ui->pushButton_4->setText (rand.first());
                    rand.removeFirst();
        }
        else {
            ui->pushButton_4->setText (textbut);
            ui->pushButton_4->setPalette (palette_change ());
        }

        if(answer!=5){
            ui->pushButton_5->setText (rand.first());
                    rand.removeFirst();
        }
        else {
            ui->pushButton_5->setText (textbut);
            ui->pushButton_5->setPalette (palette_change ());
        }
        return;
}

QPalette learn::palette_change(){
     QPalette pal=this->pal;
     QColor color;
     color.setRgb (11, 201,24);
     pal.setColor(QPalette::Disabled, QPalette::Button, color);
     return pal;
}

QString learn::getrand(bool IsItKey, QString except){
    QMap<QString, QString>::iterator it;
    QString check;
    do{
    it=words->begin ();
    int rand = qrand() % (words->count ());
    it+=rand;
    check = IsItKey ? it.value() : it.key ();
    }while(check==except);
    if (IsItKey)return it.value ();
    else return it.key ();
}

void learn::disable (){
    ui->pushButton->setDisabled (true);
    ui->pushButton_2->setDisabled (true);
    ui->pushButton_3->setDisabled (true);
    ui->pushButton_4->setDisabled (true);
    ui->pushButton_5->setDisabled (true);
}

void learn::trans_word (){
    int size = words->count ();
    while(list.count ()!=5){
        int buf = qrand() % size;
        if(!list.contains (buf))list.append (buf);
    }
    reverse = false;
    next();
    return;
}

void learn::buttons (){
    return;
}

void learn::listen (){
    return;
}

void learn::on_pushButton_6_clicked()
{
    study  *obj = new study(win, win, words);
    win->setCentralWidget (obj);
}

void learn::keyPressEvent( QKeyEvent *e) {
        if((e->key()==Qt::Key_1) ||  (e->key()==Qt::Key_2) || (e->key()==Qt::Key_3) || (e->key()==Qt::Key_4 || (e->key()==Qt::Key_5))/*&& (key->type ()==QKeyEvent::KeyPress)*/){
        disable();
        }
}
