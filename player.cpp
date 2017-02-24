#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "explosion.h"

#include <QDebug>
#include <QTimer>

extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
     setPixmap(QPixmap(":/player/player.png"));


}

void Player::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Left){
        if(pos().x() > 0)
            setPos(x()-20,y());
    }else if (event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800)
            setPos(x()+20,y());
    }else if(event->key() == Qt::Key_Space){
        //Create a bullet
        Bullet * bullet = new Bullet("up");
        bullet->setPos(x()+45,y()-55);
        scene()->addItem(bullet);
        Explosion * exp = new Explosion();
        exp->test(2);

        scene()->addItem(exp);
    }

}

void Player::spawnEnemy1(){

    //qDebug() << "Apa";

    // create an enemy
    if(game->health->getHealth() <1){
        game->gameOver();
        return;

    }else{
        Enemy * enemy = new Enemy(1);
        scene()->addItem(enemy);
    }

}

void Player::spawnEnemy2(){

    //qDebug() << "Apa";

    // create an enemy
    if(game->health->getHealth() <1){
        game->gameOver();
        return;

    }else{
        Enemy * enemy = new Enemy(2);
        scene()->addItem(enemy);
    }

}

