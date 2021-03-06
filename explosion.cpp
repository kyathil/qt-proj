#include "explosion.h"
#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "game.h"

extern Game * game;


Explosion::Explosion(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(){

   QVector<QPixmap> list;
   list.append(QPixmap("qrc:/explosions/explosion00.png"));
   list.append(QPixmap("qrc:/explosions/explosion01.png"));
   list.append(QPixmap("qrc:/explosions/explosion02.png"));

   QPixmap p("qrc:/explosions/explosion00.png");

   QString size = QString::number(list.size());
   qDebug() << "List size is: " << size;

   QTimer * timer = new QTimer();
   //QTimer::singleShot(1000,this,SLOT(explode(2)));


   // qDebug() << "EXPLODING!! :O";
   //QTimer * timer = new QTimer();
   //setPixmap(QPixmap(":/explosions/0308c489ef2156ecb78dd6ba02b0a9c2_-explosion-gif-image-clipart-bomb-exploding-gif-transparent_450-274.gif"));
   //timer->start(2000);
   //setPixmap(QPixmap(":/explosions/explosion01.png"));
   //scene()->removeItem(this);

}

void Explosion:: test(int i){
    QTimer::singleShot(1000,this,SLOT(explode(i)));

}

void Explosion:: explode(int i){
    QVector<QPixmap> list;
    list.append(QPixmap("qrc:/explosions/explosion00.png"));
    list.append(QPixmap("qrc:/explosions/explosion01.png"));
    list.append(QPixmap("qrc:/explosions/explosion02.png"));

    //setPixmap(p);

    qDebug() << "Incoming" << i;


}
