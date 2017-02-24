#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>



class Player: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT

public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawnEnemy1();
    void spawnEnemy2();
};

#endif // PLAYER_H
