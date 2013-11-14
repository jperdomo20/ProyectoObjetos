#include "Celda.h"


Celda::Celda( const QString& text, QWidget * parent) :QLabel(parent)
  {

      this->setText(text);
      hasidoClickeada = false;
  }

void Celda::establecerCoordenadas(int x, int y ){
    i=x;
    j=y;
}

  Celda::~Celda()
  {
  }


  void Celda::mousePressEvent ( QMouseEvent * event )
  {

      emit clicked();
  }
