/* 
 * VecR2.cpp: Implementacion de la clase VecR2
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#include <iostream>
#include <cmath>

#include "VecR2.hpp"

bool VecR2::Polar = false;

VecR2::VecR2( )
{
    Xcor = 0;
    Ycor = 0;
}

VecR2::VecR2( float valor_x, float valor_y )
{
    Xcor = valor_x;
    Ycor = valor_y;
}

VecR2::~VecR2()
{}

void VecR2::Asignar_x( float valor_x )
{
    Xcor = valor_x;
}

void VecR2::Asignar_y( float valor_y )
{
    Ycor = valor_y;
}

void VecR2::Asignar_xy( float valor_x, float valor_y )
{
    Xcor = valor_x;
    Ycor = valor_y;
}

float VecR2::Obtener_x( ) const
{
    return Xcor;
}

float VecR2::Obtener_y( ) const
{
    return Ycor;
}

float VecR2::Magnitud() const
{
    return std::sqrt( Xcor*Xcor + Ycor*Ycor );
}

/* Sobrecarga de operadores */

/* Calcula la suma de dos vectores */
VecR2 VecR2::operator+( const VecR2 &avec) const
{
    /* Se declara un vector temporal para almacenar los resultados */
    VecR2 tmp;
    /* Uno de los vectores a sumar es el que llama el operador,
     * por lo que se accede a el por el puntero "this". El otro
     * es el que se pasa como argumento.
     * Como se esta dentro de las definiciones de clase, se puede
     * acceder a los atributos privados. */
    tmp.Xcor = this->Xcor + avec.Xcor;
    tmp.Ycor = this->Ycor + avec.Ycor;

    /* Se devuelve la suma de los vectores */
    return tmp;
}

/* Calcula el producto punto de dos vectores */
float VecR2::operator*( const VecR2 &avec ) const
{
    /* Ver los comentarios de operator+ */
    float tmp;

    tmp = this->Xcor * avec.Xcor + this->Ycor * avec.Ycor;

    return tmp;
}

/* Operador de asignacion */
VecR2 VecR2::operator=( const VecR2 &avec)
{
    /* El vector que llama el operador es el que 
     * esta al lado izquierdo de este, y el que
     * esta al lado derecho se pasa como argumento
     * por lo que a "this" se le debe asignar el 
     * valor del argumento */
    this->Xcor = avec.Xcor;
    this->Ycor = avec.Ycor;

    return (*this);
}

/* Metodo de clase: Fija el valor del flag para que
 * el despliege del vector sea en polar (true) o
 * cartesiano (false) */
void VecR2::Mostar_Polar( bool valor )
{
    Polar = valor;
}

/* Funciones amigas. 
 * Estas funciones fueron declarada como amigas (friend) en la 
 * definicion de la clase. Las funciones amigas no son metodos 
 * de los objetos, pero pueden acceder a los atributos privados de
 * estos.*/

/* Despliega un vector con cout */
std::ostream &operator<<( std::ostream &salida, const VecR2 &avec )
{
    /* Se decide el tipo de salida en funcion del valor del atributo
     * de clase Polar. */
    if( VecR2::Polar )
    {
        /* Se calcula el angulo polar del vector. La magnitud
         * se obtiene del metodo ya implementado */
        float ang = std::atan2( avec.Ycor , avec.Xcor );
        salida << "( " << avec.Magnitud() << " < " << ang << " )";
    }
    else
        salida << "( " << avec.Xcor << ", " << avec.Ycor << " )";
    
    return salida;
}

/* Esta funcion sobrecarga el operador* para permitir
 * la multiplicacion de un escalar por un vector
 * de la forma aesc*avec. Es importante hacer notar
 * que el orden de la multiplicacion NO ES CONMUTATIVO,
 * es decir, esta funcion no es llamada si el orden
 * escalar * vector es invertido. */
VecR2 operator*( const float &aesc, const VecR2 &avec )
{
    VecR2 tmp;
    tmp.Xcor = aesc*avec.Xcor;
    tmp.Ycor = aesc*avec.Ycor;

    return tmp;
}

//------------------------------------------------------------------------------------------------
//De Tarea, VecR3
//Iniciamos el vector en cartesianas
bool VecR3::esfericas = false;

//Constructor sin argumentos
VecR3::VecR3()
{
    Xcord = 0;
    Ycord = 0;
    Zcord = 0;
}

//Constructor con argumentos
VecR3::VecR3( float valor_x, float valor_y, float valor_z )
{
    Xcord = valor_x;
    Ycord = valor_y;
    Zcord = valor_z;
}

//Destructor
VecR3::~VecR3()
{}

//Metodo SET, Asignacion de cada coordenada x. y, z y xyz
void VecR3::Asignar_x( float valor_x )
{
    Xcord = valor_x;
}

void VecR3::Asignar_y( float valor_y )
{
    Ycord = valor_y;
}

