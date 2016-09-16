#include "buttons.h"
#include "ui_buttons.h"
#include "study.h"

buttons::buttons(QWidget *parent, QMainWindow *win, QMap<QString, QString> *words, QList<int> list) :
    QWidget(parent),
    ui(new Ui::buttons)
{
    ui->setupUi(this);
    remove= false;
    current="";
    origin = ui->label_2->palette ();
    this->words=words;
    this->win=win;
    if(list.isEmpty ()){
        int size = words->count ();
        while(this->list.count ()!=5){
        int buf = qrand() % size;
        if(!this->list.contains (buf))this->list.append (buf);
        }
    }else{
        this->list=list;
        remove=true;
    }
    on_pushButton_32_clicked ();
}

buttons::~buttons()
{
    delete ui;
}

void buttons::on_pushButton_31_clicked()
{
    study *obj = new study(win, win, words);
    win->setCentralWidget (obj);
    return;
}

void buttons::on_pushButton_32_clicked(){
        if((ui->label_2->isEnabled ()) && (!ui->label->text ().isEmpty ())){
            ui->label_2->setText (current);
            ui->label_2->setDisabled (true);
            ui->pushButton_32->setText ("Next");
            disable();
            return;
        }
        if(list.isEmpty ()){
            qDebug() << forRemove;
            if(remove)for(int n=0;n<5;n++)words->remove (forRemove.at (n));
             on_pushButton_31_clicked ();
            return;
        }
        ui->pushButton_32->setText ("Don't know");
        ui->label_2->setText ("");
        ui->label_2->setDisabled (false);
        disable();
        QMap<QString, QString>::iterator it = words->begin ();
        it+=list.first ();
        list.removeFirst ();
        ui->label->setText (it.value ());
        QString word = it.key ();
        current = word;
        if(remove)forRemove.append (word);
        random.clear();
        for(;!word.isEmpty();){
            int rand = (qrand()%30+1);
            if(!random.contains (rand)){
                setButton (word.right (1), rand);
                word.chop (1);
                random.append (rand);
            }
        }
        ui->pushButton_32->setFocus ();
        setFocus();
        anable();
        return;
}

void buttons::setButton (QString name, int pos){
    getButton (pos)->setHidden (false);
    getButton (pos)->setText (name);
}

void buttons::disable(){
    for(int n =1;n<=30;n++)getButton (n)->setHidden(true);
}

void buttons::anable(){
    for(int n=1;n<=30;n++)getButton (n)->setDisabled (false);
}


void buttons::on_pushButton_clicked(){
    installButton (ui->pushButton);
}

void buttons::on_pushButton_2_clicked()
{
    installButton(ui->pushButton_2);
}

void buttons::on_pushButton_3_clicked()
{
    installButton(ui->pushButton_3);

}

void buttons::on_pushButton_5_clicked()
{
    installButton(ui->pushButton_5);
}

void buttons::on_pushButton_6_clicked()
{
    installButton(ui->pushButton_6);

}

void buttons::on_pushButton_4_clicked()
{
    installButton(ui->pushButton_4);

}

void buttons::on_pushButton_8_clicked()
{
    installButton(ui->pushButton_8);

}

void buttons::on_pushButton_9_clicked()
{
    installButton(ui->pushButton_9);
}

void buttons::on_pushButton_7_clicked()
{
    installButton(ui->pushButton_7);
}

void buttons::on_pushButton_10_clicked()
{
    installButton(ui->pushButton_10);
}

void buttons::on_pushButton_17_clicked()
{
    installButton(ui->pushButton_17);
}

void buttons::on_pushButton_20_clicked()
{
    installButton(ui->pushButton_20);
}

void buttons::on_pushButton_14_clicked()
{
    installButton(ui->pushButton_14);
}

void buttons::on_pushButton_16_clicked()
{
    installButton(ui->pushButton_16);
}

void buttons::on_pushButton_13_clicked()
{
    installButton(ui->pushButton_13);
}

void buttons::on_pushButton_15_clicked()
{
    installButton(ui->pushButton_15);
}

void buttons::on_pushButton_19_clicked()
{
    installButton(ui->pushButton_19);
}

void buttons::on_pushButton_12_clicked()
{
    installButton(ui->pushButton_12);
}

void buttons::on_pushButton_11_clicked()
{
    installButton(ui->pushButton_11);
}

void buttons::on_pushButton_18_clicked()
{
    installButton(ui->pushButton_18);
}

void buttons::on_pushButton_27_clicked()
{
    installButton(ui->pushButton_27);
}

void buttons::on_pushButton_30_clicked()
{
    installButton(ui->pushButton_30);
}

void buttons::on_pushButton_24_clicked()
{
    installButton(ui->pushButton_24);
}

void buttons::on_pushButton_26_clicked()
{
    installButton(ui->pushButton_26);
}

void buttons::on_pushButton_23_clicked()
{
    installButton(ui->pushButton_23);
}

void buttons::on_pushButton_25_clicked()
{
    installButton(ui->pushButton_25);
}

