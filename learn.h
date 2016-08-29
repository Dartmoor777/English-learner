#ifndef LEARN_H
#define LEARN_H

#include <QtWidgets>

namespace Ui {
class learn;
}

class learn : public QWidget
{
    Q_OBJECT

public:
    explicit learn(QWidget *parent = 0, QMainWindow *win= 0, int but = 0);
    ~learn();

private:
    QMainWindow *win;
    Ui::learn *ui;
    void word_trans();
    void trans_word();
    void buttons();
    void listen();
};

#endif // LEARN_H
