#include "Cjt_barcas.hh"   
    
    // Constructores

    Cjt_barcas::Cjt_barcas(){
    }
    /* Pre: cert */
    /* Post: el resultat es un conjunt de barques buit*/

    // Modificadores

    bool Cjt_barcas::alta_barca_cjt(string id_barca, string id_estacio){
        bool result = true;
        if (dicc_barca.count(id_barca)){
            result = false;
            cout << "error: la barca ya existe" << endl;
        } else {
            Barca b1(id_barca, id_estacio);
            dicc_barca.emplace(id_barca, b1);
        }
        return result;
    }
    /* Pre: la barca no existeix*/
    /* Post: la nueva barca forma parte del conjunto, true si incorporamos la barca, false sino*/

    void Cjt_barcas::baja_barca_cjt(string id_barca){
        if (dicc_barca.count(id_barca)){
            dicc_barca.erase(id_barca);
        } else {
            cout << "error: la barca no existe" << endl;
        }
    }   
    /* Pre: la barca existe*/
    /* Post: la barca ya no forma parte del conjunto*/

    void Cjt_barcas::mover_barca(string id_barca, string id_estacion){
        auto it = dicc_barca.find(id_barca);
        if (it == dicc_barca.end()) {
            cout << "error: la barca no existe" << endl;
        } else if (it->second.consultar_estacio() == id_estacion){
            cout << "error: la barca ya esta en el sitio" << endl;
        } else {
            it->second.guardar_viaje(it->second.consultar_estacio(), id_estacion);
            it->second.mod_estacio(id_estacion);
        }
    }
    /* Pre: la barca existeix, la estació destí és diferent de l'origen, la estació destí no està plena */
    /* Post: esborrem la barca de la estacio d'origen i l'afegim al destí, afegim el viatje a la barca*/

    // Consultores

    void Cjt_barcas::viajes_barca(string id_barca){
        auto it = dicc_barca.find(id_barca);
        if (it != dicc_barca.end()){
            it->second.viajes_barca();
        } else {
            cout << "error: la barca no existe" << endl; 
        }
    }

    string Cjt_barcas::estacion_barca(string id_barca){
        string result = "";
       auto it = dicc_barca.find(id_barca);
       return it->second.consultar_estacio();
    }

    bool Cjt_barcas::existe_barca(string id_barca){
        return dicc_barca.count(id_barca) > 0;
    }
    /* Pre: id d'una barca */
    /* Post: retorna true si existeix una barca amb id_barca al conjunt*/

    // Lectura i escriptura

   // Metodes propis