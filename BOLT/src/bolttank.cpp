#include "headers/bolttank.hpp"
#include "headers/boltprojectile.hpp"

#include <QGraphicsScene>
#include <QPainter>
#include <QKeyEvent>

BoltTank::BoltTank()
    :_tankWidth(80), _tankHeigth(130), _movementSpeed(7),_life(100)
{
    setZValue(2);
}
QRectF BoltTank::boundingRect() const
{
    return QRectF(0, 0, _tankWidth, _tankHeigth);
}

QPainterPath BoltTank::shape() const
{
    QPainterPath path;

    path.addRect(0, 0, _tankWidth, _tankHeigth);

    return path;
}

void BoltTank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)

    //Crtanje topa
    painter->drawPixmap(0, 0, _tankWidth, _tankHeigth, QPixmap(":/images/tenk.png"));


}
void BoltTank::keyPressEvent(QKeyEvent * event){

    if (event->key() == Qt::Key_Left and x()-_movementSpeed>-10){
        setPos(x()-_movementSpeed,y());
    }
    else if (event->key() == Qt::Key_Right and x()+_movementSpeed<840){
        setPos(x()+_movementSpeed,y());
    }else if(event->key() == Qt::Key_Space){
        fire();
    }
    event->setAccepted(true);

}
void BoltTank::fire(){
    BoltProjectile* bolt=new BoltProjectile();
    bolt->setPos(x()+_tankWidth/2-4,y());
    this->scene()->addItem(bolt);
}

int BoltTank::getLife()
{
    return _life;
}

void BoltTank::setLife(int life)
{
    _life = life;
}
