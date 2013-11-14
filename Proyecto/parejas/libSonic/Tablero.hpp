/* 
 * File:   Tablero.hpp
 * Author: ma0
 *
 * Created on 10 de noviembre de 2013, 01:01 PM
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

