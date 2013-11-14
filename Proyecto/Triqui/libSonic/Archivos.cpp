/* 
 * File:   Archivos.cpp
 * Author: ma0
 * 
 * Created on 10 de noviembre de 2013, 12:58 PM
 */

#include "Archivos.hpp"

Archivos::Archivos() {
}

Archivos::Archivos(const Archivos& orig) {
}

Archivos::~Archivos() {
}

string Archivos::LeerArchivo(string ruta)
{
	ifstream archivo(ruta.c_str());
	if(archivo.good())
	{
		//archivo.open(ruta.c_str());
		string salida="";
		while(!archivo.eof())
		{
			string linea="";
			getline(archivo,linea);
			salida+=linea+"\n";
		}
		archivo.close();
		return salida;
	}
	else
	{
		cout<<"El archivo No Existe"<<endl;
		return "";
	}
}
void Archivos::EscribirArchivo(string ruta,string datos)
{
	ofstream out(ruta.c_str());
	if( !out )
	{
		cout << "Imposible abrir el archivo"  << endl;
		return ;
	}
	out << datos;
	cout<<"Datos Ingresados Correctamente"<<endl;
	out.close();
}

void Archivos::CrearArchivo(string ruta)
{
	EscribirArchivo(ruta,"");
}
void Archivos::EliminarArchivo(string ruta)
{
	if(remove(ruta.c_str())!=0)
		cout<< "Error deleting file \n";
	else
		cout<<"File successfully deleted\n";
}
void Archivos::AgregaraArchivo(string ruta,string datos)
{
	string archivosExistentes=LeerArchivo(ruta);
	datos=archivosExistentes+datos;
	EscribirArchivo(ruta,datos);
}
bool Archivos::BuscarEnArchivo(string ruta, string datos)
{
	string archivosExistentes=LeerArchivo(ruta);
	if(archivosExistentes.find(datos)!=string::npos)
		return true;
	else
			return false;
}

