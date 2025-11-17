#ifndef ESTACION_HH
#define ESTACION_HH

#include<string>
#include <set>
#include "Cjt_barcas.hh"
#include "Barca.hh"

using namespace std;

class Estacion {
    // Tipus de modul: dades
    // Descripcio del tipus: 

 private:
    string id;
    int capacitat;
    set<string> id_barcas;
    /*
      Invariant de la representacio:
      - id = comença obligatoriament amb una lletra i consta nomes de lletres i dígits
      - capacitat = quantes places té la nostre estacio
      - barcas = set de barcas ordenado por su nombre
    */

 public:

    // Constructores

    Estacion(string nom_estacion, int capacitat);
    /* Pre: cert */
    /* Post: el resultat es una barca amb id = nom_estacio*/

    // Modificadores

    void alta_barca_est(string id_barca);
    /* Pre: llegim id_barca on la barca no existeix i la capacitat de la estacio es menor al maxim*/
    /* Post: afegim la barca al set de la estacio*/

    void baja_barca_est(string id_barca);
    /* Pre: la barca existeix*/
    /* Post: esborrem la barca de la estacio */

    void nova_capacitat(int nova_cap);
    /* Pre: la nova capacitat es >= nº barcas actual */
    /* Post: la estacio te la nova capacitat*/
    
    // Consultores

    void imprimir_barques();
    /* Pre: cert*/
    /* Post: imprimim el nom de les barques de la estació*/

    bool estacion_llena();
    /* Pre: cert*/
    /* Post: retorna true si la mida d'id_barcas >= a la capacitat de la estacio*/

    // Lectura i escriptura

   // Metodes propis
   
};
#endif
