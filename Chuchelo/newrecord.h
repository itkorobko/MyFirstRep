#ifndef NEWRECORD_H
#define NEWRECORD_H

#include <QMainWindow>

namespace Ui {
class NewRecord;
}

class NewRecord : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewRecord(QWidget *parent = nullptr);
    ~NewRecord();
    int m;
    int sec;

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewRecord *ui;

};

#endif // NEWRECORD_H
