#ifndef CELDA_H
#define CELDA_H

#include <QLabel>
#include <QString>

class Celda : public QLabel
{

Q_OBJECT

public:
    explicit Celda( const QString& text ="", QWidget * parent = 0 );
    ~Celda();
    QString nombreCelda();
    QString nomb;
    int id;
    bool hasidoClickeada, nula;
    int i, j;
    void construirCelda(QString nombre, int id, int i, int j);
signals:
    void clicked();

protected:
    void mousePressEvent ( QMouseEvent * event ) ;
};

#endif // CELDA_H
