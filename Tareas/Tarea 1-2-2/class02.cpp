/* 
 * clase02.cpp: Programa para mostrar el uso de la
 * clase persona.
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#include <cstdlib>
#include <iostream>
#include "persona.hpp"

using namespace std;

/* Programa para mostrar el uso de la clase persona. 
 * Se crean instancia y llaman metodos para experimentar
 * que pasa. */
int main()
{
    persona Fulano;

    Fulano.Decir_Nombre();
    Fulano.Decir_origen();
    Fulano.Decir_edad();

    persona Juan("Juan Perez", 1980, 7, 2, "Capital");
    //De tarea
    persona Hugo( "Hugo Cardona", 1999, 7, 19, "USA" );
    
    Juan.Decir_Nombre();
    Juan.Decir_origen();
    Juan.Decir_edad();
    Juan.Asignar_DPI("1980130130101");
    
    //De Tarea
    Hugo.Asignar_DPI( "1234 12345 1234" );
    Hugo.Asignar_Nombre( "Galileo" );
    Hugo.Asignar_Lugar_Origen( "Guatemala" );
    Hugo.Obtener_Nombre();
    Hugo.Obtener_Lugar_Nacimiento();
    Hugo.Obtener_Dia_Nacimiento();
    Hugo.Obtener_Mes_Nacimiento();
    Hugo.Obtener_Anio_Nacimiento();
    Hugo.Decir_Nombre();
    Hugo.Decir_origen();
    Hugo.Decir_edad();

    persona* Maria = new persona("Maria Gomez", 1990, 12, 3, "Zacapa");

    persona::LLamar_Todos();

    delete Maria;

    persona::LLamar_Todos();

    return 0;
}