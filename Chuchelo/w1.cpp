#include "w1.h"
#include "ui_w1.h"
#include <windows.h>
#include <time.h>
#include <QWidget>
#include <QMouseEvent>
#include <QDateTime>
#include <QDebug>
#include <QTime>
#include<QTimer>
#include<QCursor>
#include<QtMultimedia>
#include<QMediaPlayer>
#include<QMediaDevices>
#include<QtAudio>
#include"hranitel.h"
#include "spisok_recordov.h"
W1::W1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::W1)
{
   // connect(win2, &W2::first_slot21, this,&W1::show);



     MyTimer = new QTimer(this);
     connect(MyTimer, SIGNAL(timeout()), this, SLOT(setSekundomer()));
     MyTimer->start(1000);


    MP_Popal=new QMediaPlayer;
    MAO_Popal=new QAudioOutput();
    MP_Popal->setAudioOutput(MAO_Popal);
    MP_Popal->setSource(QUrl("qrc:///zvukii/inecraft_death.mp3"));
    MAO_Popal->setVolume(100);


    MP_Katafalk=new QMediaPlayer;
    MAO_Katafalk=new QAudioOutput();
    MP_Katafalk->setAudioOutput(MAO_Katafalk);
    MP_Katafalk->setSource(QUrl("qrc:///zvukii/fshopen-pohoronnyj-marsh.mp3"));
    MAO_Katafalk->setVolume(100);


    MP_Play_Time=new QMediaPlayer;
    MAO_Play_Time=new QAudioOutput();
    MP_Play_Time->setAudioOutput(MAO_Play_Time);
    MP_Play_Time->setSource(QUrl("qrc:///zvukii/Puppy_Love.mp3"));
    MAO_Play_Time->setVolume(100);
    MP_Play_Time->play();



    startTime=new QTime;
    startTime->currentTime();
    MyCurrentTime=new QTime;
    MyCurrentTime->currentTime();
    //srand(time(NULL));
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    timer->start(1);
    ui->setupUi(this);
    int x=rand()%(width()-65);
    int y=rand()%(height()-80);
    setCharakter(Hranitel::pole);
    switch(charakter)
    {
    case 1:ui->pushButton->setStyleSheet("border-image: url(:/myimg/Levakov.jpg)"); break;
    case 2:ui->pushButton->setStyleSheet("border-image: url(:/myimg/Matveev.jpg)"); break;
    case 3:ui->pushButton->setStyleSheet("border-image: url(:/myimg/Karpovich.jpg)"); break;
    case 4:ui->pushButton->setStyleSheet("border-image: url(:/myimg/fotka_Zubovicha.png)"); break;
    case 5:ui->pushButton->setStyleSheet("border-image: url(:/myimg/Vereneychik.jpg)"); break;
    }
    ui->pushButton->setGeometry(x,y,45,55);
    QCursor bita(QPixmap(":/myimg/bita.png"));
    setCursor(bita);

    // m_player = new QMediaPlayer(this);          // Инициализация плеера
    //m_playlist = new QMediaPlaylist(m_player);  // Инициализация плейлиста

    //m_player->setPlaylist(m_playlist);          // Установка плейлиста в аудио плеер
    //m_playlist->addMedia(QUrl(":/kihu/inecraft_death.mp3"));
    //   srand(QTime::currentTime().msec());
    // movementTimer = new QTimer(this);
    // connect(movementTimer, &QTimer::timeout, this, &W1::paintEvent);
    label_katafalk= new QLabel(this);
    startMovement();
}
bool dFlag=false;
// void W1::paintEvent(QPaintEvent*)
// {
//     if(dFlag==false)
//     {
//         ui->label_time->setText(QString::number(MyCurrentTime->second()-startTime->second()));
//         MyCurrentTime->currentTime();
//         QPoint currentPosition = ui->pushButton->pos();
//      QPoint newPosition = currentPosition + velocity.toPoint();
//     ui->pushButton->move(newPosition);
//      if (newPosition.x() < 0 || newPosition.x() > width() - ui->pushButton->width())
//      {
//          velocity.setX(-velocity.x());
//      }
//      if (newPosition.y() < 0 || newPosition.y() > height() - ui->pushButton->height())
//      {
//          velocity.setY(-velocity.y());
//      }

//     }

