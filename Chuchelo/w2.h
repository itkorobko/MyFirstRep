#ifndef W2_H
#define W2_H

#include <QMainWindow>
//#include "w1.h"
//#include "w3.h"
namespace Ui {
class W2;
}

class W2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit W2(QWidget *parent = nullptr);

    ~W2();
signals:
    void back_to_w3();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::W2 *ui;
};

#endif // W2_H
