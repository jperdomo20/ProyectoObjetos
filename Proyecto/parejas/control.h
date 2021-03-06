#ifndef CONTROL_H
#define CONTROL_H
#include <ctime>
#include <stdlib.h>
#include <vector>
#include "libSonic/tiempo.h"
#include "libSonic/Tablero.hpp"
#include "libSonic/Jugador.hpp"
#include "libSonic/Puntajes.hpp"
#include "libSonic/Archivos.hpp"

class control
{
public:
    vector<Jugador*> jugadores;
    int ancho, largo, numParejas;
    int *parejas,posJugador;
    Tablero *tab;
    control(int nu, Puntajes *);
    void organizarPiezas();
    void IniciarJuego(int jug);
    void agregarParejaMatriz(int parejas[], int elementos);
    void barajarParejas(int arreglo[], int l);
    int* establecerArregloFinal(int arreglo[], int longitud);
    int randInt(int low, int high);
    void siguienteJugador();
    void asignarPuntajeJugador(int punt);
    string retomarPuntajesMaximos();
    void agregarPuntajesMaximo(string n, int p);
    void asignarNombreJugador(string no);
    int tiempoTotal();
    Puntajes *p;
    Tiempo *t;
};

#endif // CONTROL_H
