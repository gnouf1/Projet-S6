#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

#ifndef STRUCTS
#define STRUCTS

typedef struct Valeur_Vecteur{
  bool type; // Si 0 entier, si 1 réel.
  int valeur_entiere;
  float valeur_reel;
}VectVal;

bool operator== (VectVal v1, VectVal v2){
  if (v1.type == v2.type){
    if (v1.valeur_entiere == v2.valeur_entiere || v1.valeur_reel == v2.valeur_reel){
        return true;
    }
  }
  return false;
}

typedef struct ROW{
  int tache;
  string nom_tache;
  int duree;
  vector <int> taches_anterieures;
  vector <int> taches_posterieures;
} pert_row;

#endif
