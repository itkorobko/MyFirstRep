#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
// // лаба 3 : получить программу чучело . ее суть заключается в том что изначально
// //на экране появляется фотография препода , а также на экране вместо курсора бейсбольная бита,
//     задача в том чтобы управляя мышкой пытаться
// догнать фотографию препода и стукнуть по фотографии битой
// нажимая левую клавишу мышки , при этом фото бычтро убегает,
// гонка сопровождается музыкой(любимой музыкой),
// в том случае когда удается битой попасть по фото, на фото появляются синяки
// и тд,удар сопровождается соответсявующим звукои (по типу ура вау) ,
// у препода есть три жизни. когда третий раз осуществляется попадание ,
// на экране прявляется катофалк и под
// похоронную музыку уезжает за границу экрана
// // желательно чтобы можно было использовать различные фото преподов, определять количество жизней для каждого,
//     фиксировать время через сколько секунд получен результат и
//     сохранять эти результаты в какойнибудь базе данных ( как рейтинг) ,
//     желательно чтобы эти параметры задавались в меню
// // лаба 3 к 15 мая
