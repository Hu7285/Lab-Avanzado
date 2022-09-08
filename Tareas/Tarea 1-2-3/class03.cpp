/* 
 * class03.cpp: Programa para mostrar el uso de la
 * clase VecInt2R.
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#include <cstdlib>
#include <iostream>

#include "VecR2.hpp"

using namespace std;

/* Inicio del programa, se crean instancias de VecR2
 * y se llaman los metodos. */
int main()
{
    /* VecR2 v1(1,0);
    VecR2 v2(0,1);

    cout<<  "v1 = " <<  v1 << endl;
    cout<<  "Magnitud de v1: " << v1.Magnitud() << endl;

    cout<<  "v2 = " <<  v2 << endl;

    VecR2 v3;

    v3 = v1 + v2;

    cout << "v3 = v1 + v2 = " << v3 << endl;

    VecR2 v4;

    v4 = v1 + 2*v2;

    cout << "v4 = v1 + 2*v2 = " << v4 << endl;

    cout << "Producto punto" << endl;
    cout << "v1*v2 = " << v1*v2 << endl;
    cout << "v3*v4 = " << v3*v4 << endl;

    VecR2::Mostar_Polar(true);
    cout<< "Mostar en notacion polar activado" << endl;
    cout<<  "v1 = " <<  v1 << endl;
    cout<<  "v2 = " <<  v2 << endl;
    cout << "v3 = " <<  v3 << endl;
    cout << "v4 = " <<  v4 << endl; */

    //-----------------------------------------------------------------------------------------------------
    //De Tarea, Para el vector en R3

    //Definiendo los vectores en cartesianas
    VecR3 v1(1,1,1);
    VecR3 v2(2,2,2);

    //Mostrando los vectores y sus magnitudes
    cout << "vector 1 = " << v1 << endl;
    cout << "vector 2 = " << v2 << endl;
    cout << "Magnitud de V1 = " << v1.Magnitud() << endl;
    cout << "Magnitud de V2 = " << v2.Magnitud() << endl;

    //Suma
    VecR3 sumv3;
    sumv3 = v1 + v2;
    cout << "Suma: v1+v2 = " << sumv3 << endl;

    //Resta
    VecR3 resv4;
    resv4 = v1 - v2;
    cout << "Resta: v1-v2 = " << resv4 << endl;

    //Negacion
    VecR3 negv5;
    negv5 = -v1;
    cout << "Negacion de v1 = " << negv5 << endl;

    //Producto punto
    cout << "Producto punto v1*v2 = " << v1 * v2 << endl;

    //Vector por escalar
    VecR3 escv6;
    escv6 = v1 * 5;
    cout << "Producto v1*5 = " << escv6 << endl;

    //Division
    VecR3 divv7;
    divv7 = v1 / 5;
    cout << "Division v1/5 = " << divv7 << endl;

    //Producto cruz
    VecR3 cruzv8;
    cruzv8 = v1 % v2;
    cout << "Producto Cruz v1%v2 = " << cruzv8 << endl;

    //Comparacion
    v1 == v2;

    //Conversion a esfericas
    VecR3::Mostrar_esfericas(true);
    cout << "En esfericas, los vectores son:" << endl;
    cout << "Vector 1 = " << v1 << endl;
    cout << "Vector 2 = " << v2 << endl;

    return 0;
}