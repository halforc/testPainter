#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#define SCAL 0.1;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void paintEvent(QPaintEvent* e);

    void wheelEvent(QWheelEvent* e);

    double value;

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
