#ifndef BARCA_HH
#define BARCA_HH

#include<string>
#include<vector>
#include<iostream>
using namespace std;


class Barca {

 private:
    string id;
    vector< pair< string, string> > viajes;
    string id_estacion;
    /*
      Invariant de la representacio:
            - id = comença obligatoriament amb una lletra i consta nomes de lletres i dígits
            -viajes = vector de parells amb el primer element origen i segon destí
            - id_estacion = mateixos requisits que id, representa el id de la estacio on tenim la barca
    */

 public:

    // Constructores

    Barca(string id_barca, string id_estacion);
    /* Pre: cert */
    /* Post: el resultat es una barca amb id = nom_barca, la seva estacio i un vector buit de viatjes*/

    // Modificadores

   void mod_estacio(string id_estacion);
    /* Pre: cert*/
    /* Post: la barca forma part de la nova estacio*/

    // Consultores

    void imprimir_estacion();
    /* Pre: la barca existeix */
    /* Post: imprimim la estació de la barca*/

    string consultar_estacion();
    /* Pre: cert*/
    /* Post: retornem l'id_estacion de la barca*/

    void viajes_barca();
    /* Pre: cert*/
    /* Post: imprimim els viatjes que ha fet la barca*/

    void guardar_viaje(string origen, string destino);
    /* Pre: cert
    Post: guardamos el nuevo viaje en el vector viajes como pareja de strings*/


    // Lectura i escriptura

   // Metodes propis
   
};
#endif
