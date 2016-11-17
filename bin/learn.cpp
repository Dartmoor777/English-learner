#include "lib/learn.h"
#include "ui_learn.h"
#include "lib/buttons.h"

learn::learn(QWidget *parent, QMainWindow *win, int but, QMap<QString, QString> *words) :
    QWidget(parent),
    ui(new Ui::learn)
{
    ui->setupUi(this);
    ui->label_9->setHidden (true);
    ui->line->setHidden (true);
    for(int n=1;n<=5;n++)connect(getButton (n), SIGNAL(clicked()), this, SLOT(disable()));
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
        introduce();
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
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(next()), Qt::UniqueConnection);
    fill();
    reverse = true;
    next();
    return;
}

void learn::next(){
        ui->pushButton_7->setText ("Don't know");
        if((ui->pushButton->isEnabled ()) && (!ui->pushButton->text().isEmpty ())){
            disable();
            return;
        }
        if(list.isEmpty ()){
            if(ui->label_9->text ()=="f49!VkW"){
                buttons *obj = new buttons(this, win, words, immortalList);
                win->setCentralWidget (obj);
                return;
            }
            if(!ui->label_9->text ().isEmpty ()){
                ui->label_9->setText ("f49!VkW");
                trans_word ();
                return;
            }
            else on_pushButton_6_clicked ();
            return;
        }
        ui->pushButton->setFocus ();
        setFocus ();
        for(int n=1;n<=5;n++){
            getButton (n)->setDisabled (false);
            getButton (n)->setPalette (pal);
        }
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
        for(int n=1;n<=5;n++){
            if(answer!=n){
                getButton (n)->setText (rand.first ());
                rand.removeFirst ();
            }else{
                getButton (n)->setText(textbut);
                getButton (n)->setPalette (palette_change());
            }
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
    for(int n=1;n<=5;n++)getButton (n)->setDisabled (true);
    ui->pushButton_7->setText ("Next");
}

void learn::trans_word (){
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(next()), Qt::UniqueConnection);
    fill();
    reverse = false;
    next();
    return;
}

void learn::introduce (){
    for(int n=1;n<=5;n++)getButton (n)->setHidden (true);
    ui->label_2->setHidden (true);
    ui->label_3->setHidden (true);
    ui->label_4->setHidden (true);
    ui->label_5->setHidden (true);
    ui->label_6->setHidden (true);
    ui->label_9->setHidden (false);
    ui->line->setHidden (false);
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(introNext()), Qt::UniqueConnection);
    fill();
    introNext ();
    return;
}
QPushButton *learn::getButton (int n){
    switch(n){
        case 1:
            return ui->pushButton;
        case 2:
            return ui->pushButton_2;
        case 3:
            return ui->pushButton_3;
        case 4:
            return ui->pushButton_4;
        case 5:
            return ui->pushButton_5;
    }
    return 0;
}

void learn::introNext (){
    if(list.isEmpty ()){
        for(int n=1;n<=5;n++)getButton (n)->setHidden (false);
        disconnect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(introNext()));
        ui->label_2->setHidden (false);
        ui->label_3->setHidden (false);
        ui->label_4->setHidden (false);
        ui->label_5->setHidden (false);
        ui->label_6->setHidden (false);
        ui->label_9->setHidden (true);
        ui->line->setHidden (true);
        word_trans ();
        return;
    }
    QMap<QString, QString> ::iterator it= words->begin ();
    it+=list.first ();
    list.removeFirst ();
    ui->label->setText (it.key ());
    ui->label_9->setText (it.value ());
}

void learn::fill (){
    int size = words->count ();
    while(immortalList.count ()!=5){
        int buf = qrand() % size;
        if(!immortalList.contains (buf))immortalList.append (buf);
    }
    list = immortalList;
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
        if((e->key () == Qt::Key_Return)&&(!ui->pushButton->isHidden ()))next();
        if((e->key () == Qt::Key_Return)&&(ui->pushButton->isHidden ()))introNext();
}
