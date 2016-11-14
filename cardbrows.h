#ifndef CARDBROWS_H
#define CARDBROWS_H

#include <QDialog>

namespace Ui {
class cardBrows;
}

class cardBrows : public QDialog
{
    Q_OBJECT

public:
    explicit cardBrows(QWidget *parent = 0);
    ~cardBrows();

private:
    Ui::cardBrows *ui;
};

#endif // CARDBROWS_H
