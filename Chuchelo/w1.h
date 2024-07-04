#ifndef W1_H
#define W1_H
//#include "w3.h"
//#include "w2.h"
#include"newrecord.h"
#include <windows.h>
#include <QMainWindow>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include<QDateTime>
#include <QMouseEvent>
#include <QWidget>
#include <QLabel>
#include <QMediaPlayer>
#include<QtMultimedia>
#include<QtAudio>
namespace Ui {
class W1;
}

class W1 : public QMainWindow
{
    Q_OBJECT

public:
    void setCharakter(int a);
    explicit W1(QWidget *parent = nullptr);
    ~W1();
    //QMediaPlayer * m_player;        // Аудио плеер
    //QMediaPlaylist * m_playlist;

signals:
    void first_slot1();

private slots:

    void on_pushButton_pressed();
    void setSekundomer();

protected:
           // void updateMovement();
    void paintEvent(QPaintEvent* ) override;
    void startMovement();
    void go_Katafalk();
private:

    NewRecord*nr;
    QTimer*timer;
    int charakter=4;
    int MySeconds=0;
    int MyMinutes=0;
    QLabel* label_katafalk;
    Ui::W1 *ui;
    QPointF velocity;
    //  QTimer* movementTimer;
    QTime* startTime;
    QTime* MyCurrentTime;
    QTimer* MyTimer;
    QMediaPlayer* MP_Popal;
    QAudioOutput* MAO_Popal;
    QMediaPlayer* MP_Katafalk;
    QAudioOutput* MAO_Katafalk;
    QMediaPlayer*MP_Play_Time;
    QAudioOutput*MAO_Play_Time;
    //QtAudio* MySound;


public:

};

#endif // W1_H
