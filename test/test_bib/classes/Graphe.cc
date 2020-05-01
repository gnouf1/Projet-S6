
#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch.hpp"
#include "../../../src/bib/classes/GrapheMatrice.hh"

// A FINIR
TEST_CASE ("Test des setters", "[Graphe]"){
  /* GRAPHE G1*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));

  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));
  Graphe G1("Graphe1", listeS, listeA, "NULL");

  SECTION ("Set etiquette"){
    G1.setEtiq("modif");
    REQUIRE(G1.getEtiq() == "modif");
  }

  SECTION("Set path"){
    G1.setPath("/home/Desktop/");
    REQUIRE(G1.getPath() == "/home/Desktop/");
  }

  SECTION("Set liste_Arcs"){
    std::vector<Arc> v;
    v.push_back(Arc(0,0,1));
    v.push_back(Arc(1,1,2));
    v.push_back(Arc(2,0,2));
    G1.setListe_Arc(v);

    REQUIRE(G1.getListe_Arcs().size() == v.size());
    if(G1.getListe_Arcs().size() == v.size()){ // Au cas où
      for(int i=0;i<v.size();i++){
        REQUIRE( v[i] == G1.getListe_Arcs()[i]);
      }
    }
  }

  SECTION("Set liste_Sommets"){
    std::vector<Sommet> v;
    v.push_back(Sommet(0));
    v.push_back(Sommet(1));
    v.push_back(Sommet(2));
    G1.setListe_Sommet(v);

    REQUIRE(G1.getListe_Sommets().size() == v.size());
    if(G1.getListe_Sommets().size() == v.size()){ // Au cas où
      for(int i=0;i<v.size();i++){
        REQUIRE(G1.getListe_Sommets()[i]==v[i]);
      }
    }
  }

}

TEST_CASE ("Test des getters", "[Graphe]"){

/* GRAPHE G1*/
vector<Sommet> listeS;
vector<Arc> listeA;
listeS.push_back(Sommet(0));
listeS.push_back(Sommet(1));
listeS.push_back(Sommet(2));

listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));

Graphe G1("Graphe1", listeS, listeA, "NULL");

  SECTION("Get etiquette"){
    REQUIRE(G1.getEtiq() == "Graphe1");
  }

  SECTION("Get liste_Arcs"){

    REQUIRE(G1.getListe_Arcs().size() == listeA.size());
    if(G1.getListe_Arcs().size() == listeA.size()){ // Au cas où
      for(int i=0;i<listeA.size();i++){
        REQUIRE(G1.getListe_Arcs()[i]==listeA[i]);
      }
    }
  }

  SECTION("Get liste_Sommets"){

    REQUIRE(G1.getListe_Sommets().size() == listeS.size());
    if(G1.getListe_Sommets().size() == listeS.size()){ // Au cas où
      for(int i=0;i<listeS.size();i++){
        REQUIRE(G1.getListe_Sommets()[i]==listeS[i]);
      }
    }
  }

  SECTION("Get path"){
    REQUIRE(G1.getPath() == "NULL");
  }
}

