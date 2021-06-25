/** @file Idioma.cc
 @brief Código de la clase Idioma
 */


#include "Idioma.hh"


Idioma::Idioma(){}

void Idioma::modificar_idioma(){
    //Modifica la tabla de frecuencias del parametro implícito y finalmente
    //obtiene su nuevo código. Para ello llama a otra función de la clase
    //TreeCode
    map <string, int>::iterator it = tabla.begin();
    int num;
    cin >> num;
    string car;
    int frec;
    for(int i = 0; i < num; ++i) {
        cin >> car >> frec;
        it = tabla.find(car);
        if (it == tabla.end())
            tabla.insert(make_pair(car, frec));
        else (*it).second += frec;
        }
   codigo.get_code(tabla);
}

void Idioma::leer_tabla(){
    //Se lee la tabla de frecuencias del parámetro implícito y finalmente
    //obtengo su código (su treecode y su codificación).
    int numero_c;
    cin >> numero_c;
    string caracter;
    int frecuencia;
    for(int i = 0; i < numero_c; ++i){
        cin >> caracter >> frecuencia;
        tabla.insert(make_pair(caracter, frecuencia));
        }
    codigo.get_code(tabla);
}

void Idioma::consultar_tabla() const{
    for (map <string, int>::const_iterator it = tabla.begin(); it != tabla.end(); ++it){
        cout << (*it).first << " " << (*it).second << endl;
    }
    cout << endl;
}

void Idioma::consultar_arbol() const{
    codigo.consulta_treecode();
}

void Idioma::consultar_codigo(const string& condicion) const{
    codigo.consultar_caracter(condicion);
}

void Idioma::consultar_codigos() const{
    codigo.escribe_codigos();
}

void Idioma::code(const string& texto) const{
    codigo.codifica(texto);
}

void Idioma::decode(string texto) const{
    codigo.decodifica(texto);
}
