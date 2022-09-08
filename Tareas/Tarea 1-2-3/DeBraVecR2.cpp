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

#include "DeBraVecR2.hpp"

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

//************************************IMPLEMENTACION VecR3**************************************************
//Inicializando los valores del vector en sus parametros estandar
//Por defecto se utilizan cartesianas
bool VecR3:: esferico = false;
//Constructor sin argumentos
VecR3::VecR3()
{
    Xcor = 0;
    Ycor = 0;
    Zcor = 0;
}
//Constructor con argumentos
VecR3::VecR3(float valx, float valy, float valz)
{
    Xcor = valx;
    Ycor = valy;
    Zcor = valz;
}
//Destructor
VecR3::~VecR3()
{}
//Metodo de clase para mostrar en esferico
void VecR3::Mostar_esferico( bool valor )
{
    esferico = valor;
}
//***************************************METODOS SET(IMPLEMENTACION)***************************************
//Metodo para asignar coordenada x al vector
void VecR3::asignar_x(float valx)
{
    Xcor = valx;
}
//Metodo para asignar coordenada y al vector
void VecR3::asignar_y(float valy)
{
    Ycor = valy;
}
//Metodo para asignar coordenada z al vector
void VecR3::asignar_z(float valz)
{
    Ycor = valz;
}
//Metodo para asignar coordenadas x,y,z al vector
void VecR3::asignar_xyz(float valx, float valy, float valz)
{
    Xcor = valx;
    Ycor = valy;
    Ycor = valz;
}
//************************************METODOS GET(IMPLEMENTACIO)****************************************
//Metodo para obtener la coordenada en x del vector
float VecR3::obtener_x() const
{
    return Xcor;
}
//Metodo para obtener la coordenada en y del vector
float VecR3::obtener_y() const
{
    return Ycor;
}
//Metodo para obtener la coordenada en z del vector
float VecR3::obtener_z() const
{
    return Zcor;
}
//**********************************METODOS OPERACIONES(Implememtacion)*************************************************
//Magnitud de un vector
float VecR3::magnitud() const
{
    return std::sqrt(Xcor*Xcor + Ycor*Ycor + Zcor*Zcor );
}
//Suma de vectores
VecR3 VecR3::operator+(const VecR3 &avec) const
{
    VecR3 tmp;
    tmp.Xcor = this->Xcor + avec.Xcor;
    tmp.Ycor = this->Ycor + avec.Ycor;
    tmp.Zcor = this->Zcor + avec.Zcor;
    return tmp;
}
//Resta de vectores
VecR3 VecR3::operator-(const VecR3 & avec)const
{
    VecR3 tmp;
    tmp.Xcor = this->Xcor - avec.Xcor;
    tmp.Ycor = this->Ycor - avec.Ycor;
    tmp.Zcor = this->Zcor - avec.Zcor;
    return tmp;
}
//Producto punto de vectores
float VecR3::operator*( const VecR3 &avec ) const
{
    float tmp;
    tmp = this->Xcor * avec.Xcor + this->Ycor * avec.Ycor + this->Zcor * avec.Zcor;
    return tmp;
}
//Producto cruz de vectores
VecR3  VecR3::operator%( const VecR3 &avec ) const
{
    /* Ver los comentarios de operator+ */
    VecR3 tmp;

    tmp.Xcor = this->Ycor*avec.Zcor - Zcor*avec.Ycor;
    tmp.Ycor = this->Zcor*avec.Xcor - Xcor*avec.Zcor;
    tmp.Zcor = this->Xcor*avec.Ycor - Ycor*avec.Xcor;

    return tmp;
}

//Asignacion de un vector
VecR3 VecR3::operator=( const VecR3 &avec)
{
    this->Xcor = avec.Xcor;
    this->Ycor = avec.Ycor;
    this->Zcor = avec.Zcor;
    return (*this);
}
//Comparacion de vectores
bool VecR3::operator==(const VecR3 &avec)
{
    if (this->Xcor == avec.Xcor && this->Ycor == avec.Ycor && this->Zcor == avec.Zcor)
    {
        std::cout<< "Verdadero \n ";
        
    }
        else{
            std::cout<< "Falso \n ";
            
        }
        return 0;
    }
//Negacion de vectores
 VecR3 operator-(const VecR3 &avec) 
{
    VecR3 tmp;
    tmp.Xcor = -1*avec.Xcor;
    tmp.Ycor = -1*avec.Ycor;
    tmp.Zcor = -1*avec.Zcor;

    return tmp;
}
    

//***********************************FUNCIONES AMIGAS(Implememtacion)**************************************
//Producto de escalar por un vector
VecR3 operator*( const float &aesc, const VecR3 &avec )
{
    VecR3 tmp;
    tmp.Xcor = aesc*avec.Xcor;
    tmp.Ycor = aesc*avec.Ycor;
    tmp.Zcor = aesc*avec.Zcor;
    return tmp;
}
//Division de vector por escalar
VecR3 operator/( const VecR3 &avec,const float &aesc  )
{
    VecR3 tmp;
    tmp.Xcor = (avec.Xcor)/aesc;
    tmp.Ycor = (avec.Ycor)/aesc;
    tmp.Zcor = (avec.Zcor)/aesc;

    return tmp;
}

//Despliegue de vectores en pantalla(esferico o cartesiano)
std::ostream &operator<<( std::ostream &salida, const VecR3 &avec )
{
    if( VecR3::esferico )
    {
        float theta = std::acos( avec.Zcor/avec.magnitud());
        float phi = std::asin(avec.Ycor/avec.Xcor);
        salida << "( " << avec.magnitud() << " < " << theta << phi <<  " )";
    }
    else
        salida << "( " << avec.Xcor << ", " << avec.Ycor << ", " << avec.Zcor << " )";
    
    return salida;
}

//Producto de vector por constante
//Producto de escalar por un vector
VecR3 operator*( const VecR3 &avec, const float &aesc )
{
    VecR3 tmp;
    tmp.Xcor = avec.Xcor*aesc;
    tmp.Ycor = avec.Ycor*aesc;
    tmp.Zcor = avec.Zcor*aesc;

    return tmp;
}

