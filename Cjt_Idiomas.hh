/** @file Sistema.hh
 @brief Especificación de la clase Cjt_Idiomas
 */


#ifndef CJT_IDIOMAS_HH
#define CJT_IDIOMAS_HH


#include "Idioma.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
using namespace std;
#endif

/*
 * Clase Cjt_Idiomas
 */

/** @class Cjt_Idiomas
 @brief Representa el conjunto de idiomas.
 
 Ofrece operaciones para añadir un idioma en el conjunto, de lectura y escritura del conjunto.
 */

class Cjt_Idiomas {
    // Descripción: contiene los idiomas que están presentes en el
    // conjunto y las operaciones necesarias para gestionarlos
private:
    
    /* Como cada idioma tiene su identificador único, usaremos un mapa, de esta manera estarán
     ordenados crecientemente (lexicográficamente) por orden de identificador, para facilitar
     las operaciones del módulo. */
    
    /** @brief Mapa del conjunto de idiomas.
     
     Ordenada crecientemente por el id de sus componentes */
    map<string, Idioma> idiomas;
    
    
    
public:
    // Constructora
    /** @brief Creadora por defecto
     @pre cierto
     @post El resultado es un conjunto de idiomas vacío.
     */
    Cjt_Idiomas();
    
    //Modificadoras
    
    
    /** @brief Modificadora del conjunto
     \pre cierto
     \post El parámetro implícito ha añadido el idioma nuevo en su conjunto en el caso de que no estuviera previamente, en caso contrario se ha modificado el idioma.
     */
    void modificar_conjunto(const string& identificador_idioma);
   
    //Consultoras
    
    /** @brief Consultora de la existencia del idioma en el conjunto
     \pre cierto
     \post El parametro implícito devuelve un booleano que es verdadero en el caso de que exista el idioma en el conjunto con ese nombre (identificador) y el idioma.
     */
    pair<bool, Idioma> consultar_idioma(string nombre) const;
    
    
    
    // Entrada / Salida
    
    /** @brief Operación de lectura
     \pre El canal estándard de entrada contiene un entero M > 0 seguido de los datos de M idiomas
     \post El parámetro implícito está formado por los M idiomas procedentes del canal estándard de entrada.
     */
    void leer_conjunto();
    
    
    /** @brief Operación de escsritura de la codificación de un texto en un cierto idioma
     \pre texto es el string que se quiere codificar en el idioma con el identificador identificador_idioma
     \post El parámetro implícito en el caso de que el idioma no existiera o el texto no fuera codificable en el idioma en concreto, se ha informado de la situación por el canal de salida. En caso contrario, se ha escrito en el canál de salida su codificación.
     */
    void codif(const string& identificador_idioma, const string& texto) const;
    /** @brief Operación de escsritura de la codificación de un caracter o de todos los caracteres del idioma
     \pre nombre es el identificador del idioma y condicion nos indica si queremos escribir la codificación de todos los carácteres del idioma o solo uno en concreto
     \post El parámetro implícito en el caso de que el idioma no existiera o el caracter en conctreo no existiera en el idioma, se ha informado de la situación por el canal de salida. En caso contrario, se ha escrito en el canál de salida la codificación de todos los caracteres del idioma o solo el del caracter en concreto según la condición.
     */
     void codig(const string& nombre, const string& condicion) const;
};
#endif
