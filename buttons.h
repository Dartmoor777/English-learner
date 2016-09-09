#ifndef BUTTONS_H
#define BUTTONS_H

#include<QtWidgets>

namespace Ui {
class buttons;
}

class buttons : public QWidget
{
    Q_OBJECT

public:
    explicit buttons(QWidget *parent = 0, QMainWindow *win = 0, QMap<QString, QString> *words = 0, QList<int> *list=0);
    ~buttons();

private slots:
    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

private:
    QList<int> list;
    QMap<QString, QString> *words;
    QMainWindow *win;
    void disable();
    void setButton(QString name, int pos);
    Ui::buttons *ui;
};

#endif // BUTTONS_H
