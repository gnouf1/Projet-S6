#include "QSommet.hh"


QSommet::QSommet(Sommet S){
  this->id = S.getID();
  this->posx = S.getPosX();
  this->posy = S.getPosY();
  this->rayon = TAILLE_RAYON;
  this->coul = QColor(0,0,0); // On le met en noir
  this->select = 0;
}

QSommet::~QSommet(){}

int QSommet::getID() const{return this->id;}
int QSommet::getPosX() const{return this->posx;}
int QSommet::getPosY() const{return this->posy;}
int QSommet::getRayon() const{return this->rayon;}
QColor QSommet::getCoul() const{return this->coul;}
bool QSommet::getSelect() const{return this->select;}

void QSommet::setID(int id){this->id = id;}
void QSommet::setPosX(int x){this->posx = x;}
void QSommet::setPosY(int y){this->posy = y;}
void QSommet::setRayon(int r){this->rayon = r;}
void QSommet::setCoul(QColor color){this->coul = color;}
void QSommet::setSelect(bool select){this->select = select;}

void QSommet::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){}
QRectF QSommet::boundingRect() const{}
void QSommet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){}
