#ifndef REPEAT_H
#define REPEAT_H

#include <QtWidgets>

namespace Ui {
class repeat;
}

class repeat : public QWidget
{
    Q_OBJECT

public:
    explicit repeat(QWidget *parent = 0, QMainWindow *win = 0, QMap<QString, QString> *words = 0);
    ~repeat();

private slots:
    void on_pushButton_clicked();

private:
    QMap<QString, QString> *words;
    QMainWindow *win;
    Ui::repeat *ui;
};

#endif // REPEAT_H
