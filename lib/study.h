#ifndef STUDY_H
#define STUDY_H

#include "QtWidgets"
#include "mainwin.h"


#define NEXT_WORD "наступне"
#define DUNNO_WORD "не знаю"


namespace Ui {
class study;
}

class study : public QWidget
{
    Q_OBJECT

public:
    explicit study(QWidget *parent = 0, QMainWindow *win = 0, QMap<QString, QString> *words = 0);

    ~study();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    bool check();
    Ui::study *ui;
    QMap<QString, QString> *words;
    QMainWindow *win;
};

#endif // STUDY_H
