/* 
 * VecR2.hpp: Definicion de la clase VecR2
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

#ifndef __VECR2_HPP__
#define __VECR2_HPP__

#include <iostream>
#include <string>

/* Clase VecR2: Vectores en R2. Internamente
 * se representa en forma cartesiana. */ 
class VecR2
{
private:
    /* Coordenada x */
    float Xcor;
    /* Coordenada x */
    float Ycor;

    /* Atributo de clase: Indica si el despliege del
     * vector seran en coordenas polares. */
    static bool Polar;

public:

    /* Constructor sin argumentos */
    VecR2();
    /* Constructor con argumentos */
    VecR2( float valor_x, float valor_y );
    /* Destructor */
    ~VecR2();

    /* Metodos de asignacion (set methods) */

    /* Asigna la coordenada x */
    void Asignar_x( float valor_x );
    /* Asigna la coordenada y */
    void Asignar_y( float valor_y );
    /* Asigna las coordenadas x, y */
    void Asignar_xy( float valor_x, float valor_y );

    /* Metodos de obtencion (get methods)
     * El calificador const al final del prototipo
     * indica que estos metodos no van a alterar
     * los valores de la instancia que los llama. */

    /* Obtener la coordenada x */
    float Obtener_x( ) const;
    /* Obtener la coordenada y */
    float Obtener_y( ) const;

    /* Otros metodos */
    
    /* Devuelve la magnitud del vector */
    float Magnitud() const;

    /* Sobrecarga de operadores
     * El calificador const en el argumento impide 
     * que el argumento del operador pueda ser modificado
     * dentro del metodo. */

    /* Calcula la suma de dos vectores */
    VecR2 operator+( const VecR2 & ) const;
    /* Calcula el producto punto de dos vectores */
    float operator*( const VecR2 & ) const;
    /* Operador de asignacion */
    VecR2 operator=( const VecR2 & );
    
    /* Metodo de clase: Fija el valor del flag para que
     * el despliege del vector sea en polar (true) o
     * cartesiano (false) */
    static void Mostar_Polar( bool valor );

    /* Funciones amigas */

    /* Despliega un vector con cout */
    friend std::ostream &operator<<( std::ostream &, const VecR2 & );
    /* Multiplica un flotante por un vector */
    friend VecR2 operator*( const float &, const VecR2 & );

};

//Clase VecR3
class VecR3
{
private:
    float Xcor;
    float Ycor;
    float Zcor;

    static bool esferico;

public:
    //Constructor sin argumentos
    VecR3();
    //Constructor con argumentos
    VecR3(float valx, float valy, float valz);
    //Destructor
    ~VecR3();
    //Metodo de clase (fijo)
    static void Mostar_esferico( bool valor );

    //*******************************************METODOS SET*************************************************
    //Asignar coordenada en x
    void asignar_x(float valx);
    //Asignar coordenada en y
    void asignar_y(float valy);
    //Asignar coordenada en z
    void asignar_z(float valz);
    //Asignar coordenadas x, y, z
    void asignar_xyz(float valx, float valy, float valz);

    //*******************************************METODOS GET*************************************************
    //Obtener coordenada en x
    float obtener_x() const;
    //Obtener coordenada en y
    float obtener_y() const;
    //Obtener coordenada en z
    float obtener_z() const;

    //**********************************METODOS DE OPERACIONES (SOBRECARGA)*****************************************
    //Estos metodos serán uttilizados para operar los vectores
    //Magnitud de un vector
    float magnitud() const;
    //Suma de vectores (operador sobrecargado)
    VecR3 operator+(const VecR3 &) const;
    //Resta de vectores (operador sobrecargado)
    VecR3 operator-(const VecR3 &) const;
    //Producto de vectores (operador sobrecargado)
    float operator*(const VecR3 &) const;
    //Producto cruz de vectores (operador sobrecargado)
    VecR3 operator%(const VecR3 &) const;
    //Asigancion de vector (operador sobrecargado)
    VecR3 operator=(const VecR3 &);
    //Comparacion de vectores (operador sobrecargado)
    bool operator==(const VecR3 &);
    //Negacion de vectores
    friend VecR3 operator-(const VecR3 &);
    

    //**************************************FUNCIONES AMIGAS (SOBRECARGA)**************************************************
    //Producto de constante con vector (sobrecarga)
    friend VecR3 operator*(const float &, const VecR3 &);
     //Division de vectores con constante (operador sobrecargado)
    friend VecR3 operator/(const VecR3 &, const float &);
    //Despliegue de vectores (operador sobrecargado)
    friend std::ostream &operator<<( std::ostream &, const VecR3 & );
    //Producto de vector por constante (sobrecarga)
    friend VecR3 operator*(const VecR3 &, const float &);
    
    


    

};

#endif /* __VECR2_HPP__ */