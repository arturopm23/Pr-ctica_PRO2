#ifndef BARCA_HH
#define BARCA_HH

#include<string>
#include<vector>
#include<iostream>
using namespace std;


class Barca {
    // Tipus de modul: dades
    // Descripcio del tipus: 

 private:
    string id;
    vector< pair< string, string> > viajes;
    string id_estacio;
    /*
      Invariant de la representacio:
            - id = comença obligatoriament amb una lletra i consta nomes de lletres i dígits
    */

 public:

    // Constructores

    Barca(string id_barca, string id_estacio);
    /* Pre: cert */
    /* Post: el resultat es una barca amb id = nom_barca i la seva estacio*/

    // Modificadores

   void mod_estacio(string id_estacio);
    /* Pre: cert*/
    /* Post: la barca forma part de la nova estacio*/

    // Consultores

    void estacion_barca();
    /* Pre: la barca existeix */
    /* Post: imprimim la estació de la barca*/

    string consultar_estacio();
    /* Pre: cert*/
    /* Post: retornem l'id_estacio de la barca*/

    void viajes_barca();
    /* Pre: cert*/
    /* Post: imprimim els viatjes que ha fet la barca*/

    // Lectura i escriptura

   // Metodes propis
   
};
#endif
