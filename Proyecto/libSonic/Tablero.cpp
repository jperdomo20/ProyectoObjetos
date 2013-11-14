
/* 
   Proyecto de Andres Felipe Munñoz, Jose Miguel Perdomo.
   Ayuda de Carlos Rocero

   Porcentaje de ayuda = 25%
   Ayudo en el rediseño del software, y en algunas falencias de la implementacion del software.

 */

#include "Tablero.hpp"

Tablero::Tablero() {
}

Tablero::Tablero(const Tablero& orig) {
}

Tablero::Tablero(int i, int j)
{
	crearTablero( i,  j);
}
void Tablero::crearTablero(int i, int j) // Crea un tablero segun las dimensiones dadas
{
	tami=i;
	tamj=j;
	if(i>0&&j>0)
	{
		tablero= new string*[i];
		for(int i1=0;i1<i;i1++)
			tablero[i1]=new string[j];
		for (int i1=0;i1<tami;i1++)
		{
			for (int j1=0;j1<tamj;j1++)
			{
					tablero[i1][j1]="";
			}
		}
		cout<<"Tablero Creado ["<<tami<<"]["<<tamj<<"]\n";
	}
	
}
void Tablero::agregarElemento(string elemento, int i, int j) //  Agrega un elemento al tablero segun la posicion dada
{
	if(enRango(i,j))
		tablero[i][j]=elemento;
}
void Tablero::moverElemento(int iInicio, int jInicio,int iFinal, int jFinal ) // Mueve un elemento segun su posicion incial y dado la final
{
	if(enRango(iInicio,jInicio)&&enRango(iFinal,jFinal))
	{
		tablero[iFinal][jFinal]=tablero[iInicio][jInicio];
		tablero[iInicio][jInicio]="";
	}
}
string Tablero::obtenerElemento(int i, int j) // Retorna el elemento de la posicion dada
{
	if(enRango(i,j))
		return tablero[i][j];
	else
		return "";
}
bool Tablero::estaVacia(int i,int j ) // Retorna si tal posicion contiene un elemento o esta vacia.
{
	if(enRango(i,j))
	{
		if(tablero[i][j].compare("")==0)
			return true;
		else
			return false;
	}
	return false;
	
}
void Tablero::guardarTablero() // Guarda el tablero en un archivo txt
{
	string guardar="";
	stringstream ss,ss1;
	ss << tami;
	string str = ss.str();
	guardar+=str+"\n";
	ss1 << tamj;
	str = ss1.str();
	guardar+=str+"\n";
	for (int i=0;i<tami;i++)
	{
		for (int j=0;j<tamj;j++)
		{
			guardar+=tablero[i][j]+"#";
		}
		guardar+="\n";
	}
	Archivos archivo;
	archivo.EscribirArchivo("tablero.txt",guardar);
}
void Tablero::cargarTablero() // CArga el tablero del archivo txt
{
	Archivos archivo;
	string texto=archivo.LeerArchivo("tablero.txt");
        string bufferi="",bufferj="";
        int k=0;
        bufferi=texto.substr(k,texto.find("\n")-k);
        texto=texto.substr(texto.find("\n")+1);
        bufferj=texto.substr(k,texto.find("\n")-k);
        texto=texto.substr(texto.find("\n")+1);
        stringstream ss(bufferi);
        ss>>tami;
        stringstream ss1(bufferj);
        ss1>>tamj;
        
        crearTablero(tami,tamj);
        
	for(int i=0;i<tami;i++)
        {
            string linea=texto.substr(0,texto.find("\n")+1);
            cout<<"En Linea "<<i<<" "<<linea<<endl;
            for(int j=0;j<tamj;j++)
            {
                agregarElemento(linea.substr(0,linea.find("#")),i,j);
                linea=linea.substr(linea.find("#")+1);
            }
            
            texto=texto.substr(texto.find("\n")+1);
        }
}
bool Tablero::enRango(int i, int j) //Verifica si tal posicion esta en el rango del tablero
{
	if(i>=0&&i<tami&&j>=0&&j<tamj)
		return true;
	else
		{
		cout<<"Fuera de Los indices"<<endl;
		return false;
	}
}


void Tablero::imprimirTablero() // Imprime el tablero
{
    for(int i=0;i<tami;i++)
        {
            for(int j=0;j<tamj;j++)
            {
                if(estaVacia(i,j))
                    cout<<" |";
                else
                        cout<<tablero[i][j]<<"|";
            }
            cout<<endl;
        }
    
}

Tablero::~Tablero() {
}

