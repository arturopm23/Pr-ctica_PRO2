#ifndef CJT_BARCA_HH
#define CJT_BARCA_HH

#include<string>
#include<map>
#include "Barca.hh"
using namespace std;


class Cjt_barcas {

 private:
    map<string, Barca> dicc_barca;
    /*
      Invariant de la representacio:
            - dicc_barca: mapa donde la clave de cada barca es su id y contiene su objeto Barca
    */

 public:

    // Constructores

    Cjt_barcas();
    /* Pre: cert */
    /* Post: el resultat es un conjunt de barques buit*/

    // Modificadores

    bool alta_barca_cjt(string id_barca, string id_estacio);
    /* Pre: la barca no existeix*/
    /* Post: la nueva barca forma parte del conjunto, true si incorporamos la barca, false sino*/


    void baja_barca_cjt(string id_barca);
    /* Pre: la barca existe*/
    /* Post: la barca ya no forma parte del conjunto*/

    void mover_barca(string id_barca, string id_estacion);
    /* Pre: la barca existeix, la estació destí és diferent de l'origen, la estació destí no està plena */
    /* Post: esborrem la barca de la estacio d'origen i l'afegim al destí, afegim el viatje a la barca*/

    // Consultores

   void viajes_barca(string id_barca);
   /* Pre: la barca existeix*/
   /* Post: imprimim els viatjes que ha fet una barca del diccionari*/

   string estacion_barca(string id_barca);
   /*Pre: cert
   Post: retornem la estacio de la barca*/

    bool existe_barca(string id_barca);
    /* Pre: id d'una barca */
    /* Post: retorna true si existeix una barca amb id_barca al conjunt*/

    // Lectura i escriptura

   // Metodes propis
   
};
#endif
