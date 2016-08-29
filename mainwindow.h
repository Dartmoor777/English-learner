#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QMap<QString, QString> words;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QFile base;
    Ui::MainWindow *ui;
    int change;
};

#endif // MAINWINDOW_H
