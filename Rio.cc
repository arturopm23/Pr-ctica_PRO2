#include "Rio.hh"
    // Constructores

    Rio::Rio(){
    }
    /* Pre: cert */
    /* Post: el resultat es un riu amb les seves estacions*/

    // Modificadores

    void Rio::alta_barca(string id_barca, string id_estacion, Cjt_barcas& mis_barcas){}
    /* Pre: la barca no existeix i la estacio no esta plena */
    /* Post: afegim la nova barca a la estacio*/

    void Rio::baja_barca(string id_barca, Cjt_barcas& mis_barcas){}
    /* Pre: la barca existeix */
    /* Post: esborrem la barca de la estacio*/

    void Rio::mover_barca(string id_barca, string id_estacion, Cjt_barcas& mis_barcas){}
    /* Pre: la barca existeix, la estació destí és diferent de l'origen, la estació destí no està plena */
    /* Post: esborrem la barca de la estacio d'origen i l'afegim al destí*/

    void Rio::modificar_capacidad(string id_estacion, int nueva_cap){}
    /* Pre: la estacio existeix, la nova capacitat es >= nº barcas actual */
    /* Post: la estacio te la nova capacitat*/

    void Rio::subir_barcas(Cjt_barcas& mis_barcas){}
    /* Pre: cert */
    /* Post: Intentarem afegir a una estació pare parells de barques de les filles
    fins que la estació para s'ompli o una de les filles es buidi*/

    string Rio::asignar_estacion(string id_barca, Cjt_barcas& mis_barcas){}
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

    bool Rio::existe_estacion(string id_estacion){}
    /* Pre: id d'una estacio */
    /* Post: retorna true si al conjunt existeix una estacio amb id_estacion*/


    // Lectura i escriptura


   // Metodes propis