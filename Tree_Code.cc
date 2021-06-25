/** @file Tree_Code.cc
 @brief Código de la clase Tree_code
 */

#include "Tree_Code.hh"

Tree_Code::Tree_Code(){}

void Tree_Code::get_code(const map<string, int>& tabla){
    //Se trata de obtener el treecode y la codifciion a partir de la tabla proporcionada.
    //Para ello, borramos el set y el mapa con las codificaciones por si previamente ya
    //se habia obtenido y se quiere crear otra vez con una tabla nueva.
    conjunto.clear();
    codificacion.clear();
    //Sea n el tamaño de la tabla, se crean n arboles binarios de pares, cada uno formado por un
    //solo nodo y se añaden al set.
    for (map <string, int>::const_iterator it = tabla.begin(); it != tabla.end(); ++it){
        BinTree<pair<string, int> > par(*it);
        conjunto.insert(par);
    }
    crear_arbol();
    string pos;
    obtener_codificaciones(treecode, pos);
}

void Tree_Code::crear_arbol(){
    //El numero de arboles del set se reducen 1 llamado treecode, aplicando N-1 (siendo n el tamaño
    //inical del set) los pasos siguiente:
    
    // 1) sean a1 y a2, respectivamente, el árbol con raíz más pequeña y el árbol con la segunda
    //raíz más pequeña respecto al siguiente criterio: si las frecuencias no son iguales, es más
    //pequeña la raíz con la frecuencia más pequeña; en caso de empate, es más pequeña la raíz con
    //la string (el carácter) más pequeña en orden lexicográfico.
    
    //2)los árboles a1 y a2 se eliminan y se sustituyen por un tercero (b) cuya raíz contiene la
    //suma de los enteros (frecuencias) de las raíces de a1 y a2 y la concatenación de sus strings
    //(primero, la más pequeña); los subárboles de b son a1, como subárbol izquierdo, y a2, como
    //subárbol derecho
    if (conjunto.size() == 1) treecode = (*conjunto.begin());
    else {
        const BinTree<pair<string, int> > izd = (*conjunto.begin());
        conjunto.erase((*conjunto.begin()));
        const BinTree<pair<string, int> > der = (*conjunto.begin());
        conjunto.erase((*conjunto.begin()));
        string nuevo_s;
        if (izd.value().first < der.value().first){
            nuevo_s = izd.value().first;
            nuevo_s  += der.value().first;
        }
        else {
            nuevo_s = der.value().first;
            nuevo_s  += izd.value().first;
        }
        pair<string, int> nuevo(nuevo_s, izd.value().second + der.value().second);
        BinTree<pair<string, int> > nuevo_arbol(nuevo, izd, der);
        conjunto.insert(nuevo_arbol);
        crear_arbol();
    }
}

void Tree_Code::obtener_codificaciones(const BinTree<pair<string, int> >& treecode, string pos){
    //Se asigna a cada carácter x (cada caraácter que forma parte de la tabla) el código formado
    //por el camino en el treecode desde la raíz hasta x (0=izquierda, 1=derecha)
    if (treecode.empty()) return;
    //x siempre será una hoja
    if (treecode.left().empty() and treecode.right().empty()) {
        codificacion.insert(make_pair(treecode.value().first, pos));
    }
    else {
        obtener_codificaciones(treecode.left(), pos + '0');
        obtener_codificaciones(treecode.right(), pos + '1');
    }
}

void Tree_Code::consultar_caracter(string caracter) const{
    map<string, string>::const_iterator it;
    it = codificacion.find(caracter);
    if (it != codificacion.end()) cout << caracter << " " << (*it).second << endl;
    else cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
}

void Tree_Code::escribe_codigos() const{
    for (map<string, string>::const_iterator it = codificacion.begin(); it != codificacion.end(); ++it){
        cout << (*it).first << " " << (*it).second << endl;
        
    }
}

void Tree_Code::consulta_treecode() const{
    cout << "recorrido en preorden:" << endl;
    preorden(treecode);
    
    cout << "recorrido en inorden:" << endl;
    inorden(treecode);
    cout << endl;
    
}

void Tree_Code::preorden(const BinTree <pair<string, int> >& treecode) {
    if (not treecode.empty()) {
        pair <string, int > x = treecode.value();
        cout << x.first << " " << x.second << endl;
        preorden(treecode.left());
        preorden(treecode.right());
    }
}

void Tree_Code::inorden(const BinTree <pair<string, int> >& treecode) {
    if (not treecode.empty()){
        pair <string, int > x = treecode.value();
        inorden(treecode.left());
        cout << x.first << " " << x.second << endl;
        inorden(treecode.right());
    }
}


void Tree_Code::codifica(const string& texto) const{
    bool encontrado = true;
    int i = 0;
    map<string, string>::const_iterator it;
    string codi;
    string cambio;
    bool especial;//indica si el char es de tamaño 2 o no
    while(i < texto.size() and encontrado){
        if (texto[i] >= 0){
            cambio = string(1, texto[i]);
            especial = false;
        }
        else if (texto[i] < 0) {
            cambio = string (texto, i, 2);
            especial = true;
        }
        it = codificacion.find(cambio);
        if (it != codificacion.end()) {
            codi += it -> second;
            if (especial) i += 2;
            else ++i;
        }
        else if (it == codificacion.end()) encontrado = false;
    }
    if (encontrado) cout << codi << endl;
    else cout <<"El texto no pertenece al idioma; primer caracter que falla: " << texto[i] << endl;
    cout << endl;
}



void Tree_Code::decodifica(const string& texto) const{
    BinTree <pair<string, int> > aux = treecode;
    string carac; //donde guardamos la decodificación
    int i = 0;
    bool b;//indica si se puede decodificar o no el texto en concreto
    int last_pos = 0; //Guarda la ultima posición válida que se ha podido decodificar
    traduccion(texto, aux, i, carac, b, last_pos);
    if (b)
        cout << carac << endl;
    else
        cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << last_pos << endl;
    cout << endl;
    
}

void Tree_Code::traduccion(const string& texto, const BinTree <pair<string, int> >& aux, int& i, string& carac, bool& b, int& ultima_pos) const{
    //Se trata de buscar el camino siguiendo cada caracter del texto (los unos y los ceros) hasta llegar a la raiz. El proceso se repite hasta el que se haya recorrido todo el string (el tecto)
    if (i == texto.size()){
        carac += aux.value().first;
        if (aux.left().empty() and aux.right().empty()) {
            b = true;
            ultima_pos = i;
        }
        else b = false;
        return;
    }
    if (i < texto.size()){
        if (aux.left().empty() and aux.right().empty()) {
            carac += aux.value().first;
            ultima_pos = i;
            traduccion(texto, treecode, i, carac, b, ultima_pos);
        }
        else  {
            if (texto[i] == '0') traduccion(texto, aux.left(), ++i, carac, b, ultima_pos);
            else if (texto[i] == '1') traduccion(texto, aux.right(), ++i, carac, b, ultima_pos);
        }
    }
}


