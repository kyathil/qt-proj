#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>

#include "player.h"
#include "score.h"
#include "health.h"


class Game: public QGraphicsView{
    Q_OBJECT

public:
    Game(QWidget * parent=0);
    void gameOver();
    void drawMenu();
    void getHighscore();

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

public slots:
    void start();
    void restart();


};

#endif // GAME_H
