#include <QtTest/QtTest>
#include <QGraphicsScene>
#include "../../../../src/app/GUI/fntPrincipale/QArc.hh"
#include "../../../../src/app/GUI/fntPrincipale/QSommet.hh"

class TestQArc: public QObject
{
    Q_OBJECT
private slots:
void testConstruct(){
  QGraphicsScene scene;

  Sommet S2(2,3,"S2",2), S0(23,32,"S0",0);
  QSommet QS2(S2), QS0(S0);
  scene.addItem(&QS2);
  scene.addItem(&QS0);

  // On fait la map INUTILE de l'arc
  VectVal vv;
  vv.type = 0;
  vv.valeur_entiere = 12;

  map <string, VectVal> cu;
  cu.insert (pair <string, VectVal> ("flot", vv));

  // On construit le Sommet
  Arc A1("arc1", 1, 2, 0, cu);

  // On construit le QArc
  Qarc QA1(A1);
  scene.addItem(&QA1);
  QVERIFY(QA1.getID() == 1);
  QVERIFY(QA1.getPosXA() == 2);
  QVERIFY(QA1.getPosYA() == 3);
  QVERIFY(QA1.getPosXB() == 23);
  QVERIFY(QA1.getPosYB() == 32);
}

void testGettersSetters(){
  // On construit le Sommet
  Arc A1("arc1", 1, 2, 0);

  // On construit le QArc
  Qarc QA1(A1);
  QA1.setID(12);
  QA1.setPosXA(1);
  QA1.setPosYA(1);
  QA1.setPosXB(3);
  QA1.setPosYB(3);

  QVERIFY(QA1.getID() == 12);
  QVERIFY(QA1.getPosXA() == 1);
  QVERIFY(QA1.getPosYA() == 1);
  QVERIFY(QA1.getPosXB() == 3);
  QVERIFY(QA1.getPosYB() == 3);
}

};
#ifndef QTT_MAIN
#define QTT_MAIN
QTEST_MAIN(TestQArc);
#endif
#include "QArc.moc"
