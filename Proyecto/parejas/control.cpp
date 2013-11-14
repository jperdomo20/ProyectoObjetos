#include "control.h"


control::control(int nu, Puntajes *p)
{

    tab = new Tablero();
    this->numParejas = nu;
    organizarPiezas();
    this->p = p;
}

void control::IniciarJuego(int jug)
{
    t = new Tiempo();
    t->inicializarReloj();
    posJugador=0;
    for(int i=0; i<jug; i++)
        jugadores.push_back(new Jugador);
}
// Rota los jugadores
void control::siguienteJugador()
{
    posJugador=(posJugador+1)%jugadores.size();
}
// Asigna el puntaje del ganador al jugador actual
void control::asignarPuntajeJugador(int punt)
{
    jugadores.at(posJugador)->sumarPuntaje(punt);

}
int control::tiempoTotal()
{
    return t->tiempoTotal();
}


// Lee la tabla de puntajes y la devuelve
string control::retomarPuntajesMaximos()
{
    string magia=" Nombre    |   Puntaje \n";
    string** mag = p->retornarPuntajes();
    int limite = p->tam;
    for(int i=0; i<limite; i++)
    {
        magia += (mag[i][0] + " -> " + mag[i][1])+ "\n";
    }
    return magia;
}
// Encargado de agregar la puntuación a la tabla de puntajes
void control::agregarPuntajesMaximo(string n, int pu)
{

    p->ingresarNuevoPuntaje(n,pu);
}
// Asigna el nombre del ganador al jugador actual
void control::asignarNombreJugador(string no)
{
    jugadores.at(posJugador)->setNombre(no);
    agregarPuntajesMaximo(no,jugadores.at(posJugador)->getPuntajeActual() );
}

/*----------------------------------------*/
int control::randInt(int low, int high)
{
return rand() % ((high + 1) - low) + low;
}

/*----------------------------------------*/

void control::organizarPiezas(){

    parejas=new int[numParejas];
    for(int i=0; i<numParejas; i++)
    {
        parejas[i]=i+1;
    }
    barajarParejas(parejas,numParejas);

    tab->imprimirTablero();
}

/*----------------------------------------*/
int* control::establecerArregloFinal(int arreglo[], int longitud){
        int longitudPila = longitud*2;
        int *pila= new int[longitudPila];

        int cont=0;
        for(int u=0;u<longitudPila;u++){
            pila[u]=arreglo[cont];
            if((cont+1)!=longitud){
                cont=cont+1;
            }
            else{
                cont=0;
            }
        }

        return pila;
}

    void control::barajarParejas(int arreglo[], int l){

     int *pila,alea,temp;

     pila=establecerArregloFinal(arreglo, l);

     int longitud = l*2;



     for(int i=0;i<longitud;i++){
       int valorRandom = randInt(0,longitud-1);
       alea=(valorRandom);
       temp=pila[i];
       pila[i]=pila[alea];
       pila[alea]=temp;
     }

     agregarParejaMatriz(pila,longitud);

    }

    void control::agregarParejaMatriz(int parejas[], int elementos){
        largo = 4;
        ancho = 4;
        if(elementos==12){//6 parejas
           largo = 3;
           ancho = 4;
        }
        else if(elementos == 24){ // 12 parejas
            largo = 6;
            ancho = 4;
        }
        tab->crearTablero(largo, ancho);
        int contador=0;
        ostringstream ss;
        for(int i=0;i<largo;i++){
            for(int e=0;e<ancho;e++){
                ss << parejas[contador];
                tab->agregarElemento(ss.str(), i, e);
                ss.str("");
                contador=contador+1;
            }
        }
    }
//--------------------------------------------------------------
