
/* 
   Proyecto de Andres Felipe Muñoz, Jose Miguel Perdomo.
   Ayuda de Carlos Rocero

   Porcentaje de ayuda = 25%
   Ayudo en el rediseño del software, y en algunas falencias de la implementacion del software.

 */

// Especifica las funciones de la clase Archivos.
/*

	Esta clase se encarga de los archivos .txt,
	usados en otras clases como tablero o principalmente puntajes.



*/

#ifndef ARCHIVOS_HPP
#define	ARCHIVOS_HPP

#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Archivos {
public:
    Archivos();
    Archivos(const Archivos& orig);
    string LeerArchivo(string ruta);
    void EscribirArchivo(string ruta,string datos);
    void CrearArchivo(string ruta);
    void EliminarArchivo(string ruta);
    void AgregaraArchivo(string ruta,string datos);
    bool BuscarEnArchivo(string ruta, string datos);
    ~Archivos();
private:

};

#endif	/* ARCHIVOS_HPP */

