#include "Estacion.hh"
    
    // Constructores

    Estacion::Estacion(string nom_estacion){}
    /* Pre: cert */
    /* Post: el resultat es una barca amb id = nom_estacio*/

    // Modificadores

    void Estacion::alta_barca_est(string id_barca){
        if (id_barca.size() < capacitat){
            cout << "error: la barca no cabe" << endl;
        } else if (id_barcas.count(id_barca)){
            cout << "error: la barca ya esta en el sitio" << endl;
        } else {
            id_barcas.insert(id_barca);
        }
    }
    /* Pre: llegim id_barca on la barca no existeix i la capacitat de la estacio es menor al maxim*/
    /* Post: afegim la barca al set de la estacio*/

    void Estacion::baja_barca_est(string id_barca){
        if (id_barcas.count(id_barca)){
            id_barcas.erase(id_barca);
        }
    }
    /* Pre: la barca existeix*/
    /* Post: esborrem la barca de la estacio */

    void Estacion::nova_capacitat(int nova_cap){
        if (id_barcas.size() + 1 <= nova_cap){
            capacitat = nova_cap;
        }
    }
    /* Pre: la nova capacitat es >= nº barcas actual */
    /* Post: la estacio te la nova capacitat*/
    
    // Consultores

    void Estacion::imprimir_barques(){
        auto it = id_barcas.begin();
        while (it != id_barcas.end()){
            cout << *it << endl;
            ++it;
        }
    }
    /* Pre: cert*/
    /* Post: imprimim el nom de les barques de la estació*/

    bool Estacion::estacion_llena(){
        bool resultat = false;
        if (capacitat = id_barcas.size() + 1){
            resultat = true;
        }
        return resultat;
    }
    /* Pre: cert*/
    /* Post: retorna true si la mida d'id_barcas >= a la capacitat de la estacio*/

    // Lectura i escriptura

   // Metodes propis

