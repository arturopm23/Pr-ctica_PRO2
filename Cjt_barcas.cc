#include "Cjt_barcas.hh"   
    
    // Constructores

    Cjt_barcas::Cjt_barcas(){
    }

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

    void Cjt_barcas::baja_barca_cjt(string id_barca){
        if (dicc_barca.count(id_barca)){
            dicc_barca.erase(id_barca);
        } else {
            cout << "error: la barca no existe" << endl;
        }
    } 

    void Cjt_barcas::mover_barca(string id_barca, string id_estacion){
        auto it = dicc_barca.find(id_barca);
        if (it == dicc_barca.end()) {
            cout << "error: la barca no existe" << endl;
        } else if (it->second.consultar_estacion() == id_estacion){
            cout << "error: la barca ya esta en el sitio" << endl;
        } else {
            it->second.guardar_viaje(it->second.consultar_estacion(), id_estacion);
            it->second.mod_estacio(id_estacion);
        }
    }

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
       auto it = dicc_barca.find(id_barca);
       return it->second.consultar_estacion();
    }

    void  Cjt_barcas::imprimir_estacion_barca(string id_barca){
       auto it = dicc_barca.find(id_barca);
       return it->second.imprimir_estacion();
    }

    bool Cjt_barcas::existe_barca(string id_barca){
        return dicc_barca.count(id_barca) > 0;
    }

    // Lectura i escriptura

   // Metodes propis