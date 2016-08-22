#ifndef STUDY_H
#define STUDY_H

#include "QtWidgets"
#include "mainwin.h"

namespace Ui {
class study;
}

class study : public QWidget
{
    Q_OBJECT

public:
    explicit study(QWidget *parent = 0, QMainWindow *win = 0);

    ~study();

private slots:
    void on_pushButton_6_clicked();

private:
    Ui::study *ui;
    QMainWindow *win;
};

#endif // STUDY_H
