/* 
 * File:   Jugador.cpp
 * Author: ma0
 * 
 * Created on 10 de noviembre de 2013, 03:38 PM
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

string Jugador::getNombre()
{
    return nombre;
}
int Jugador::getMaximoPuntaje()
{
    return maximoPuntaje;
}
bool Jugador::esSuTurno()
{
    return suTurno;
}
int Jugador::getPuntajeActual()
{
    return puntajeActual;
}
void Jugador::setNombre(string nombre)
{
    this->nombre=nombre;
}
void Jugador::setMaximoPuntaje(int puntaje)
{
    this->maximoPuntaje=puntaje;
}
void Jugador::setSuTurno(bool turno)
{
    this->suTurno=turno;
}
void Jugador::sumarPuntaje(int puntos)
{
    puntajeActual+=puntos;
}

