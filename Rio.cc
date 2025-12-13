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

    pair<string, pair<double,int>> Rio::asignar_estacion_aux(const BinTree<string>& rio, int prof){
    if (rio.empty()){
        return make_pair("", make_pair(2.0, -1)); // ocupación imposible
    }

    auto rio_left  = asignar_estacion_aux(rio.left(), prof + 1);
    auto rio_right = asignar_estacion_aux(rio.right(), prof + 1);

    double ocupacio =
        double(dicc_estacion.at(rio.value()).consultar_aforo()) /
        dicc_estacion.at(rio.value()).consultar_capacidad_total();

    pair<string, pair<double,int>> actual =
        make_pair(rio.value(), make_pair(ocupacio, prof));

    // Empezamos suponiendo que el mejor es el actual
    auto mejor = actual;

    // Comparación con el hijo izquierdo
    if (rio_left.first != "") {
        if (rio_left.second.first < mejor.second.first ||
           (rio_left.second.first == mejor.second.first &&
            rio_left.second.second < mejor.second.second)) {
            mejor = rio_left;
        }
    }

    // Comparación con el hijo derecho
    if (rio_right.first != "") {
        if (rio_right.second.first < mejor.second.first ||
           (rio_right.second.first == mejor.second.first &&
            rio_right.second.second < mejor.second.second)) {
            mejor = rio_right;
        }
    }

    return mejor;
}


    void Rio::asignar_estacion(string id_barca, Cjt_barcas& mis_barcas){
     if (mis_barcas.existe_barca(id_barca)){
        cout << "error: la barca ya existe" << endl;
    } else if (plazas_disp < 1){
        cout << "error: no hay plazas libres" << endl;
    } else {
        pair<string, pair<double,int>> result = asignar_estacion_aux(rio, 0);
        cout << result.first << endl;
        alta_barca(id_barca, result.first, mis_barcas);
    }
    }

    void Rio::subir_en_nodo(Cjt_barcas& mis_barcas, const BinTree<string>& rio){
    if (rio.left().empty() or rio.right().empty()) return;

    auto it_left  = dicc_estacion.find(rio.left().value());
    auto it_right = dicc_estacion.find(rio.right().value());
    auto it       = dicc_estacion.find(rio.value());

    while ( it->second.consultar_capacidad() >= 2 &&
            it_left->second.consultar_aforo() > 0 &&
            it_right->second.consultar_aforo() > 0 ) {

        string b1 = it_left->second.consultar_idBarca_petit();
        string b2 = it_right->second.consultar_idBarca_petit();

        it_left->second.baja_barca_est(b1);
        it_right->second.baja_barca_est(b2);

        it->second.alta_barca_est(b1);
        it->second.alta_barca_est(b2);

        mis_barcas.mover_barca(b1, it->first);
        mis_barcas.mover_barca(b2, it->first);
    }
}


    void Rio::subir_barcas(Cjt_barcas& mis_barcas){
    queue<BinTree<string>> q;
    q.push(rio);

    while (!q.empty()){
        BinTree<string> act = q.front();
        q.pop();

        if (!act.empty()){
            subir_en_nodo(mis_barcas, act);
            q.push(act.left());
            q.push(act.right());
        }
    }
}



    Rio::Rio(){
        plazas_disp = 0;
        rio = construir_arbol();
    }

    // Modificadores

    void Rio::alta_barca(string id_barca, string id_estacion, Cjt_barcas& mis_barcas){
        if (mis_barcas.existe_barca(id_barca)){
            cout << "error: la barca ya existe" << endl;
        } else {
        auto it = dicc_estacion.find(id_estacion);
        if (it == dicc_estacion.end()) {
         cout << "error: la estacion no existe" << endl;
        } else if (it->second.estacion_llena()) {
         cout << "error: la barca no cabe" << endl;
        } else {
        mis_barcas.alta_barca_cjt(id_barca, id_estacion);
        --plazas_disp;
         it->second.alta_barca_est(id_barca);
        }
        }
    }

    void Rio::baja_barca(string id_barca, Cjt_barcas& mis_barcas){
    if (mis_barcas.existe_barca(id_barca)){
        string id_est_ant = mis_barcas.estacion_barca(id_barca);
        auto it = dicc_estacion.find(id_est_ant);
        it->second.baja_barca_est(id_barca);
        mis_barcas.baja_barca_cjt(id_barca);
        ++plazas_disp;
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
            if (id_est_actual == id_estacion){
                cout << "error: la barca ya esta en el sitio" << endl;
            } else {
                auto it_actual = dicc_estacion.find(id_est_actual);
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
        if (it->second.consultar_aforo() <= nueva_cap){
            int diff = nueva_cap - it->second.consultar_capacidad_total();
            plazas_disp += diff;
            it->second.nueva_capacidad(nueva_cap);
        } else {
            cout << "error: capacidad insuficiente" << endl;
        }
    }
    }

    // Consultores
    
    void Rio::barca_estacion(string id_estacion){
        auto it =dicc_estacion.find(id_estacion);
        if (it != dicc_estacion.end()){
            it->second.imprimir_barcas();
        } else {
            cout << "error: la estacion no existe" << endl;
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