//     else
//     {
//         label_katafalk->setGeometry(label_katafalk->x()-1,label_katafalk->y(),label_katafalk->width(),label_katafalk->height());
//         if(label_katafalk->x()==ui->pushButton->x()-ui->pushButton->width())
//             ui->pushButton->hide();
//         if(label_katafalk->x()==-label_katafalk->width())
//             close();
//     }
// }
void W1::paintEvent(QPaintEvent *)
{
    srand(time(NULL));


    switch(charakter)
    {
    case 1:ui->pushButton->setStyleSheet("border-image: url(:/myimg/Levakov.jpg)"); break;
    case 2:ui->pushButton->setStyleSheet("border-image: url(:/myimg/Matveev.jpg)"); break;
    case 3:ui->pushButton->setStyleSheet("border-image: url(:/myimg/Karpovich.jpg)"); break;
    case 4:ui->pushButton->setStyleSheet("border-image: url(:/myimg/fotka_Zubovicha.png)"); break;
    case 5:ui->pushButton->setStyleSheet("border-image: url(:/myimg/Veremeychik.jpg)"); break;
    }
    if(dFlag==false)
    {int rx, ry;
        rx=rand()%10-5; ry=rand()%10-5;
        if(ui->pushButton->x()>width()-ui->pushButton->width())
            ui->pushButton->setGeometry(width()-rand()%100-30-ui->pushButton->width(),ui->pushButton->y()+rand()%80-40,ui->pushButton->width(),ui->pushButton->height());
        if(ui->pushButton->x()<0)
            ui->pushButton->setGeometry(rand()%100+30+ui->pushButton->width(),ui->pushButton->y()+rand()%80-40,ui->pushButton->width(),ui->pushButton->height());
        if(ui->pushButton->y()>height()-ui->pushButton->height())
            ui->pushButton->setGeometry(ui->pushButton->x()+rand()%80-40,height()-rand()%100-30-ui->pushButton->height(),ui->pushButton->width(),ui->pushButton->height());
        if(ui->pushButton->y()<0)
            ui->pushButton->setGeometry(ui->pushButton->x()+rand()%80-40,rand()%100+30+ui->pushButton->height(),ui->pushButton->width(),ui->pushButton->height());



        if(abs(QCursor::pos().x()-ui->pushButton->x())<=200 && abs(QCursor::pos().y()-ui->pushButton->y())<=200)
            ui->pushButton->setGeometry(ui->pushButton->x()+rx,ui->pushButton->y()+ry,ui->pushButton->width(),ui->pushButton->height());
        // if(abs(QCursor::pos().y()-ui->pushButton->y())<=50)
        //     ui->pushButton->setGeometry(ui->pushButton->x()+rx,ui->pushButton->y()+ry,ui->pushButton->width(),ui->pushButton->height());
    }



    else
    {
        label_katafalk->setGeometry(label_katafalk->x()-1,label_katafalk->y(),label_katafalk->width(),label_katafalk->height());
        if(label_katafalk->x()==ui->pushButton->x()-ui->pushButton->width())
            ui->pushButton->hide();
        if(label_katafalk->x()==-label_katafalk->width())
        {

            nr=new NewRecord;
            QString s;
            QString s1;
            s=ui->label_4->text();
            bool ok;
            s1+=s[0];
            s1+=s[1];
            nr->m=s1.toInt(&ok,10);
            s1+=s[3];
            s1+=s[4];
            nr->sec=s1.toInt(&ok,10);
            nr->show();



        }
    }
}
void W1::startMovement()
{

    // Генерация случайных значений скорости
    int vx = rand() % 3+1 ;
    int vy = rand() % 3+1;

    // Генерация случайных значений направления -1 или 1
    int dx = rand() % 2 == 0 ? -1 : 1;
    int dy = rand() % 2 == 0 ? -1 : 1;

    // Установка случайной скорости и направления движения
    velocity = QPointF(vx * dx, vy * dy);

    // Запуск таймера обновления движения
    // movementTimer->start(1);
}
void W1::setCharakter(int a)
{
    charakter=a;
}
W1::~W1()
{
    delete ui;
}
void W1::go_Katafalk()
{


    MP_Play_Time->stop();
    MyTimer->stop();
    MP_Katafalk->play();
    setStyleSheet("background-color: rgb(155, 146, 146)");
    // ui->pushButton->setGeometry(ui->pushButton->x(),ui->pushButton->y(),ui->pushButton->width(),ui->pushButton->height());
    QPixmap pix(":/myimg/katafalk.png");
    // QLabel* label_katafalk= new QLabel(this);
    label_katafalk->setFixedSize(200, 110);
    label_katafalk->setGeometry(width(),ui->pushButton->y(), 200, 110);
    label_katafalk->show();
    label_katafalk->setPixmap(pix.scaled(200, 110, Qt::KeepAspectRatio));

    // while(label_katafalk->x()>=ui->pushButton->x()+ui->pushButton->width())
    //  {
    //      label_katafalk->setGeometry(label_katafalk->x()-10,label_katafalk->y(),label_katafalk->width(),label_katafalk->height());
    //  }

    //   QPoint startPos(label_katafalk->width(), ui->pushButton->y());
    //  label_katafalk->move(startPos);
    // ui->pushButton->move(label_katafalk->x() + label_katafalk->width(), ui->pushButton->y());


}




/////////////////////////////////////////////////////////////////////////////////////

int kol=0;
void W1::on_pushButton_pressed()
{
    //m_player->play();
    switch(kol)
    {
    case 0:  ui->label->hide();kol++; MP_Popal->play();break;
    case 1: ui->label_2->hide();kol++;MP_Popal->play(); break;
    case 2: ui->label_3->hide();kol++;MP_Popal->play();dFlag=true; go_Katafalk(); break;
        //default: go_Katafalk();
    }
}
void W1::setSekundomer()
{

    MySeconds++;
    if(MySeconds==60)
    {
        MySeconds=0;
        MyMinutes++;
    }
    if(MyMinutes<10 && MySeconds<10)
         ui->label_4->setText("0"+QString::number(MyMinutes)+":0"+QString::number(MySeconds));
    else if(MyMinutes<10)
         ui->label_4->setText("0"+QString::number(MyMinutes)+":"+QString::number(MySeconds));
    else if(MySeconds<10)
         ui->label_4->setText(QString::number(MyMinutes)+":0"+QString::number(MySeconds));
    else
         ui->label_4->setText(QString::number(MyMinutes)+":"+QString::number(MySeconds));
}

