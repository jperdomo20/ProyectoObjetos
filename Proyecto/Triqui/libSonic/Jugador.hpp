/* 
 * File:   Jugador.hpp
 * Author: ma0
 *
 * Created on 10 de noviembre de 2013, 03:38 PM
 */

#ifndef JUGADOR_HPP
#define	JUGADOR_HPP
#include <iostream>
#include <string> 

using namespace std;
class Jugador {
public:
    Jugador();
    Jugador(const Jugador& orig);
    string getNombre();
    int getMaximoPuntaje();
    bool esSuTurno();
    int getPuntajeActual();
    void setNombre(string nombre);
    void setMaximoPuntaje(int puntaje);
    void setSuTurno(bool suTurno);
    void sumarPuntaje(int puntos);
    virtual ~Jugador();
private:
    string nombre;
    int maximoPuntaje;
    bool suTurno;
    int puntajeActual;
};

#endif	/* JUGADOR_HPP */

