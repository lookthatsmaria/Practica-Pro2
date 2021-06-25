/** @file Cjt_Idiomas.cc
 @brief Código de la clase Cjt_Idiomas
 */

#include "Cjt_Idiomas.hh"



Cjt_Idiomas::Cjt_Idiomas(){}



void Cjt_Idiomas::modificar_conjunto(const string& identificador_idioma){
    //Busca el idioma en el conjunto y en el caso que no esté lo añade. En caso
    //contrario, se modifica el idioma. Para modifcarlo, llama a una función de la
    //clase Idioma.
    map<string, Idioma>::iterator it;
    it = idiomas.find(identificador_idioma);
    if (it == idiomas.end()) {
        Idioma nuevo;
        nuevo.leer_tabla();
        idiomas.insert(make_pair(identificador_idioma, nuevo));
        cout << "Anadido " << identificador_idioma<< endl;
        cout << endl;
    }
    else {
        (*it).second.modificar_idioma();
        cout << "Modificado " << identificador_idioma << endl;
        cout << endl;
    }
    
    
    
}

pair<bool, Idioma> Cjt_Idiomas::consultar_idioma(string nombre) const{
    //Busca el idioma en el conjunto y devuleve si escierto que está o no y si
    //está, devuelve el idioma
    map<string, Idioma>::const_iterator it;
    it = idiomas.find(nombre);
    pair<bool, Idioma> consulta;
    bool existe = (it != idiomas.end());
    consulta.first = existe;
    if (existe) consulta.second = (*it).second;
    return consulta;
}


void Cjt_Idiomas::leer_conjunto(){
    //Esta operación actualiza el conjunto, leyéndolos del canal estándard.
    int numero_idiomas; //número de idiomas que se van a añadir en el conunto
    cin >> numero_idiomas;
    for(int i = 0; i < numero_idiomas; ++i){
        string iden;
        cin >> iden;
        Idioma idi;
        idi.leer_tabla();
        idiomas.insert(make_pair(iden, idi));
    }
}





void Cjt_Idiomas::codif(const string& identificador_idioma, const string& texto) const{
    //Esa operación simplemente busca el idioma en el conjunto y en el caso de que
    //no esté informa del caso. En caso contrario, si el texto es codificable en
    //el idioma en concreto, se escribe su codificación por el canal de salida.
    //Para ello llama a otra función de la clase Idioma.
    
    map<string, Idioma>::const_iterator it;
    it = idiomas.find(identificador_idioma);
    if (it == idiomas.end()){
        cout << "El idioma no existe" << endl;
        cout << endl;
    }
    else (*it).second.code(texto);
}

void Cjt_Idiomas::codig(const string& nombre, const string& condicion) const{
    //Esa operación simplemente busca el idioma en el conjunto y en el caso de que
    //no esté informa del caso. En caso contrario, dependiendo de la condición, se
    //escribe por el canal estàndard de salida la codificación de todos los
    //caracteres del idioma en concreto o solo la de un carácter si es que es
    //posible (si no es posible, se informa de la situación).
   
    map<string, Idioma>::const_iterator it;
     it = idiomas.find(nombre);
    if (condicion == "todos"){
        cout << "Codigos de " << nombre <<":" << endl;
       if (it == idiomas.end()){
            cout << "El idioma no existe" << endl;
        }
        else (*it).second.consultar_codigos();
    }
    else {
        cout << "Codigo de " << condicion << " en " << nombre << ":" <<endl;
        if (it == idiomas.end()) cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
        else (*it).second.consultar_codigo(condicion);
    }
    cout << endl;
}

