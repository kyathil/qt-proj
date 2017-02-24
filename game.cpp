#include "game.h"
#include "button.h"
#include <QTimer>
#include <QPixmap>
#include "enemy.h"
#include <QDebug>


Game::Game(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/env/background.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    start();

}

void Game::start(){
    qDebug() << "starting!";

    // create the player
    player = new Player();
    player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);


    // spawn enemies
     QTimer * timer = new QTimer();
     QTimer * timer2 = new QTimer();
     QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawnEnemy1()));
     timer->start(2000);
     QObject::connect(timer2,SIGNAL(timeout()),player,SLOT(spawnEnemy2()));
     timer2->start(7000);




}

void Game::restart(){
    qDebug() << "Restarting game";
    scene->clear();
    start();

}

void Game::gameOver(){
    qDebug() << "Game is over, nub";
    scene->clear();
    QPixmap gameover(":/env/gameover.png");
    QGraphicsPixmapItem * item = new QGraphicsPixmapItem();
    item->setPixmap(gameover);
    item->setPos(200,100);
    scene->addItem(item);

    Button* restartButton = new Button(QString("Restart Game"));
    restartButton->setPos(300,340);
    connect(restartButton,SIGNAL(clicked()),this,SLOT(restart()));
    scene->addItem(restartButton);



}

void Game::drawMenu(){

}

void Game::getHighscore(){

}
