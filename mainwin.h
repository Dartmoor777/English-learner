#ifndef MAINWIN_H
#define MAINWIN_H

#include <QtWidgets>
#include "add.h"
#include "study.h"

namespace Ui {
class mainwin;
}

class mainwin : public QWidget
{
    Q_OBJECT

public:
    explicit mainwin(QWidget *parent = 0, QMainWindow *win = 0);
    ~mainwin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::mainwin *ui;
    QMainWindow *win;
};

#endif // MAINWIN_H
