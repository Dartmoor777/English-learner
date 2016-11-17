#ifndef LEARN_H
#define LEARN_H

#include <QtWidgets>
#include "study.h"

namespace Ui {
class learn;
}

class learn : public QWidget
{
    Q_OBJECT

public:
    explicit learn(QWidget *parent = 0, QMainWindow *win= 0, int but = 0, QMap<QString, QString> *words = 0);
    ~learn();
public slots:
    void next();
    void introNext();
    void disable();
private slots:
    void on_pushButton_6_clicked();

private:
    QMainWindow *win;
    QMap<QString, QString> *words;
    QString getrand(bool IsItKey, QString except);
    QList<int> list;
    QList<int> immortalList;
    Ui::learn *ui;
    void word_trans();
    void trans_word();
    void introduce();
    QPalette palette_change();
    QPalette pal;
    bool reverse;
    void keyPressEvent (QKeyEvent *e);
    void fill();
    QPushButton *getButton(int n);
};

#endif // LEARN_H
