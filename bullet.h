#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Bullet(QString dir, QGraphicsItem * parent=0);

public slots:
    void moveUp();
    void moveDown();

};

#endif // BULLET_H
