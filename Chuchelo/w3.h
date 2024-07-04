#ifndef W3_H
#define W3_H

#include <QMainWindow>
#include "w1.h"
#include "w2.h"
#include"rekords.h"
namespace Ui {
class W3;
}

class W3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit W3(QWidget *parent = nullptr);

    ~W3();
signals:

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::W3 *ui;
    W1* win1;
    W2* win2;
    Rekords* rw;

};

#endif // W3_H