// A FINIR
TEST_CASE("Test des constructeur de la classe", "[Graphe]" ){

  /*GRAPHE G0*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeS.push_back(Sommet(3));
  listeS.push_back(Sommet(4));
  listeS.push_back(Sommet(5));
  listeA.push_back(Arc(0,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[0].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[1].getID(),listeS[3].getID()));
  listeA.push_back(Arc(4,listeS[2].getID(),listeS[3].getID()));
  listeA.push_back(Arc(5,listeS[2].getID(),listeS[5].getID()));
  listeA.push_back(Arc(6,listeS[3].getID(),listeS[4].getID()));

  SECTION("Test du constructeur avec tout les arguments"){
      Graphe G0("Graphe0", listeS, listeA, "NULL");
      REQUIRE(G0.getEtiq() == "Graphe0");
      REQUIRE(G0.getListe_Arcs().size() == listeA.size());
      if(G0.getListe_Arcs().size() == listeA.size()){ // Au cas où
        for(int i=0;i<listeA.size();i++){
          REQUIRE(G0.getListe_Arcs()[i]==listeA[i]);
        }
      }
      REQUIRE(G0.getListe_Sommets().size() == listeS.size());
      if(G0.getListe_Sommets().size() == listeS.size()){ // Au cas où
        for(int i=0;i<listeS.size();i++){
          REQUIRE(G0.getListe_Sommets()[i]==listeS[i]);
        }
      }
      REQUIRE(G0.getPath() == "NULL");

  }

  SECTION("Test du constructeur vide"){
    Graphe G0 ("Graphe G0");
    REQUIRE(G0.getEtiq() == "Graphe0");
    REQUIRE(G0.getPath() == "\0");
    REQUIRE(G0.getListe_Arcs().size() == 0);
    REQUIRE(G0.getListe_Sommets().size() == 0);
  }

  SECTION("Test du constructeur par Matrice d'Adjacence"){
      Matrice MA1(3); //Matrice Adjacence avec 3 Sommets 0 Arcs
      MA1.modifTab(0,1,1);
      MA1.modifTab(1,2,1);
      MA1.modifTab(2,0,1);

      Graphe G1(MA1);
      REQUIRE(G1.getEtiq() == "Graphe Adjacence");

      REQUIRE(G1.getListe_Sommets().size() == MA1.gettV());
      int cmp=0;
      for(int i=0;i<MA1.gettV();i++){
        for(int j=0;j<MA1.gettV();i++){
          if(MA1.getTab()[i][j]){
            cmp++;
          }
        }
      }
      REQUIRE(G1.getListe_Arcs().size()==cmp);

      for(int i=0;i<G1.getListe_Arcs().size();i++){
        REQUIRE(MA1.getTab()[G1.getListe_Arcs()[i].getIDDepart()][G1.getListe_Arcs()[i].getIDArrive()]);
      }
      REQUIRE(G1.getPath() == "\0");
  }

  //faire pour matrice d'incidence

  SECTION("Test du constructeur par copie"){
    Graphe G1("Bonjour");
    Graphe G2(G1);
    REQUIRE(G1.getEtiq()==G2.getEtiq());
    REQUIRE(G1.getListe_Arcs().size()==G2.getListe_Arcs().size());
    REQUIRE(G1.getListe_Sommets().size()==G2.getListe_Sommets().size());
    REQUIRE(G1.getPath()==G2.getPath());
    for(int i =0;i<G1.getListe_Arcs().size();i++){
      REQUIRE(G1.getListe_Arcs()[i]==G1.getListe_Arcs()[i]);

    }
    for(int i =0;i<G1.getListe_Sommets().size();i++){
      REQUIRE(G1.getListe_Sommets()[i]==G2.getListe_Sommets()[i]);
    }

  }
//suite a revoir
  SECTION("Test du constructeur par Liste de Voisin"){
    std::vector<std::vector<int>> LV;
    LV.push_back({1});
    LV.push_back({2});
    LV.push_back({0});
    Graphe GV(LV);

  }

}


TEST_CASE ("Test du destructeur de la classe", "[Graphe]"){ // A FAIRE
  // à faire
}

TEST_CASE ("Test de l'opérateur =", "[Graphe]"){

}

TEST_CASE ("Test de l'opérateur ==", "[Graphe]"){

}

TEST_CASE ("Test de conversion en matrice d'adjacence et d'incidence", "[Graphe]"){
  /* GRAPHE G1*/
  std::vector<Sommet> listeS;
  std::vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));
  Graphe G1("Graphe0", listeS, listeA, "NULL");

  SECTION("Test de conversion en Matrice d'adjacence"){
    /*Matrice MA1*/
    Matrice MA1 (3);

    REQUIRE(G1.conversion_vers_Matrice_adj() == MA1);
  }

  SECTION("Test de conversion en Matrice d'incidence"){
    /*Matrice MI*/
    Matrice MI1 (1,3,1);

    REQUIRE(G1.conversion_vers_Matrice_inc() == MI1);
  }
}

TEST_CASE ("Test ajout de sommet", "[Graphe]"){

}

TEST_CASE ("Test suprression de sommet", "[Graphe]"){

}

// A FAIRE
TEST_CASE ("Test ajout d'arc", "[Graphe]"){
  /* GRAPHE G1*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));
  Graphe G1("Graphe1", listeS, listeA, "NULL");

}

// A FAIRE
TEST_CASE ("Test de suppression d'arc", "[Graphe]"){
  /* GRAPHE G1*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[2].getID(),listeS[0].getID()));
  Graphe G1("Graphe1", listeS, listeA, "NULL");
}

// A FAIRE KILL ME PLIZ
TEST_CASE ("Test de conversion en liste de voisin", "[Graphe]"){
  /*GRAPHE G0*/
  vector<Sommet> listeS;
  vector<Arc> listeA;
  listeS.push_back(Sommet(0));
  listeS.push_back(Sommet(1));
  listeS.push_back(Sommet(2));
  listeS.push_back(Sommet(5));
  listeS.push_back(Sommet(3));
  listeS.push_back(Sommet(4));
  listeA.push_back(Arc(0,listeS[1].getID(),listeS[2].getID()));
  listeA.push_back(Arc(1,listeS[0].getID(),listeS[1].getID()));
  listeA.push_back(Arc(2,listeS[0].getID(),listeS[2].getID()));
  listeA.push_back(Arc(3,listeS[1].getID(),listeS[3].getID()));
  listeA.push_back(Arc(4,listeS[2].getID(),listeS[3].getID()));
  listeA.push_back(Arc(5,listeS[2].getID(),listeS[5].getID()));
  listeA.push_back(Arc(6,listeS[3].getID(),listeS[4].getID()));
  Graphe G0("Graphe0", listeS, listeA, "NULL");
  vector<vector<int>> result;
  // vecteur à initialiser

  REQUIRE(G0.conversion_vers_listeDeVoisins() == result);
}
