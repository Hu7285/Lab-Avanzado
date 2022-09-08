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

//---------------------------------------------------------------------------------------
//De tarea, Para vector en R3
class VecR3
{
    private:
        //Coordenadas x,y,z
        float Xcord;
        float Ycord;
        float Zcord;

        //Flag si sera esfericas o cartesianas
        static bool esfericas;

    public:
        //Constructor sin argumentos
        VecR3();
        //Constructor con argumentos
        VecR3( float valor_x, float valor_y, float valor_z );
        //Destructor 
        ~VecR3();

        //Flag para cambiar entre esfericas y cartesianas
        static void Mostrar_esfericas( bool valor );
    
        //Metodo SET, Asignacion de cada coordenada x. y, z y xyz
        void Asignar_x( float valor_x );
        void Asignar_y( float valor_y );
        void Asignar_z( float valor_z );
        void Asignar_xyz( float valor_x, float valor_y, float valor_z );

        //Metodo GET, Obtener coordenada para x, y, z
        float Obtener_x() const;
        float Obtener_y() const;
        float Obtener_z() const;

        /*Metodos para las operaciones aritmeticas*/
        //Magnitud de vector
        float Magnitud() const;
        //Suma entre vectores
        VecR3 operator+( const VecR3 & ) const;
        //Resta entre vectores
        VecR3 operator-( const VecR3 & ) const;
        //Producto punto entre vectores
        float operator*( const VecR3 & ) const;
        //Producto cruz entre vectores
        VecR3 operator%( const VecR3 & ) const;
        //Asignacion de vector
        VecR3 operator=( const VecR3 & );
        //Comparacion entre vectores
        bool operator==( const VecR3 & );

        /*Funciones amigas para mas operaciones*/
        //Negacion de un vector
        friend VecR3 operator-( const VecR3 & );
        //Multiplicacion vector con escalar
        friend VecR3 operator*( const float &, const VecR3 & );
        friend VecR3 operator*( const VecR3 &, const float & );
        //Division de vector con escalar
        friend VecR3 operator/( const VecR3 &, const float & );
        //Mostrar los vectores
        friend std::ostream &operator << ( std::ostream &, const VecR3 & );
};


#endif /* __VECR2_HPP__ */