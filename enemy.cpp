#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QGraphicsPixmapItem>
#include <typeinfo>
#include <QDebug>
#include <ctime>
#include "game.h"
#include "bullet.h"

extern Game * game;

Enemy::Enemy(int type, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(){
    //set random position
    srand((int)time(0));
    int random_number = rand() % 700;
    setPos(random_number,0);

    if(type == 1){
        setPixmap(QPixmap(":/enemy/enemyRed1.png"));
    }else{
        setPixmap(QPixmap(":/enemy/enemyRed2.png"));
        QTimer::singleShot(1000,this,SLOT(spawn()));
    }


     QTimer * timer = new QTimer();
     connect(timer, SIGNAL(timeout()), this,SLOT(move()));
     timer->start(50);


}

void Enemy::move(){

    //move enemy down
    setPos(x(),y()+5);
    if(game->health->getHealth() <1){
        scene()->removeItem(this);
        delete this;


    }
    if (pos().y() > 600){
        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }

    // if enemy collides with player, remove enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            //decrease health
            game->health->decrease();

            // remove enemy
            scene()->removeItem(this);
            delete this;
            return;
        }

    }
}

void Enemy::spawn(){
    Bullet * bullet = new Bullet("down");
    bullet->setPos(x()+42,y()+60);
    scene()->addItem(bullet);
}
