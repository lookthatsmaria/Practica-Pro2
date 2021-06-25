/** @mainpage
 
 
 
 El programa principal se encuentra en el módulo program.cc.
 Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos un
 módulo para representar el conjunto de idiomas donde se agruparán todos
 , otro para el tipo idioma y otro para el tipo Treecode.
 
 
 */

/** @file program.cc
 
 @brief Programa principal
 
 Estamos suponiendo que los datos leídos siempre son correctos, ya que
 no incluímos comprobaciones al respecto.
 */




#include "Cjt_Idiomas.hh"
#include "Idioma.hh"


int main(){
    Cjt_Idiomas conj;
    conj.leer_conjunto();
    Idioma i;
    string identificador_idioma, texto, op; //Siendo op la operación a realizar
    cin >> op;
    while(op != "fin"){
        if (op == "anadir/modificar"){
            cin >> identificador_idioma;
            conj.modificar_conjunto(identificador_idioma);
        }
       
        if (op == "codifica"){
            cin >> identificador_idioma>> texto;
            cout << "Codifica en " << identificador_idioma << " el texto:" << endl;
            cout << texto << endl;
            conj.codif(identificador_idioma, texto);
        }
        if (op == "decodifica"){
            cin >> identificador_idioma >> texto;
            cout << "Decodifica en " << identificador_idioma<< " el texto:" << endl;
            cout << texto << endl;
            pair<bool, Idioma> existe = conj.consultar_idioma(identificador_idioma);
            if(not existe.first){
                cout << "El idioma no existe" << endl;
                cout << endl;
            }
            else
                (existe.second).decode(texto);
            
        }
        if (op == "tabla_frec"){
            cin >> identificador_idioma;
            cout << "Tabla de frecuencias de " << identificador_idioma << ":" << endl;
            pair<bool, Idioma> existe = conj.consultar_idioma(identificador_idioma);
            if(not existe.first){
                cout << "El idioma no existe" << endl;
                cout << endl;
            }
            else
                (existe.second).consultar_tabla();
           
        }
        if (op == "treecode"){
            cin >> identificador_idioma;
            cout << "Treecode de " << identificador_idioma<< ":" << endl;
            pair<bool, Idioma> existe = conj.consultar_idioma(identificador_idioma);
            if(not existe.first){
                cout << "El idioma no existe" << endl;
                cout << endl;
            }
            else{
                
                (existe.second).consultar_arbol();
            }
           
        }
        if (op == "codigos"){
            string condicion;
            cin >> identificador_idioma >> condicion;
            conj.codig(identificador_idioma, condicion);
            
        }
        cin >> op;
    }
}
