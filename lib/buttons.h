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
    buttons(QWidget *parent, QMainWindow *win, QMap<QString, QString> *words, QList<int> list);
    ~buttons();
private slots:
    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_28_clicked();

    //void on_label_2_windowTitleChanged(const QString &title);

private:
    QList<int> list;
    QMap<QString, QString> *words;
    QMainWindow *win;
    QString current;
    void disable();
    void anable();
    void setButton(QString name, int pos);
    void installButton(QPushButton *button);
    bool check(QString name);
    bool remove;
    void keyPressEvent (QKeyEvent *e);
    QList<int> random;
    QList<QString> forRemove;
    QPushButton *getButton(int n, bool skip = false);
    Ui::buttons *ui;
    QPalette origin;
};

#endif // BUTTONS_H
