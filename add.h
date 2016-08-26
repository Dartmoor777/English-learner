#ifndef ADD_H
#define ADD_H

#include <QtWidgets>
#include <QMap>

namespace Ui {
class add;
}

class add : public QDialog
{
    Q_OBJECT

public:
    explicit add(QWidget *parent = 0, QMap<QString, QString> *words=0);
    ~add();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::add *ui;
    QMap<QString, QString> *words;
};

#endif // ADD_H
