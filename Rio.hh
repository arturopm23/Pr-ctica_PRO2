#ifndef RIO_HH
#define RIO_HH

#include<string>
#include "bintree.hh"
#include "Estacion.hh"
#include "Cjt_barcas.hh"
#include <map>
using namespace std;


class Rio {

    // Tipus de modul: dades
    // Descripcio del tipus: 

 private:
    BinTree<string> rio;
    map<string, Estacion> dicc_estacion;

    BinTree<string> construir_arbol();
    int plazas_disp;

    /*
      Invariant de la representacio:
            - 
    */
    BinTree<string> subir_barcas_aux(Cjt_barcas& mis_barcas, BinTree<string> rio);

 public:

    // Constructores

    Rio();
    /* Pre: cert */
    /* Post: el resultat es un riu amb les seves estacions i un conjunt de barques*/

    // Modificadores

    void alta_barca(string id_barca, string id_estacion, Cjt_barcas& mis_barcas);
    /* Pre: la barca no existeix i la estacio no esta plena */
    /* Post: afegim la nova barca a la estacio*/

    void baja_barca(string id_barca, Cjt_barcas& mis_barcas);
    /* Pre: la barca existeix */
    /* Post: esborrem la barca de la estacio*/

    void mover_barca(string id_barca, string id_estacion, Cjt_barcas& mis_barcas);
    /* Pre: la barca existeix, la estació destí és diferent de l'origen, la estació destí no està plena */
    /* Post: esborrem la barca de la estacio d'origen i l'afegim al destí*/

    void modificar_capacidad(string id_estacion, int nueva_cap);
    /* Pre: la estacio existeix, la nova capacitat es >= nº barcas actual */
    /* Post: la estacio te la nova capacitat*/

    void subir_barcas(Cjt_barcas& mis_barcas);
    /* Pre: cert */
    /* Post: Intentarem afegir a una estació pare parells de barques de les filles
    fins que la estació para s'ompli o una de les filles es buidi*/

    string asignar_estacion(string id_barca, Cjt_barcas& mis_barcas);
    /* Pre: la barca no existeix i tenim espai */
    /* Post: Assignem la barca a una nova estació amb menys ocupació
    (pl.ocupades/pl.totals) retorna l'id de la estació destí*/

    // Consultores
    
    void barca_estacion(string id_estacion);
    /* Pre: la estacio existeix */
    /* Post: imprimim les barques de la estacio*/

    void plazas_libres();
    /* Pre: cert */
    /* Post: imprimim el numero de places lliures*/

    bool existe_estacion(string id_estacion);
    /* Pre: id d'una estacio */
    /* Post: retorna true si al conjunt existeix una estacio amb id_estacion*/

    bool estacion_llena(string id_estacion);
    /* Pre: la estacio existeix*/
    /* Post: retornem true si capacidad == nº elements de la estacio*/

    // Lectura i escriptura


   // Metodes propis
   
};
#endif
