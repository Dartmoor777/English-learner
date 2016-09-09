#include "buttons.h"
#include "ui_buttons.h"
#include "study.h"

buttons::buttons(QWidget *parent, QMainWindow *win, QMap<QString, QString> *words, QList<int> *list) :
    QWidget(parent),
    ui(new Ui::buttons)
{
    ui->setupUi(this);
    this->words=words;
    this->win=win;
    if(!list){
        int size = words->count ();
        while(this->list.count ()!=5){
        int buf = qrand() % size;
        if(!this->list.contains (buf))this->list.append (buf);
        }
    }else this->list=*list;
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
}

void buttons::on_pushButton_32_clicked(){
        if(list.isEmpty ()){
            on_pushButton_31_clicked ();
            return;
        }
        disable();
        QMap<QString, QString>::iterator it = words->begin ();
        it+=list.first ();
        list.removeFirst ();
        ui->label->setText (it.value ());
        QString word = it.key ();

        for(int pos =1;!word.isEmpty();){
            int rand = (qrand()%30+1);
            setButton (word.right (1), rand);
            word.chop (1);
        }
        return;
}

void buttons::setButton (QString name, int pos){
    switch(pos){
    case 1:
        ui->pushButton->setHidden (false);
        ui->pushButton->setText (name);
        break;
    case 2:
        ui->pushButton_2->setHidden (false);
        ui->pushButton_2->setText (name);
        break;
    case 3:
        ui->pushButton_3->setHidden (false);
        ui->pushButton_3->setText (name);
        break;
    case 4:
        ui->pushButton_4->setHidden (false);
        ui->pushButton_4->setText (name);
        break;
    case 5:
        ui->pushButton_5->setHidden (false);
        ui->pushButton_5->setText (name);
        break;
    case 6:
        ui->pushButton_6->setHidden (false);
        ui->pushButton_6->setText (name);
        break;
    case 7:
        ui->pushButton_7->setHidden (false);
        ui->pushButton_7->setText (name);
        break;
    case 8:
        ui->pushButton_8->setHidden (false);
        ui->pushButton_8->setText (name);
        break;
    case 9:
        ui->pushButton_9->setHidden (false);
        ui->pushButton_9->setText (name);
        break;
    case 10:
        ui->pushButton_10->setHidden (false);
        ui->pushButton_10->setText (name);
        break;
    case 11:
        ui->pushButton_11->setHidden (false);
        ui->pushButton_11->setText (name);
        break;
    case 12:
        ui->pushButton_12->setHidden (false);
        ui->pushButton_12->setText (name);
        break;
    case 13:
        ui->pushButton_13->setHidden (false);
        ui->pushButton_13->setText (name);
        break;
    case 14:
        ui->pushButton_14->setHidden (false);
        ui->pushButton_14->setText (name);
        break;
    case 15:
        ui->pushButton_15->setHidden (false);
        ui->pushButton_15->setText (name);
        break;
    case 16:
        ui->pushButton_16->setHidden (false);
        ui->pushButton_16->setText (name);
        break;
    case 17:
        ui->pushButton_17->setHidden (false);
        ui->pushButton_17->setText (name);
        break;
    case 18:
        ui->pushButton_18->setHidden (false);
        ui->pushButton_18->setText (name);
        break;
    case 19:
        ui->pushButton_19->setHidden (false);
        ui->pushButton_19->setText (name);
        break;
    case 20:
        ui->pushButton_20->setHidden (false);
        ui->pushButton_20->setText (name);
        break;
    case 21:
        ui->pushButton_21->setHidden (false);
        ui->pushButton_21->setText (name);
        break;
    case 22:
        ui->pushButton_22->setHidden (false);
        ui->pushButton_22->setText (name);
        break;
    case 23:
        ui->pushButton_23->setHidden (false);
        ui->pushButton_23->setText (name);
        break;
    case 24:
        ui->pushButton_24->setHidden (false);
        ui->pushButton_24->setText (name);
        break;
    case 25:
        ui->pushButton_25->setHidden (false);
        ui->pushButton_25->setText (name);
        break;
    case 26:
        ui->pushButton_26->setHidden (false);
        ui->pushButton_26->setText (name);
        break;
    case 27:
        ui->pushButton_27->setHidden (false);
        ui->pushButton_27->setText (name);
        break;
    case 28:
        ui->pushButton_28->setHidden (false);
        ui->pushButton_28->setText (name);
        break;
    case 29:
        ui->pushButton_29->setHidden (false);
        ui->pushButton_29->setText (name);
        break;
    case 30:
        ui->pushButton_30->setHidden (false);
        ui->pushButton_30->setText (name);
        break;
    default:
        qDebug()<< "Holly shit";
    }
}

void buttons::disable(){
    ui->pushButton->setHidden (true);
    ui->pushButton_2->setHidden (true);
    ui->pushButton_3->setHidden (true);
    ui->pushButton_4->setHidden (true);
    ui->pushButton_5->setHidden (true);
    ui->pushButton_6->setHidden (true);
    ui->pushButton_7->setHidden (true);
    ui->pushButton_8->setHidden (true);
    ui->pushButton_9->setHidden (true);
    ui->pushButton_10->setHidden (true);
    ui->pushButton_11->setHidden (true);
    ui->pushButton_12->setHidden (true);
    ui->pushButton_13->setHidden (true);
    ui->pushButton_14->setHidden (true);
    ui->pushButton_15->setHidden (true);
    ui->pushButton_16->setHidden (true);
    ui->pushButton_17->setHidden (true);
    ui->pushButton_18->setHidden (true);
    ui->pushButton_19->setHidden (true);
    ui->pushButton_20->setHidden (true);
    ui->pushButton_21->setHidden (true);
    ui->pushButton_22->setHidden (true);
    ui->pushButton_23->setHidden (true);
    ui->pushButton_24->setHidden (true);
    ui->pushButton_25->setHidden (true);
    ui->pushButton_26->setHidden (true);
    ui->pushButton_27->setHidden (true);
    ui->pushButton_28->setHidden (true);
    ui->pushButton_29->setHidden (true);
    ui->pushButton_30->setHidden (true);
}
