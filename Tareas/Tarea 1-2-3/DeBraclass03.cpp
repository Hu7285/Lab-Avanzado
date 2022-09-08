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

#include "DeBraVecR2.hpp"

using namespace std;

/* Inicio del programa, se crean instancias de VecR2
 * y se llaman los metodos. */
int main()
{
    //*******************************************VECTORES R3*********************************************
    /*VecR2 v1(1,0);
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
    cout << "v4 = " <<  v4 << endl;*/

    //*****************************************VECTORES R3*********************************************
    VecR3 vv1(2,2,2);
    VecR3 vv2(1,1,1);

    //Imprimir los vectores con sus magnitudes respectivas
    cout<<  "vv1 = " <<  vv1 << endl;
    cout<<  "Magnitud de vv1: " << vv1.magnitud() << endl;
    cout<<  "vv2 = " <<  vv2 << endl;
    cout<<  "Magnitud de vv2: " << vv2.magnitud() << endl;

    //Suma de vectores
    VecR3 vv3;
    vv3 = vv1 + vv2;
    cout << "vv3 = vv1 + vv2 = " << vv3 << endl;

    //Suma y producto escalar
    VecR3 vv4;
    vv4 = vv1 + 2*vv2;
    cout << "vv1 + 2*vv2 = " << vv4 << endl;

    //Producto de vector por escalar
    cout << vv1*2 <<endl;

    //Producto cruz
    VecR3 vv5;
    vv5 = vv1%vv2;
    cout << "vv1%vv2 = " << vv5 << endl;

    //Producto punto
    VecR3 vv8;
    cout<<vv1*vv2<<endl;

    //Resta de vectores
    VecR3 vv6;
    vv6 = vv1 - vv2;
    cout << "vv3 = vv1 - vv2 = " << vv6 << endl;

    //Division por ecalar
    VecR3 vv7;
    vv7 = vv1/2;
    cout << "vv1/2" << vv7 << endl;

    //Negacion de un vector

    cout<<-vv1<<endl;

    //Comparacion de dos vectores
    vv1 == vv2;

    //Trabajando los vectores en esfericas
    VecR3::Mostar_esferico(true);
    cout<< "Mostar en notacion esferica activado" << endl;
    cout<<  "vv1 = " <<  vv1 << endl;
    cout<<  "vv2 = " <<  vv2 << endl;



    


    return 0;
}