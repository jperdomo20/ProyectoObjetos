
/* 
   Proyecto de Andres Felipe Munñoz, Jose Miguel Perdomo.
   Ayuda de Carlos Rocero

   Porcentaje de ayuda = 25%
   Ayudo en el rediseño del software, y en algunas falencias de la implementacion del software.

 */


// Especifica las funciones de la clase Tablero

/*

Esta clase se encarga del espacio de funcionamiento donde se van a relacionar 
los jugadores y juegos que se implementen


*/



#ifndef TABLERO_HPP
#define	TABLERO_HPP
#include "Archivos.hpp"
#include <iostream>
#include <string> 
#include <sstream>
using namespace std;


class Tablero {
public:
    Tablero();
    Tablero(const Tablero& orig);
    Tablero(int i, int j);
    void crearTablero(int i, int j);
    void agregarElemento(string elemento, int i, int j);
    void moverElemento(int iInicio, int jInicio,int iFinal, int jFinal );
    string obtenerElemento(int i, int j);
    bool estaVacia(int i,int j );
    void guardarTablero();
    void cargarTablero();
    void imprimirTablero();
    virtual ~Tablero();
private:
    string ** tablero;
    bool enRango(int i, int j);
    int tami;
    int tamj;
};

#endif	/* TABLERO_HPP */

