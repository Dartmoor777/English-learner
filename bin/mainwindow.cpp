#include "lib/mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "lib/cardbrows.h"

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
        QStringList browsedWords;

        while(!stream.atEnd ()){
            browsedWords = stream.readLine().split(';');
            if (browsedWords.count() != WORDS_AMOUNT) {
                continue;
            }
            words.insert (browsedWords.at(WORD),
                         browsedWords.at(TRANSLATION));
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
    box.information (this, "Допомога", "Програма має всього дві кнопки," "\n"
                                       "1. \"Додати\" - додає слово на тренування." "\n"
                                       "2. \"Тренування\" - тренування доданих слів." "\n""\n"

                                       "Кнопка \"додати\" — відкриває вікно," "\n"
                                       "де користувачу треба ввести слово та переклад.""\n"
                                       "Максимальна довжина слова 30 символів.""\n"
                                       "Кнопка \"Тренування\" — відкриває меню можливих тренувань.""\n""\n"

                                        "Вікно тренувань має наступні функції:""\n"
                                       "\"Слово - Переклад\" — треба з запропонованих варіантів""\n"
                                       "вибрати правильний переклад.""\n"
                                       "\"Переклад - Слово\" —  Вправа аналогічна до попередньої,""\n"
                                       "з тією різницею, що треба вибрати правильне слово.""\n"
                                       "\"Куб - Слово\" — тренування полягає в тому,""\n"
                                       "що слово розбивається на \"куби\" і з цих кубів треба знову зібрати слово.""\n"
                                       "В якості підказки присутній переклад слова, яке має бути зібраним.""\n"
                                       "\"Мозковий штурм\" — вправа \"все і відразу\",""\n"
                                       "включає в себе три вище перечислені вправи""\n"
                                       "та перед їх початком короткий перегляд слів.""\n""\n"

                                       "Для запуску будь-якої з вправ треба додати мінімум 5 слів.""\n"
                                       "Додані слова мають два стани: \"вивчене\" та \"вивчається\".""\n"
                                       "Слово вважається вивченим тільки після вправи \"Мозковий штурм\".""\n"
                                       "Перегляд слів та їх редагування/видалення можна здійснити в""\n"
                                       "\"Налаштування -> Перегляд слів\".""\n"
                                       "Крім слова та перекладу є можливість редагувати і стан слова,""\n"
                                       "якщо є бажання повторити вивчене знову."
                     );
    box.show ();
}

void MainWindow::on_action_Program_triggered()
{
    QMessageBox box;
    box.information (this, "Про програму", "Розробник цієї програми студент  41-РПЗ групи,""\n"
                                           "Київського державного коледжу туризму та готельного господарства" "\n"
                                            "Путін Олександр Геннадійович."
                                    );
    box.show ();
}
