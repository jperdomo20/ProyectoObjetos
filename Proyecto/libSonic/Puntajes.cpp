/* 
 * File:   Puntajes.cpp
 * Author: ma0
 * 
 * Created on 10 de noviembre de 2013, 03:48 PM
 */

#include "Puntajes.hpp"

Puntajes::Puntajes() {
    tam=0;
    cargarPuntajes();
    cout<<"Se Contruye\n";
}

Puntajes::Puntajes(const Puntajes& orig) {
}

Puntajes::~Puntajes() {
}

void Puntajes::ingresarNuevoPuntaje(string nombre, int puntaje)
{
    cout<<"Ingresando: "<<nombre<<endl;
    int * nuevosPuntajes=new int[tam+1];
    string ** nuevamatriz=new string*[tam+1];
    for(int i=0;i<tam+1;i++)
        nuevamatriz[i]=new string[2];
    bool agregado=false;
    tam=tam+1;
    for(int i=0;i<tam-1;i++)
    {
        if(!agregado)
        {
            if(puntajesOrdenados[i]>puntaje)
            {
                nuevosPuntajes[i]=puntajesOrdenados[i];
                nuevamatriz[i][0]=puntajes[i][0];
                nuevamatriz[i][1]=puntajes[i][1];
            }else
            {
                cout<<"Se Agrega un Puintaje Mayor\n";
                nuevosPuntajes[i]=puntaje;
                nuevamatriz[i][0]=nombre;
                stringstream ss;
                ss<<puntaje;
                nuevamatriz[i][1]=ss.str();
                agregado=true;
                nuevosPuntajes[i+1]=puntajesOrdenados[i];
                nuevamatriz[i+1][0]=puntajes[i][0];
                nuevamatriz[i+1][1]=puntajes[i][1];
            }
        }else
        {
            nuevosPuntajes[i+1]=puntajesOrdenados[i];
            nuevamatriz[i+1][0]=puntajes[i][0];
            nuevamatriz[i+1][1]=puntajes[i][1];
        }
    }
    if(!agregado)
    {
        nuevosPuntajes[tam-1]=puntaje;
        nuevamatriz[tam-1][0]=nombre;
        stringstream ss;
        ss<<puntaje;
        nuevamatriz[tam-1][1]=ss.str();
    }
    puntajes=nuevamatriz;
    puntajesOrdenados=nuevosPuntajes;
    imprimirPuntajes();
    guardarPuntajes();
}
string** Puntajes::retornarPuntajes()
{
    return puntajes;
}

void Puntajes::cargarPuntajes()
{
    Archivos archivo;
    string texto=archivo.LeerArchivo("puntajes.txt");
    if(texto.compare("")!=0)
    {

        stringstream ss(texto.substr(0,texto.find("\n")));
        ss>>tam;
        cout<<tam<<endl;
        puntajes= new string*[tam];
        for(int i1=0;i1<tam;i1++)
                puntajes[i1]=new string[2];
        puntajesOrdenados=new int[tam];
        texto=texto.substr(texto.find("\n")+1);
        for(int i=0;i<tam;i++)
        {
            string linea=texto.substr(0,texto.find("\n")+1);
            cout<<"En Linea "<<i<<" "<<linea<<endl;
            puntajes[i][0]=linea.substr(0,linea.find("#"));
            linea=linea.substr(linea.find("#")+1);
            puntajes[i][1]=linea.substr(0,linea.find("\n"));
            stringstream ss(puntajes[i][1]);
            ss>>puntajesOrdenados[i];
            texto=texto.substr(texto.find("\n")+1);
        }
        cout<<"Archivos que se cargan del archivo txt\n";
        imprimirPuntajes();
    }
}

void Puntajes::guardarPuntajes()
{
    string texto="";
    stringstream ss;
    ss<<tam;
    texto+=ss.str()+"\n";
    for(int i=0;i<tam;i++)
    {
        texto+=puntajes[i][0]+"#"+ puntajes[i][1]+"\n";
    }
    cout<<texto<<endl;
    Archivos archivo;
    archivo.EscribirArchivo("puntajes.txt",texto);
    
}

void Puntajes::imprimirPuntajes()
{
    cout<<"Imprimiendo Puntajes\n";
    for(int i=0;i<tam;i++)
    {
            cout<< puntajes[i][0]+"#"+ puntajes[i][1]<<endl;
    }
    cout<<endl;
}
