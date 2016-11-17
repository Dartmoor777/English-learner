#ifndef MAINWIN_H
#define MAINWIN_H

#include <QtWidgets>
#include "add.h"
#include "study.h"
#include <QMap>
#include <QFile>
#include <QTextStream>

namespace Ui {
class mainwin;
}

class mainwin : public QWidget
{
    Q_OBJECT

public:
    explicit mainwin(QWidget *parent = 0, QMainWindow *win = 0, QMap<QString, QString> *words = 0);
    ~mainwin();
//public slots:
    //void overwrite();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    QMap<QString, QString> *words;
    Ui::mainwin *ui;
    QMainWindow *win;
    //int change;
};

#endif // MAINWIN_H
