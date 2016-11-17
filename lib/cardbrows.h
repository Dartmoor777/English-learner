#ifndef CARDBROWS_H
#define CARDBROWS_H

#include <QtWidgets>

namespace Ui {
class cardBrows;
}

class cardBrows : public QDialog
{
    Q_OBJECT

public:
    explicit cardBrows(QWidget *parent = 0, QMap<QString, QString> *words = 0);
    ~cardBrows();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_cardBrows_finished();

private:
    QMap<QString, QString> *words;
    QMap<QString, QString> anki;
    Ui::cardBrows *ui;
};

#endif // CARDBROWS_H
