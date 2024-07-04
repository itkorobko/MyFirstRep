#ifndef REKORDS_H
#define REKORDS_H
#include "spisok_recordov.h"
#include <QMainWindow>
#include"w1.h"

namespace Ui {
class Rekords;
}

class Rekords : public QMainWindow
{
    Q_OBJECT

public:
    explicit Rekords(QWidget *parent = nullptr);
    ~Rekords();
private slots:
    void addRecord();

    void on_pushButton_clicked();
signals:
    void back_to_w3();
private:
    Ui::Rekords *ui;
    W1* win1;


};

#endif // REKORDS_H
