
/* 
   Proyecto de Andres Felipe Muñoz, Jose Miguel Perdomo.
   Ayuda de Carlos Rocero

   Porcentaje de ayuda = 25%
   Ayudo en el rediseño del software, y en algunas falencias de la implementacion del software.

 */


// Especifica las funciones de la clase puntajes

/*

Esta clase se encarga de todos los puntajes y 
posiciones de los jugadores


*/


#ifndef PUNTAJES_HPP
#define	PUNTAJES_HPP

#include "Archivos.hpp"
#include <iostream>
#include <string> 
#include <sstream>

using namespace std;
class Puntajes {
public:
    Puntajes();
    Puntajes(const Puntajes& orig);
    virtual ~Puntajes();
    void ingresarNuevoPuntaje(string nombre, int puntaje);
    string** retornarPuntajes();
    void cargarPuntajes();
    void guardarPuntajes();
    void imprimirPuntajes();
    int tam;
private:
    string** puntajes;
    int * puntajesOrdenados;
    //int tam;
};

#endif	/* PUNTAJES_HPP */

