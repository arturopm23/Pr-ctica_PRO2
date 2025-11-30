#include "Estacion.hh"
    
    // Constructores

    Estacion::Estacion(string nom_estacion, int capacidad){
        id = nom_estacion;
        this->capacidad = capacidad;
    }

    // Modificadores

    void Estacion::alta_barca_est(string id_barca){
        if (barcas.size() >= capacidad){
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

    void Estacion::nueva_capacidad(int nova_cap){
            capacidad = nova_cap;
    }
    
    // Consultores

    string Estacion::consultar_idBarca_petit(){
        auto it = barcas.begin();
        string id_petit = *it;
        ++it;
        while (it != barcas.end()){
            if (*it < id_petit) id_petit = *it;
            ++it;
        }
        return id_petit; 
    }

    int Estacion::consultar_capacidad(){
        return capacidad - barcas.size();
    }

        int Estacion::consultar_capacidad_total(){
        return capacidad;
    }

    int Estacion::consultar_aforo(){
        return barcas.size();
    }

    void Estacion::imprimir_barcas(){
        auto it = barcas.begin();
        while (it != barcas.end()){
            cout << *it << endl;
            ++it;
        }
    }

    bool Estacion::estacion_llena(){
        bool resultat = false;
        if (capacidad <= barcas.size()){
            resultat = true;
        }
        return resultat;
    }

    // Lectura i escriptura

   // Metodes propis

