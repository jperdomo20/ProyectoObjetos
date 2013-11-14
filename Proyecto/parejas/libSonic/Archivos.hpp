/* 
 * File:   Archivos.hpp
 * Author: ma0
 *
 * Created on 10 de noviembre de 2013, 12:58 PM
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