void buttons::on_pushButton_29_clicked()
{
    installButton(ui->pushButton_29);
}

void buttons::on_pushButton_22_clicked()
{
    installButton(ui->pushButton_22);
}

void buttons::on_pushButton_21_clicked()
{
    installButton(ui->pushButton_21);
}

void buttons::on_pushButton_28_clicked()
{
    installButton(ui->pushButton_28);
}

bool buttons::check (QString name){
    QString text = ui->label_2->text()+name;
    int size = text.size();
    QString proof = current.left (size);
    if(current==text){
        ui->label_2->setDisabled (true);
        ui->pushButton_32->setText ("Next");
        return false;
    }
    ////
    if(proof==text){
        return false;
    }else{
        return true;
    }
}


void buttons::installButton (QPushButton *button){
    QString text = ui->label_2->text ();
    if(check (button->text ())){
        button->setDisabled (true);
        return;
    }
    anable();
    text.append (button->text ());
    ui->label_2->setText (text);
    button->setHidden(true);

}

QPushButton *buttons::getButton(int n, bool skip){
    switch(n){
    case 1:
        if (!skip)return ui->pushButton;
        on_pushButton_clicked();
 return 0;
    case 2:
        if(!skip)return ui->pushButton_2;
        on_pushButton_2_clicked();
 return 0;
    case 3:
        if(!skip)return ui->pushButton_3;
        on_pushButton_3_clicked();
 return 0;
    case 4:
        if(!skip)return ui->pushButton_4;
        on_pushButton_4_clicked();
 return 0;
    case 5:
        if(!skip)return ui->pushButton_5;
        on_pushButton_5_clicked();
 return 0;
    case 6:
        if(!skip)return ui->pushButton_6;
        on_pushButton_6_clicked();
 return 0;
    case 7:
        if(!skip)return ui->pushButton_7;
        on_pushButton_7_clicked();
 return 0;
    case 8:
        if(!skip)return ui->pushButton_8;
        on_pushButton_8_clicked();
 return 0;
    case 9:
        if(!skip)return ui->pushButton_9;
        on_pushButton_9_clicked();
 return 0;
    case 10:
        if(!skip)return ui->pushButton_10;
        on_pushButton_10_clicked();
 return 0;
    case 11:
        if(!skip)return ui->pushButton_11;
        on_pushButton_11_clicked();
 return 0;
    case 12:
        if(!skip)return ui->pushButton_12;
        on_pushButton_12_clicked();
 return 0;
    case 13:
        if(!skip)return ui->pushButton_13;
        on_pushButton_13_clicked();
 return 0;
    case 14:
        if(!skip)return ui->pushButton_14;
        on_pushButton_14_clicked();
 return 0;
    case 15:
        if(!skip)return ui->pushButton_15;
        on_pushButton_15_clicked();
 return 0;
    case 16:
        if(!skip)return ui->pushButton_16;
        on_pushButton_16_clicked();
 return 0;
    case 17:
        if(!skip)return ui->pushButton_17;
        on_pushButton_17_clicked();
 return 0;
    case 18:
        if(!skip)return ui->pushButton_18;
        on_pushButton_18_clicked();
 return 0;
    case 19:
        if(!skip)return ui->pushButton_19;
        on_pushButton_19_clicked();
 return 0;
    case 20:
        if(!skip)return ui->pushButton_20;
        on_pushButton_20_clicked();
 return 0;
    case 21:
        if(!skip)return ui->pushButton_21;
        on_pushButton_21_clicked();
 return 0;
    case 22:
        if(!skip)return ui->pushButton_22;
        on_pushButton_22_clicked();
 return 0;
    case 23:
        if(!skip)return ui->pushButton_23;
        on_pushButton_23_clicked();
 return 0;
    case 24:
        if(!skip)return ui->pushButton_24;
        on_pushButton_24_clicked();
 return 0;
    case 25:
        if(!skip)return ui->pushButton_25;
        on_pushButton_25_clicked();
 return 0;
    case 26:
        if(!skip)return ui->pushButton_26;
        on_pushButton_26_clicked();
 return 0;
    case 27:
        if(!skip)return ui->pushButton_27;
        on_pushButton_27_clicked();
 return 0;
    case 28:
        if(!skip)return ui->pushButton_28;
        on_pushButton_28_clicked();
 return 0;
    case 29:
        if(!skip)return ui->pushButton_29;
        on_pushButton_29_clicked();
 return 0;
    case 30:
        if(!skip)return ui->pushButton_30;
        on_pushButton_30_clicked();
 return 0;
    default:
        qFatal("You should use numbers in rage of 30!");
    }
}

void buttons::keyPressEvent (QKeyEvent *e){
    for(int n=0;n<random.size ();n++){
        QPushButton *button=getButton (random[n]);
        if(((QString)e->key ())==(button->text ().toUpper ())){
            getButton (random[n], true);
            if(button->isEnabled ())random.removeAt (n);
            else continue;
            break;
        }
    }
    if(e->key () == Qt::Key_Return)on_pushButton_32_clicked ();
}
