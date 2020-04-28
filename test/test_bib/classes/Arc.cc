#include "../../../src/bib/classes/Arc.hh"

#define CATCH_CONFIG_MAIN
#include "../../../libExt/catch2/include/catch.hpp"

TEST_CASE ("Test des setters", [arc]){

  Arc A1 ("arc1",1, 2,3, m); //map a faire

  SECTION ("Set ID"){
    A1.setID (37);
    REQUIRE (A1.ID == 37);
  }
  SECTION ("Set etiquette"){
    A1.setEtiq("modif");
    REQUIRE (A1.etiquette == "modif");
  }
  SECTION ("Set IDdepart"){
    A1.setIDDepart (7);
    REQUIRE (A1.IDdepart == 7);
  }
  SECTION ("Set IDarrive"){
    A1.setIDArrive (44);
    REQUIRE (A1.IDarrive == 44);
  }
  SECTION ("Set ACharge_Utile"){ // A faire
    A1.setCU ();
    REQUIRE (A1.ACharge_Utile == );
  }
}


TEST_CASE ("Test des getters", []){
  Arc A1 ("arc1",1,2,3,m); //map a faire

  SECTION ("Get ID"){
      REQUIRE (A1.getID() == 1);
  }
  SECTION ("Get etiquette"){
    REQUIRE (A1.getEtiq () == "arc1");
  }
  SECTION ("Get IDdepart"){
    REQUIRE (A1.getIDDepart() == 2);
  }
  SECTION ("Get IDarrive"){
    REQUIRE (A1.getIDArrive() == 3);
  }
  SECTION ("Get ACharge_Utile"){
    REQUIRE (A1.getCU () == NULL) // A faire
  }
}



TEST_CASE("Test des constructeur de la classe", [arc] ){

  SECTION ("Test du constructeur avec tout les arguments"){
    Arc A1 ("arc1", 1,2,3,m); // Faire la map

    REQUIRE (A1.etiquette == "arc1");
    REQUIRE (A1.ID == 1);
    REQUIRE (A1.IDdepart == 2);
    REQUIRE (A1.IDarrive == 3);
    REQUIRE (A1.ACharge_Utile == NULL); // A faire
  }

  SECTION ("Test du constructeur sans la map"){
    Arc A2 ("arc2",2,1,4);

    REQUIRE (A2.etiquette == "arc2");
    REQUIRE (A2.ID == 2);
    REQUIRE (A2.IDdepart == 1);
    REQUIRE (A2.IDarrive == 4);

      SECTION ("Test du constructeur par copie"){
        Arc A4 (A2);

        REQUIRE (A4.etiquette == "arc2");
        REQUIRE (A4.ID == 2);
        REQUIRE (A4.IDdepart == 1);
        REQUIRE (A4.IDarrive == 4);
      }
  }

  SECTION ("Test du constructeur avec un ID, un id de sommet de départ et d'arrive"){
    Arc A3 (3,4,1);

    REQUIRE (A3.ID == 3);
    REQUIRE (A3.IDdepart == 4);
    REQUIRE (A3.IDarrive == 1);
  }
}

TEST_CASE ("Test du destructeur de la classe", [arc]){
  // A faire
}

TEST_CASE ("Test de l'opérateur =", [arc]){
  Arc A2 ("arc2",2,1,4);
  Arc A3 ("arc3",3,4,1);
  A3 = A2;

  REQUIRE (A3.etiquette == "arc2");
  REQUIRE (A3.ID == 2);
  REQUIRE (A3.IDdepart == 1);
  REQUIRE (A3.IDarrive == 4);
}

TEST_CASE ("Test de l'opérateur ==", [arc]){
  Arc A2 ("arc2",2,1,4);
  Arc A4 (A2);

  REQUIRE ((A2 == A4));

}
