#include "Estacion.hh"
    
    // Constructores

    Estacion::Estacion(string nom_estacion, int capacidad){
        id = nom_estacion;
        this->capacidad = capacidad;
    }

    // Modificadores

    void Estacion::alta_barca_est(string id_barca){
        if (id_barca.size() < capacidad){
            cout << "error: la barca no cabe" << endl;
        } else if (barcas.count(id_barca)){
            cout << "error: la barca ya esta en el sitio" << endl;
        } else {
            barcas.insert(id_barca);
        }
    }

    void Estacion::baja_barca_est(string id_barca){
        if (barcas.count(id_barca)){
            barcas.erase(id_barca);
        }
    }

    void Estacion::nova_capacidad(int nova_cap){
        if (barcas.size() + 1 <= nova_cap){
            capacidad = nova_cap;
        } else {
            cout << "error: capacidad insuficiente" << endl;
        }
    }
    
    // Consultores

    void Estacion::imprimir_barcas(){
        auto it = barcas.begin();
        while (it != barcas.end()){
            cout << *it << endl;
            ++it;
        }
    }

    bool Estacion::estacion_llena(){
        bool resultat = false;
        if (capacidad = barcas.size() + 1){
            resultat = true;
        }
        return resultat;
    }

    // Lectura i escriptura

   // Metodes propis

