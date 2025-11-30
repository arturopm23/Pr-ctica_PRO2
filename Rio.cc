#include "Rio.hh"
    // Constructores

    BinTree<string> Rio::construir_arbol(){
        string id;
        cin >> id;
        if (id == "#"){
            return BinTree<string>();
        }
        int capacidad;
        cin >> capacidad;
        plazas_disp += capacidad;
        Estacion e(id, capacidad);
        dicc_estacion.insert({id, e});
        BinTree<string> left = construir_arbol();
        BinTree<string> right = construir_arbol();
        return BinTree<string>(id, left, right);
    }

    BinTree<string> Rio::subir_barcas_aux(Cjt_barcas& mis_barcas, BinTree<string> rio){
        if (rio.empty()){
            BinTree<string> resultat;
            return resultat;
        }

        BinTree<string> rio_left = subir_barcas_aux(mis_barcas, rio.left());
        BinTree<string> rio_right = subir_barcas_aux(mis_barcas, rio.right());

        if (rio_left.empty() or rio_right.empty()){
            BinTree<string> resultat(rio.value());
            return resultat;
        }

        auto it_left = dicc_estacion.find(rio_left.value());
        auto it_right = dicc_estacion.find(rio_right.value());
        auto it = dicc_estacion.find(rio.value());

        while (it_left->second.consultar_aforo() > 0 and it_right->second.consultar_aforo() > 0 and it->second.consultar_capacidad() >= 2){
            mover_barca(it_left->second.consultar_idBarca_petit(), it->first, mis_barcas);
            mover_barca(it_right->second.consultar_idBarca_petit(), it->first, mis_barcas);
        }
        BinTree<string> resultat(rio.value(), rio_left, rio_right);
        return resultat;
    }

    Rio::Rio(){
        plazas_disp = 0;
        rio = construir_arbol();
    }

    // Modificadores

    void Rio::alta_barca(string id_barca, string id_estacion, Cjt_barcas& mis_barcas){
        auto it = dicc_estacion.find(id_estacion);
        if (it == dicc_estacion.end()) {
         cout << "error: la estacion no existe" << endl;
        } else if (it->second.estacion_llena()) {
         cout << "error: la barca no cabe" << endl;
        } else {
        if (mis_barcas.alta_barca_cjt(id_barca, id_estacion)){
        --plazas_disp;
         it->second.alta_barca_est(id_barca);
        }
    }
    }

    void Rio::baja_barca(string id_barca, Cjt_barcas& mis_barcas){
    if (mis_barcas.existe_barca(id_barca)){
        string id_est_ant = mis_barcas.estacion_barca(id_barca);
        auto it = dicc_estacion.find(id_est_ant);
    if (it != dicc_estacion.end()) {
            it->second.baja_barca_est(id_barca);
            mis_barcas.baja_barca_cjt(id_barca);
            ++plazas_disp;
    }
} else {
        cout << "error: la barca no existe" << endl;
    }
}

    void Rio::mover_barca(string id_barca, string id_estacion, Cjt_barcas& mis_barcas){
        auto it_dest = dicc_estacion.find(id_estacion); 
    if (it_dest == dicc_estacion.end()) {
        cout << "error: la estacion no existe" << endl;
    } else if (it_dest->second.estacion_llena()) {
        cout << "error: la barca no cabe" << endl;
    } else {
        if (mis_barcas.existe_barca(id_barca)) {
            string id_est_actual = mis_barcas.estacion_barca(id_barca);
            auto it_actual = dicc_estacion.find(id_est_actual);
            if (it_actual != dicc_estacion.end()) {
                it_actual->second.baja_barca_est(id_barca);
                it_dest->second.alta_barca_est(id_barca);
                mis_barcas.mover_barca(id_barca, id_estacion);
            }
        } else {
            cout << "error: la barca no existe" << endl;
        }
    }
    }
    
    void Rio::modificar_capacidad(string id_estacion, int nueva_cap){
    auto it = dicc_estacion.find(id_estacion);
    if (it == dicc_estacion.end()) {
        cout << "error: la estacion no existe" << endl;
    } else {
        int diff = nueva_cap - it->second.consultar_capacidad();
        plazas_disp += diff;
        it->second.nueva_capacidad(nueva_cap);
    }
    }

    void Rio::subir_barcas(Cjt_barcas& mis_barcas){
        subir_barcas_aux(mis_barcas, rio);
    }

    string Rio::asignar_estacion(string id_barca, Cjt_barcas& mis_barcas){
        return ";";
    }

    // Consultores
    
    void Rio::barca_estacion(string id_estacion){
        auto it =dicc_estacion.find(id_estacion);
        if (it != dicc_estacion.end()){
            it->second.imprimir_barcas();
        }
    }

    void Rio::plazas_libres(){
        cout << plazas_disp << endl;
    }

    bool Rio::existe_estacion(string id_estacion){
        return dicc_estacion.count(id_estacion);
    }
    
    bool Rio::estacion_llena(string id_estacion){
        bool result = false;
        auto it = dicc_estacion.find(id_estacion);
        if (it != dicc_estacion.end()) {
        result = it->second.estacion_llena();
    }
    return result;
    }

    // Lectura i escriptura


   // Metodes propis