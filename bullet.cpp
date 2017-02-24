#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>
#include "game.h"
#include "explosion.h"

extern Game * game;


Bullet::Bullet(QString dir, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(){


    //Connect
    QTimer * timer = new QTimer();

    if(dir == "up"){
        //Draw bullet
        setPixmap(QPixmap(":/env/laserBlue01.png"));

        connect(timer, SIGNAL(timeout()), this,SLOT(moveUp()));

        timer->start(50);

    }else{
        setPixmap(QPixmap(":/enemy/laserRed13.png"));
        connect(timer, SIGNAL(timeout()), this,SLOT(moveDown()));

        timer->start(50);
    }


}

void Bullet::moveUp(){

    if(game->health->getHealth() == 0){
        game->gameOver();
        return;
    }

    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            //increase the score
            game->score->increase();

            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //move bullet up
    setPos(x(),y()-10);
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

void Bullet::moveDown(){

    if(game->health->getHealth() == 0){
        game->gameOver();
        return;
    }

    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        // If enemy bullet hits Player -> player's life decreases with 1
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            game->health->decrease();
            if(game->health->getHealth() == 0){
                game->gameOver();
                return;
            }
            scene()->removeItem(this);
            delete this;
            return;

        // If Player shoots an enemy bullet, remove both bullets
        }else if(typeid(*(colliding_items[i])) == typeid(Bullet)){

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;

        }
    }

    //move bullet down
    setPos(x(),y()+10);
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }


}