void VecR3::Asignar_z( float valor_z )
{
    Zcord = valor_z;
}

void VecR3::Asignar_xyz( float valor_x, float valor_y, float valor_z )
{
    Xcord = valor_x;
    Ycord = valor_y;
    Zcord = valor_z;
}

//Metodo GET, Obtener coordenada para x, y, z
float VecR3::Obtener_x() const
{
    return Xcord;
}

float VecR3::Obtener_y() const
{
    return Ycord;
}

float VecR3::Obtener_z() const
{
    return Zcord;
}

/*Metodos para las operaciones aritmeticas*/
//Calculo de magnitud de un vector
float VecR3::Magnitud() const
{
    return std::sqrt( Xcord*Xcord + Ycord*Ycord + Zcord*Zcord );
}

//Suma entre vectores
VecR3 VecR3::operator+( const VecR3 &avec ) const
{
    VecR3 tmp;
    tmp.Xcord = this-> Xcord + avec.Xcord;
    tmp.Ycord = this-> Ycord + avec.Ycord;
    tmp.Zcord = this-> Zcord + avec.Zcord;
    return tmp;
}

//Resta entre vectores
VecR3 VecR3::operator-( const VecR3 &avec ) const
{
    VecR3 tmp;
    tmp.Xcord = this-> Xcord - avec.Xcord;
    tmp.Ycord = this-> Ycord - avec.Ycord;
    tmp.Zcord = this-> Zcord - avec.Zcord;
    return tmp;
}

//Negacion de un vector
VecR3 operator-( const VecR3 &avec )
{
    VecR3 tmp;
    tmp.Xcord = -1*avec.Xcord;
    tmp.Ycord = -1*avec.Ycord;
    tmp.Zcord = -1*avec.Zcord;
    return tmp;
}

//Producto punto entre vectores
float VecR3::operator*( const VecR3 &avec ) const
{
    float tmp;
    tmp = this->Xcord * avec.Xcord + this->Ycord * avec.Ycord + this->Zcord * avec.Zcord;
    return tmp;
}

//Producto cruz entre vectores
VecR3 VecR3::operator%( const VecR3 &avec ) const
{
    VecR3 tmp;
    tmp.Xcord = this->Ycord*avec.Zcord - Zcord*avec.Ycord;
    tmp.Ycord = this->Zcord*avec.Xcord - Xcord*avec.Zcord;
    tmp.Zcord = this->Xcord*avec.Ycord - Ycord*avec.Xcord;
    return tmp;
}

//Aginacion de un vector
VecR3 VecR3::operator=( const VecR3 &avec )
{
    this->Xcord = avec.Xcord;
    this->Ycord = avec.Ycord;
    this->Zcord = avec.Zcord;
    return (*this);
}

//Comparacion entre vectores
bool VecR3::operator==( const VecR3 &avec )
{
    if ( this->Xcord == avec.Xcord && this->Ycord == avec.Ycord && this->Zcord == avec.Zcord )
    {
        std::cout << "Los Vectores Son inguales \n ";
    }
    else
    {
        std::cout << "Los vectores No son iguales \n ";
    }
    return 0;
}

//Producto entre un vector y un escalar y viceversa
VecR3 operator*( const float &aesc, const VecR3 &avec )
{
    VecR3 tmp;
    tmp.Xcord = aesc*avec.Xcord;
    tmp.Ycord = aesc*avec.Ycord;
    tmp.Zcord = aesc*avec.Zcord;
    return tmp;
}

VecR3 operator*( const VecR3 &avec, const float &aesc )
{
    VecR3 tmp;
    tmp.Xcord = avec.Xcord * aesc;
    tmp.Ycord = avec.Ycord * aesc;
    tmp.Zcord = avec.Zcord * aesc;
    return tmp;
}

//Division entre un vector y un escalar
VecR3 operator/( const VecR3 &avec, const float &aesc )
{
    VecR3 tmp;
    tmp.Xcord = (avec.Xcord)/aesc;
    tmp.Ycord = (avec.Ycord)/aesc;
    tmp.Zcord = (avec.Zcord)/aesc;
    return tmp;
}

//Flag para cambiar entre cartesianas y esfericas
void VecR3::Mostrar_esfericas( bool valor )
{
    esfericas = valor;
}

//Calculo y despliege de coordenadas en esfericas o cartesianas
//Dependiente del valor de esfericas
std::ostream &operator<<( std::ostream &salida , const VecR3 &avec )
{
    if( VecR3::esfericas )
    {
        float theta = std::atan( avec.Ycord/avec.Xcord );
        float phi = std::acos( avec.Zcord/avec.Magnitud() );
        salida << "( " << avec.Magnitud() << " , " << theta << " , " << phi <<" )";
    }
    else
    {
        salida << "( " << avec.Xcord << ", " << avec.Ycord << ", " << avec.Zcord << " )";
    }
    return salida;
}