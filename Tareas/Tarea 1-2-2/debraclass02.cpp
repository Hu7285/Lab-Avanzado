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
#include "debrahpp.hpp"

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
    persona Bryant("Bryant Morazan", 1997, 9, 2, "Ciudad de Guatemala" );
    persona Lipe;
    
    Juan.Decir_Nombre();
    Juan.Decir_origen();
    Juan.Decir_edad();
    Juan.Asignar_DPI("1980130130101");
    Juan.Obtener_DPI();
    Bryant.Obtener_lugar();
    Bryant.Asignar_nombre("Eugenio Marroquin");
    Bryant.Obtener_nombre();
    Bryant.Obtener_dia();
    Bryant.Obtener_mes();
    Bryant.Obtener_anio();
    Bryant.Decir_Nombre();
    Lipe.Obtener_lugar();

    persona* Maria = new persona("Maria Gomez", 1990, 12, 3, "Zacapa");

    persona::LLamar_Todos();

    delete Maria;

    persona::LLamar_Todos();

    return 0;
}