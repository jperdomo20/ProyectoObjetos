#include "celda.h"


Celda::Celda( const QString& text, QWidget * parent ) :
    QLabel(parent)

  {
      this->setText(text);
      this->hasidoClickeada=false;
      nula = true;
  }

  Celda::~Celda()
  {
  }

  void Celda::construirCelda(QString nombre, int id, int i, int j)
  {
      this->nomb=nombre;
      this->id=id;
      this->i=i;this->j=j;
  }

  void Celda::mousePressEvent ( QMouseEvent * event )

  {
      emit clicked();
  }

  QString Celda::nombreCelda()
  {
      return this->text();
  }
