#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>



class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Enemy(int type, QGraphicsItem * parent=0);

public slots:
    void move();
    void spawn();

};

#endif // ENEMY_H
