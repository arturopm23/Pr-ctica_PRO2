#include "Barca.hh"

    //Constructores

    Barca::Barca(string id_barca, string id_estacion){
        id = id_barca;
        this->id_estacion = id_estacion;
    }

    // Modificadores

   void Barca::mod_estacio(string id_estacion){
        this->id_estacion = id_estacion;
   }

    void Barca::guardar_viaje(string origen, string destino){
        viajes.push_back(make_pair(origen, destino));
    }

    // Consultores

    void Barca::imprimir_estacion(){
        cout << id_estacion << endl;
    }

    void Barca::viajes_barca(){
        for (int i = 0; i < viajes.size(); ++i){
            cout << viajes[i].first << " " << viajes[i].second << endl;
        }
    }

    string Barca::consultar_estacion(){
        return id_estacion;
    }

    // Lectura i escriptura

   // Metodes propis
   