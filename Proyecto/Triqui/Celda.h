#ifndef CELDA_H
#define CELDA_H

#include <QLabel>

class Celda : public QLabel
{
    Q_OBJECT
public:

    int i;
    int j;

    explicit Celda( const QString& text ="", QWidget * parent = 0 );
       ~Celda();
       void establecerCoordenadas(int x,int y);
       bool hasidoClickeada;
   signals:
       void clicked();

   protected:
       void mousePressEvent ( QMouseEvent * event ) ;

};

#endif // CELDA_H
