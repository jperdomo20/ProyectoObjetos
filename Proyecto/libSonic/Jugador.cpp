
/* 
   Proyecto de Andres Felipe Muñoz, Jose Miguel Perdomo.
   Ayuda de Carlos Rocero

   Porcentaje de ayuda = 25%
   Ayudo en el rediseño del software, y en algunas falencias de la implementacion del software.

 */

#include "Jugador.hpp"

Jugador::Jugador() {
    nombre="";
    maximoPuntaje=0;
    suTurno=false;
    puntajeActual=0;
}

Jugador::Jugador(const Jugador& orig) {
}

Jugador::~Jugador() {
}

string Jugador::getNombre()  // Retorna el nombre del jugador
{
    return nombre;
}
int Jugador::getMaximoPuntaje() // Retorna el puntaje maximo del jugador
{
    return maximoPuntaje;
}
bool Jugador::esSuTurno() // Retorna el turno del jugador
{
    return suTurno;
}
int Jugador::getPuntajeActual() //  Retorna el puntaje actual del jugador
{
    return puntajeActual;
}
void Jugador::setNombre(string nombre) // Asigna un nombre al jugador
{
    this->nombre=nombre;
}
void Jugador::setMaximoPuntaje(int puntaje) // Asigna un Maximo puntaje al jugador
{
    this->maximoPuntaje=puntaje;
}
void Jugador::setSuTurno(bool turno) // Asigna el turno al jugador
{
    this->suTurno=turno;
}
void Jugador::sumarPuntaje(int puntos) // Asigna el puntaje actual al jugador
{
    puntajeActual+=puntos;
}

