#ifndef TIEMPO_H
#define TIEMPO_H

#include <time.h>
class Tiempo
{
public:
    time_t ahora;
    double seconds;
    Tiempo();
    void inicializarReloj();
    int tiempoTotal();

};

#endif // TIEMPO_H
