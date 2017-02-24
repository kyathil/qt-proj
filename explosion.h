#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>

class Explosion: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Explosion(QGraphicsItem * parent=0);
    void test(int i);
public slots:
    void explode(int i);

};


#endif // EXPLOSION_H
