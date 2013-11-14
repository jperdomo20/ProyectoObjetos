
/* 
   Proyecto de Andres Felipe Muñoz, Jose Miguel Perdomo.
   Ayuda de Carlos Rocero

   Porcentaje de ayuda = 25%
   Ayudo en el rediseño del software, y en algunas falencias de la implementacion del software.

 */

#include "Archivos.hpp"

Archivos::Archivos() {
}

Archivos::Archivos(const Archivos& orig) {
}

Archivos::~Archivos() {
}

string Archivos::LeerArchivo(string ruta) // Lee el archivo segun la ruta asignada, de lo contrario imprime un mensjae de error
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
void Archivos::EscribirArchivo(string ruta,string datos) // Escribe sobre el archivo de la ruta asignada, de lo contrario imprime un mensjae de error
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

void Archivos::CrearArchivo(string ruta)  // Crea un archivo en la ruta asignada
{
	EscribirArchivo(ruta,"");
}
void Archivos::EliminarArchivo(string ruta) // Elimina el archivo de la ruta asignada, de lo contrario imprime un mensjae de error
{
	if(remove(ruta.c_str())!=0)
		cout<< "Error deleting file \n";
	else
		cout<<"File successfully deleted\n";
}
void Archivos::AgregaraArchivo(string ruta,string datos)  // Agrega el archivo en la ruta asignada.
{
	string archivosExistentes=LeerArchivo(ruta);
	datos=archivosExistentes+datos;
	EscribirArchivo(ruta,datos);
}
bool Archivos::BuscarEnArchivo(string ruta, string datos) // Busca  un archivo segun la ruta y los datos dados.
{
	string archivosExistentes=LeerArchivo(ruta);
	if(archivosExistentes.find(datos)!=string::npos)
		return true;
	else
			return false;
}

