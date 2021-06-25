/** @file TreeCode.hh
 @brief Especificación de la clase TreeCode
 */


#ifndef TREE_CODE_HH
#define TREE_CODE_HH

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <set>
#include <string>
#include <map>
#include <iostream>
using namespace std;
#endif

/*
 * Clase TreeCode
 */

/** @class TreeCode
 @brief Representa el árbol de códigos (treecode) y la codificación de cada carácter de la tabla de frecuencias de un Idioma en concreto.
 */

class Tree_Code {
    
private:
     /** @brief struct que me permite ordenar mi set en orden ascendente de frecuencia y en caso de empate en orden ascendente lexicográfico */
    struct comp{
        bool operator ()(const BinTree<pair<string, int> >& a1, const BinTree<pair<string, int> >& a2) const{
            if (a1.value().second != a2.value().second)
                return a1.value().second < a2.value().second;
            else return a1.value().first < a2.value().first;
        }
    };
     /** @brief set de arboles que servirá para crear el treecode */
    set <BinTree<pair<string, int> >, comp > conjunto;
     /** @brief Árbol a partir del cual obtendré la codficiación de los carácteres*/
    BinTree <pair<string, int> > treecode;
     /** @brief Donde guardo la codificación de cada carácter */
    map<string, string> codificacion;
     /** @brief Función que me permite obtener la codifciación de cada carácter del idioma a partir del treecode */
    void obtener_codificaciones(const BinTree<pair<string, int> >& treecode, string pos);
     /** @brief Función que me escribe en el canal de salida el treecode en preorden */
    static void preorden(const BinTree<pair<string, int> >& treecode);
     /** @brief Función que me escribe en el canal de salida el treecode en inorden */
    static  void inorden(const BinTree <pair<string, int> >& treecode);
     /** @brief Función auxiliar que me serivirá para decodificar */
    void traduccion(const string& texto, const BinTree <pair<string, int> >& aux, int& i, string& carac, bool& b, int& ultima_pos) const;
    /** @brief Función que me crea el árbol de códigos (treecode) */
    void crear_arbol();
    
public:
   
    // Constructora
    /** @brief Creadora por defecto
     @pre cierto
     @post el resultado es un treecode vacío.
     */
    Tree_Code();
    
    //Modificadoras
    
    /** @brief Modificadora que crea el árbol de códigos (treecode) y obtiene las codificaciones de cada carácter (el string) de la tabla.
     @pre cierto
     @post se ha creado el árbol y se han obtenido las codificaciones correspondientes  siguiendo el proceso especificado en el enunciado de la práctica
     */
    void get_code(const map<string, int>& tabla);
    // Escritura
    
    /** @brief Operación de escritura de la codificación de un caráccter en concreto
     \pre cierto
     \post En el caso de que el carácter exista en el parámetro implícito, se ha esribe su codificiación en el canal de salida.en caso contrario, se informa de la situación.
     */
    void consultar_caracter(string caracter) const;
   
    /** @brief Operación de escritura de la codificación de todos los caracteres del parametro implicito
     \pre cierto
     \post se han escrito por el canal de salida todo los carácteres con sus respectivas codificaciones
     */
    void escribe_codigos() const;
    
    
    /** @brief Operación de escritura del treecode del parametro implícito
     \pre cierto
     \post se ha escrito por el canal de salida el treecode en preorden y en inorden
     */
    void consulta_treecode()const ;
    
    /** @brief Operación de escritura de la codificación de un texto
     \pre cierto
     \post se ha escrito por el canal de salida la codficiación del texto en caso de que fuera posible. En caso contrario, se ha informado de la situación.
     */
    void codifica(const string& texto) const;
    /** @brief Operación de escritura de la decodificación de un texto
     \pre cierto
     \post se ha escrito por el canal de salida la decodficiación del texto en caso de que fuera posible. En caso contrario, se ha informado de la situación.
     */
    void decodifica(const string& texto) const;

};
#endif
