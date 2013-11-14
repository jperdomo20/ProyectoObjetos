/* 
 * File:   Puntajes.hpp
 * Author: ma0
 *
 * Created on 10 de noviembre de 2013, 03:48 PM
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

