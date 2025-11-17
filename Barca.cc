#include "Barca.hh"
    // Tipus de modul: dades
    // Descripcio del tipus: 


    Barca::Barca(string id_barca, string id_estacio){
        id = id_barca;
        this->id_estacio = id_estacio;
    }
    /* Pre: cert */
    /* Post: el resultat es una barca amb id = nom_barca i la seva estacio*/

    // Modificadores

   void Barca::mod_estacio(string id_estacio){
        this->id_estacio = id_estacio;
   }
    /* Pre: cert*/
    /* Post: la barca forma part de la nova estacio*/

    // Consultores

    void Barca::estacion_barca(){
        cout << id_estacio << endl;
    }
    /* Pre: la barca existeix */
    /* Post: imprimim la estació de la barca*/

    void Barca::viajes_barca(){
        for (int i = 0; i < viajes.size(); ++i){
            cout << viajes[i].first << " " << viajes[i].second << endl;
        }
    }
    /* Pre: la barca existeix */
    /* Post: imprimim els viatjes que ha fet la barca*/

    string Barca::consultar_estacio(){
        return id_estacio;
    }
    /* Pre: cert*/
    /* Post: retornem l'id_estacio de la barca*/

    // Lectura i escriptura

   // Metodes propis
   