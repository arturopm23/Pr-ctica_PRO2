#include "Rio.hh"
    // Constructores

    BinTree<string> Rio::construir_arbol(){
        string id;
        int capacitat;
        cin >> id >> capacitat;
        if (id == "#"){
            return BinTree<string>();
        }
        Estacion e(id, capacitat);
        dicc_estacion.insert({id, e});
        BinTree<string> left = construir_arbol();
        BinTree<string> right = construir_arbol();
        return BinTree<string>(id, left, right);
    }

    Rio::Rio(){
        rio = construir_arbol();
    }
    /* Pre: cert */
    /* Post: el resultat es un riu amb les seves estacions*/

    // Modificadores

    void Rio::alta_barca(string id_barca, string id_estacion, Cjt_barcas& mis_barcas){
        auto it = dicc_estacion.find(id_estacion);
        if (it == dicc_estacion.end()) {
         cout << "error: la estacion no existe" << endl;
        } else if (it->second.estacion_llena()) {
         cout << "error: la barca no cabe" << endl;
        } else {
        if (mis_barcas.alta_barca_cjt(id_barca, id_estacion)){
         it->second.alta_barca_est(id_barca);
        }
    }
    }
    /* Pre: la barca no existeix i la estacio no esta plena */
    /* Post: afegim la nova barca a la estacio*/

    void Rio::baja_barca(string id_barca, Cjt_barcas& mis_barcas){
    if (mis_barcas.existe_barca(id_barca)){
        string id_est_ant = mis_barcas.estacion_barca(id_barca);
        auto it = dicc_estacion.find(id_est_ant);
    if (it != dicc_estacion.end()) {
            it->second.baja_barca_est(id_barca);
        }
        mis_barcas.baja_barca_cjt(id_barca);
    } else {
        cout << "error: la barca no existe" << endl;
    }
    }
    /* Pre: la barca existeix */
    /* Post: esborrem la barca de la estacio*/

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
    /* Pre: la barca existeix, la estació destí és diferent de l'origen, la estació destí no està plena */
    /* Post: esborrem la barca de la estacio d'origen i l'afegim al destí*/

    void Rio::modificar_capacidad(string id_estacion, int nueva_cap){
        auto it = dicc_estacion.find(id_estacion);  // FIXED: Use find
    if (it == dicc_estacion.end()) {
        cout << "error: la estacion no existe" << endl;
    } else {
        it->second.nova_capacitat(nueva_cap);
    }
    }
    /* Pre: la estacio existeix, la nova capacitat es >= nº barcas actual */
    /* Post: la estacio te la nova capacitat*/

    void Rio::subir_barcas(Cjt_barcas& mis_barcas){}
    /* Pre: cert */
    /* Post: Intentarem afegir a una estació pare parells de barques de les filles
    fins que la estació para s'ompli o una de les filles es buidi*/

    string Rio::asignar_estacion(string id_barca, Cjt_barcas& mis_barcas){
        return ";";
    }
    /* Pre: la barca no existeix i tenim espai */
    /* Post: Assignem la barca a una nova estació amb menys ocupació
    (pl.ocupades/pl.totals) retorna l'id de la estació destí*/

    // Consultores
    
    void Rio::barca_estacion(string id_estacion){}
    /* Pre: la estacio existeix */
    /* Post: imprimim les barques de la estacio*/

    void Rio::plazas_libres(){}
    /* Pre: cert */
    /* Post: imprimim el numero de places lliures*/

    bool Rio::existe_estacion(string id_estacion){
        return dicc_estacion.count(id_estacion);
    }
    /* Pre: id d'una estacio */
    /* Post: retorna true si al conjunt existeix una estacio amb id_estacion*/

    bool Rio::estacion_llena(string id_estacion){
        bool result = false;
        auto it = dicc_estacion.find(id_estacion);
        if (it != dicc_estacion.end()) {
        result = it->second.estacion_llena();
    }
    return result;
    }
    /* Pre: la estacio existeis*/
    /* Post: retorna true si la estacio esta plena*/


    // Lectura i escriptura


   // Metodes propis