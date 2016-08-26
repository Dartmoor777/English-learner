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
    QMap<QString, QString> words;
    explicit mainwin(QWidget *parent = 0, QMainWindow *win = 0);
    ~mainwin();
public slots:
    void overwrite();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::mainwin *ui;
    QMainWindow *win;
    QFile base;
    int change;
};

#endif // MAINWIN_H
