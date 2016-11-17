#ifndef EDIT_H
#define EDIT_H

#include <QtWidgets>

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = 0 , QTableWidget *table = 0, int row = 0, QMap<QString, QString> *anki = 0);
    ~edit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    QTableWidget *table;
    QMap<QString, QString> *anki;
    QString current;
    QPalette palette;
    int row;
    Ui::edit *ui;
};

#endif // EDIT_H
