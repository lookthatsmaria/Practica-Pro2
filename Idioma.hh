#ifndef IDIOMA_HH
#define IDIOMA_HH


#include "Tree_Code.hh"

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif


/*
 * Clase Idioma
 */

/** @class Idioma
 @brief Representa la información y las operaciones asociadas a un idioma.
 
 Sus operaciones son las modificadoras de idioma, la de lectura (lee el idioma) y las de escriptura
 */

class Idioma {
    
    // Descripción: contiene la tabla de frecuencias del idioma y su treecode y las operaciones de un idioma
    
private:
    
    /* Un Organismo se representa mediante su tabla de frecuencias, que será un mapa y su código (representado por un TreeCode*/
    /** @brief Tabla de frecuencias del idioma */
    map <string, int> tabla;
    /** @brief Engloba el árbol y la codificación de cada caracter de la tabla de frecuencias del idioma*/
    Tree_Code codigo;

public:
    
    //Constructora
    /** @brief Creadora por defecto
     \pre cierto
     \post El resultado es un idioma sin tabla ni códigp
     */
    Idioma();
   
    // Modificadoras
    
    /** @brief Modificadora del idioma
     \pre En el canal de entrada se poporciona un entero n que será el numero de entradas de la tabla y a continuación los n caracteres con sus respectivas frecuencias
     \post El parámetro implícito pasa a tener una nueva tabla de frecuencias seguiendo el mñetodo siguiente: en el caso de que el caracter de la tabla proporcionada en el canal de entrada exista en la tabla del idioma en concreto, se modifica su frecuencia sumando la de las dos tablas. En caso contrario se añade a la tabla del idioma la nueva entrada (el cracater con su frecuencia)
      */
    void modificar_idioma();
    
    // Entrada / Salida
    
    /** @brief Operación de lectura
     \pre el canal estándard de entrada contiene un entero M > 0 seguido de los datos de M entradas  de la tabla de freceuncias (carácter con su frecuencia).
     \post El parámetro implícito está formado por la tabla del canal estándard de entrada.
     */
    void leer_tabla();
    
    /** @brief Operación de escritura
     \pre cierto
     \post escribe por el canal de salida la tabla de frecuencia por orden lexicografico ascendente de caracter
     */
    void consultar_tabla() const;
    
    /** @brief Operación de escritura
     \pre cierto
     \post escribe por el canal de salida el arbol (treecode) del idioma en preorden y en inorden
     */
    void consultar_arbol() const;
    
    
    /** @brief Operación de escritura
     \pre condición es el caracter cuyo código queremos obtener.
     \post escribe por el canal de salida la codificación del carácter si es que este existe en el parametro implícito
     */
    void consultar_codigo(const string& condicion) const;
    
    
    /** @brief Operación de escritura
     \pre cierto
     \post escribe por el canal de salida la codificación de cada carácter de la tabla de frecuencias del parametro implícito
     */
    void consultar_codigos() const;
    
    
    /** @brief Operación de escritura
     \pre cierto
     \post escribe por el canal de salida la codificación del texto si es que es posible (en caso de no serlo se informa de la situación.
     */
    void code(const string& texto) const;
   
    /** @brief Operación de escritura
     \pre cierto
     \post escribe por el canal de salida la decodificación del texto si es que es posible (en caso de no serlo se informa de la situación.
     */
    void decode(string texto) const;
    
    
};
#endif

    
