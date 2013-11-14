#include "tiempo.h"

Tiempo::Tiempo()
{

}


void Tiempo::inicializarReloj()
{
    ahora = time(&ahora);
}

int Tiempo::tiempoTotal()
{
    time_t now= time(&now);
    int seconds = difftime(now,ahora);
    return seconds;
}
