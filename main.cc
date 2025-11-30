#include <iostream>
#include "Cjt_barcas.hh"
#include "Rio.hh"

using namespace std;

int main()
{
    string op;
    Rio rio;
    Cjt_barcas mis_barcas;

    while (cin >> op and op != "fin")
    {
        if (op == "alta_barca" or op == "ab")
        {
            string id_barca, id_estacion;
            cin >> id_barca;
            cin >> id_estacion;
            cout << "#ab " << id_barca << " " << id_estacion << endl;
            rio.alta_barca(id_barca, id_estacion, mis_barcas); // Creem la nova instància barca i l'afegim la barca al conjunt total de barques. Afegim la barca a la seva estació
        }
        else if (op == "baja_barca" or op == "bb")
        {
            string id_barca;
            cin >> id_barca;
            cout << "#bb " << id_barca << endl;
            rio.baja_barca(id_barca, mis_barcas); // Esborrem l'id de la barca del conjunt. Esborrem la barca del set de la seva estació
        }
        else if (op == "estacion_barca" or op == "eb")
        {
            string id_barca;
            cin >> id_barca;
            cout << "#eb " << id_barca << endl;
            mis_barcas.imprimir_estacion_barca(id_barca); //Imprimim en què estació està la barca
        }
        else if (op == "viajes_barca" or op == "vb")
        {
            string id_barca;
            cin >> id_barca;
            cout << "#vb " << id_barca << endl;
            mis_barcas.viajes_barca(id_barca); //Imprimim els viatjes q ha fet la barca
        }
        else if (op == "mover_barca" or op == "mb")
        {
            string id_barca, id_estacion;
            cin >> id_barca;
            cin >> id_estacion;
            cout << "#mb " << id_barca << " " << id_estacion << endl;
            rio.mover_barca(id_barca, id_estacion, mis_barcas); //Canviem l'id_estacio actual de la barca i afegim el viatje. Actualitzem el set de la estació origen i destí
        }
        else if (op == "barcas_estacion" or op == "be"){
            string id_estacion;
            cin >> id_estacion;
            cout << "#be " << id_estacion << endl;
            rio.barca_estacion(id_estacion); //Imprimim els id de les barques de la estacio
        }
        else if (op == "modificar_capacidad" or op == "mc"){
            string id_estacion;
            int nueva_cap;
            cin >> id_estacion;
            cin >> nueva_cap;
            cout << "#mc " << id_estacion << " " << nueva_cap << endl;
            rio.modificar_capacidad(id_estacion, nueva_cap); //Canviem la capacitat d'una estació del rio
        }
        else if (op == "plazas_libres" or op == "pl"){
            cout << "#pl" << endl;
            rio.plazas_libres(); //Imprimim el nº total de places lliures de totes les estacions del riu
        }
        else if (op == "subir_barcas" or op == "sb"){
            cout << "#sb" << endl;
            rio.subir_barcas(mis_barcas); // Reestructurem les ubicacions de les barques en parells
        }
        else if (op == "asignar_estacion" or op == "ae"){
            string id_barca;
            cin >> id_barca;
            cout << "#ae " << id_barca << endl;
            rio.asignar_estacion(id_barca, mis_barcas); //Assignem la barca a la nova estació segons el criteri d'ocupació
        }
    }
}