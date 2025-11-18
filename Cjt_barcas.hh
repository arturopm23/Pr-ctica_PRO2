#ifndef CJT_BARCA_HH
#define CJT_BARCA_HH

#include<string>
#include<map>
#include "Barca.hh"
using namespace std;


class Cjt_barcas {
    // Tipus de modul: dades
    // Descripcio del tipus: 

 private:
    map<string, Barca> dicc_barca;
    /*
      Invariant de la representacio:
            
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

   void Cjt_barcas::viajes_barca(string id_barca);

   string Cjt_barcas::estacion_barca(string id_barca);
   /*Pre: cert
   Post: retornem la estacio de la barca*/

    bool existe_barca(string id_barca);
    /* Pre: id d'una barca */
    /* Post: retorna true si existeix una barca amb id_barca al conjunt*/

    // Lectura i escriptura

   // Metodes propis
   
};
#endif
