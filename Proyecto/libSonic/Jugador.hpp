
/* 
   Proyecto de Andres Felipe Muñoz, Jose Miguel Perdomo.
   Ayuda de Carlos Rocero

   Porcentaje de ayuda = 25%
   Ayudo en el rediseño del software, y en algunas falencias de la implementacion del software.

 */


// Especifica las funciones de la clase jugador

/*

Esta clase se encarga de todos los atributos y 
caracteristicas de los jugadores


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

