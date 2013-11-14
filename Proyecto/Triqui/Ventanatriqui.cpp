
#include <QtGui>

#include "Ventanatriqui.h"


Ventanatriqui::Ventanatriqui()
{
    this->setGeometry(400,250,200,200);
    setStyleSheet("background-color:black;");
    turno = 0;
    iniciar=false;

    tableroJuego=new Tablero(numeroDeCeldas,numeroDeCeldas);

    jugadorUno=new Jugador();
    jugadorDos=new Jugador();
    jugadorUno->setSuTurno(true);//jugador uno comienza


    crearMenu();
    crearTablero();
    crearSubPanelJugadores();



    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(gbJugadores);
    mainLayout->addWidget(gridGroupBox);
    setLayout(mainLayout);
    setWindowTitle(tr("Basic Layouts"));

}

void Ventanatriqui::crearMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&Archivo"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    scoreAction = fileMenu->addAction(tr("&Ver"));

    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
    connect(scoreAction, SIGNAL(triggered()), this, SLOT(verPuntajes()));
}

void Ventanatriqui::verPuntajes()
{

}

void Ventanatriqui::crearPanelTitulo()
{
    horizontalGroupBox = new QGroupBox(tr("Horizontal layout"));
    QHBoxLayout *layout = new QHBoxLayout;

    for (int i = 0; i < NumButtons; ++i) {
        buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
	layout->addWidget(buttons[i]);
    }
    horizontalGroupBox->setLayout(layout);
}

void Ventanatriqui::crearTablero()
{

    gridGroupBox = new QGroupBox("Tablero");
    gridGroupBox->setStyleSheet("QGroupBox { background-color : black; color : white;}");

    QGridLayout *layout = new QGridLayout;
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);


    for (int i = 0; i < numeroDeCeldas; ++i) {
        for (int j=0; j < numeroDeCeldas; ++j)
        {

            Celda *boton = new Celda();
            boton->establecerCoordenadas(i,j);
            QPixmap *pixMaps = new QPixmap(tr("imagenes/casillaVacia.png"));
            //boton->setStyleSheet("QLabel{ background-color :black;color:blue;font-size: 40px; border :0.5px solid  #ffffff }");
            boton->setPixmap(*pixMaps);
            botones[i][j] = boton;

            connect(boton, SIGNAL(clicked()), this, SLOT(manejadorBoton()));
            layout->addWidget(botones[i][j], i + 1, j+1,Qt::AlignBottom);
        }
    }


    layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);
    gridGroupBox->setLayout(layout);

}

void Ventanatriqui::crearSubPanelJugadores(){
      gbJugadores= new QGroupBox("Jugadores");
      gbJugadores->setAlignment(2);
      gbJugadores->setStyleSheet("QGroupBox { background-color : black; color : white;}");
      layoutF=new QFormLayout(this);
      qlJugadorUno=new QLabel("Jugador 1: ");
      qlJugadorDos=new QLabel("Jugador 2: ");
      qlJugadorUno->setStyleSheet("QLabel { background-color : black; color : white;}");
      qlJugadorDos->setStyleSheet("QLabel { background-color : black; color : white;}");

      qteJugadorUno=new QTextEdit();
      qteJugadorUno->setStyleSheet("QTextEdit { background-color : black; color : white;font-size: 20px;}");
      qteJugadorDos=new QTextEdit();
      qteJugadorDos->setStyleSheet("QTextEdit { background-color : black; color : white;font-size: 20px;}");

      layoutF->addRow(qlJugadorUno,qteJugadorUno);
      layoutF->addRow(qlJugadorDos,qteJugadorDos);
      gbJugadores->setLayout(layoutF);

      connect(qteJugadorUno,SIGNAL(textChanged()),this,SLOT (manejarSesionJUno()));
      connect(qteJugadorDos,SIGNAL(textChanged()),this,SLOT (manejarSesionJDos()));

}

void Ventanatriqui::manejadorBoton()
{
    if(iniciar){

        Celda *clickedButton = qobject_cast<Celda *>(sender());
        QString str("");
        if(!clickedButton->hasidoClickeada){

            if(jugadorUno->esSuTurno()){
                str = tr("X");
                // Pinta el recuadro del jugador acutal
                qteJugadorDos->setStyleSheet("QTextEdit { background-color : black; color : white;font-size: 20px;}");
                qteJugadorUno->setStyleSheet("QTextEdit { background-color : black; color : red;font-size: 20px;}");

                //clickedButton->setStyleSheet("QLabel{ background-color :black;font-size: 40px;color:red; border :0.5px solid #ffffff }");
                QPixmap *pixMaps = new QPixmap(tr("imagenes/casillaX.png"));
                //boton->setStyleSheet("QLabel{ background-color :black;color:blue;font-size: 40px; border :0.5px solid  #ffffff }");

                clickedButton->hasidoClickeada = true;//la celda fue clickeada, se inhabilita
                clickedButton->setPixmap(*pixMaps);
                //clickedButton->setText(str);

                tableroJuego->agregarElemento("X",clickedButton->i,clickedButton->j);

                if(validarGanador(tableroJuego,"X")){
                   qteJugadorUno->setStyleSheet("QTextEdit { background-color : black; color : green;font-size: 20px;}");
                   //qteJugadorUno->append(" HA GANADO ");
                   jugadorUno->setSuTurno(false);
                   jugadorDos->setSuTurno(true);
                   QMessageBox msgBox;
                       msgBox.setText("Ganador");
                       msgBox.setInformativeText(qteJugadorUno->toPlainText());
                       msgBox.setStandardButtons(QMessageBox::Cancel);
                       msgBox.setDefaultButton(QMessageBox::Cancel);
                       msgBox.exec();
                       jugadorUno->setSuTurno(false);
                       jugadorDos->setSuTurno(false);
                }
                else{
                    jugadorUno->setSuTurno(false);
                    jugadorDos->setSuTurno(true);
                }

            }
            else if(jugadorDos->esSuTurno()){
                str = tr("O");
                qteJugadorDos->setStyleSheet("QTextEdit { background-color : black; color : blue;font-size: 20px;}");
                qteJugadorUno->setStyleSheet("QTextEdit { background-color : black; color : white;font-size: 20px;}");

                //clickedButton->setStyleSheet("QLabel{ background-color :black;font-size: 40px;color:blue; border :0.5px solid #ffffff }");
                clickedButton->hasidoClickeada = true;//la celda fue clickeada, se inhabilita
                QPixmap *pixMaps = new QPixmap(tr("imagenes/casillaO.png"));
                //clickedButton->setText(str);
                clickedButton->setPixmap(*pixMaps);
                tableroJuego->agregarElemento("O",clickedButton->i,clickedButton->j);

                if(validarGanador(tableroJuego,"O")){
                   qteJugadorDos->setStyleSheet("QTextEdit { background-color : black; color : green;font-size: 20px;}");
                   QMessageBox msgBox;
                       msgBox.setText("Ganador");
                       msgBox.setInformativeText(qteJugadorDos->toPlainText());
                       msgBox.setStandardButtons(QMessageBox::Cancel);
                       msgBox.setDefaultButton(QMessageBox::Cancel);
                       msgBox.exec();
                       jugadorUno->setSuTurno(false);
                       jugadorDos->setSuTurno(false);
                }
                else{
                    jugadorUno->setSuTurno(true);
                    jugadorDos->setSuTurno(false);
                }

            }


      }

    }
}




void Ventanatriqui::manejarSesionJUno(){
    QTextEdit *textE1= qobject_cast<QTextEdit *>(sender());
    jugadorUno->setNombre(textE1->toPlainText().toStdString());


        jugadorUno->setNombre(textE1->toPlainText().toStdString());


        if((!jugadorUno->getNombre().empty())&&(!jugadorDos->getNombre().empty())){
            iniciar=true;
        }
        else{
           iniciar=false;
        }


  cout<<jugadorUno->getNombre()<<endl;
}

void Ventanatriqui::manejarSesionJDos(){
    QTextEdit *textE1= qobject_cast<QTextEdit *>(sender());
    jugadorDos->setNombre(textE1->toPlainText().toStdString());


        jugadorDos->setNombre(textE1->toPlainText().toStdString());

        if((!jugadorUno->getNombre().empty())&&(!jugadorDos->getNombre().empty())){
            iniciar=true;
        }
        else{
              iniciar=false;
        }
  cout<<jugadorDos->getNombre()<<endl;
}
bool Ventanatriqui::validarGanador(Tablero *matriz,string simbolo){


    if((matriz->obtenerElemento(0,0)==simbolo)&&(matriz->obtenerElemento(0,1)==simbolo)&&(matriz->obtenerElemento(0,2)==simbolo)){
        return true;
    }
    else if((matriz->obtenerElemento(1,0)==simbolo)&&(matriz->obtenerElemento(1,1)==simbolo)&&(matriz->obtenerElemento(1,2)==simbolo)){
        return true;
    }
    else if((matriz->obtenerElemento(2,0)==simbolo)&&(matriz->obtenerElemento(2,1)==simbolo)&&(matriz->obtenerElemento(2,2)==simbolo)){
        return true;
    }
    else if((matriz->obtenerElemento(0,0)==simbolo)&&(matriz->obtenerElemento(1,0)==simbolo)&&(matriz->obtenerElemento(2,0)==simbolo)){
        return true;
    }
    else if((matriz->obtenerElemento(0,1)==simbolo)&&(matriz->obtenerElemento(1,1)==simbolo)&&(matriz->obtenerElemento(2,1)==simbolo)){
        return true;
    }
    else if((matriz->obtenerElemento(0,2)==simbolo)&&(matriz->obtenerElemento(1,2)==simbolo)&&(matriz->obtenerElemento(2,2)==simbolo)){
        return true;
    }
    else if((matriz->obtenerElemento(0,0)==simbolo)&&(matriz->obtenerElemento(1,1)==simbolo)&&(matriz->obtenerElemento(1,2)==simbolo)){
        return true;
    }
    else if((matriz->obtenerElemento(0,2)==simbolo)&&(matriz->obtenerElemento(1,1)==simbolo)&&(matriz->obtenerElemento(2,0)==simbolo)){
        return true;
    }
    else{
        return false;
    }
}

void Ventanatriqui::createFormGroupBox()
{
    formGroupBox = new QGroupBox(tr("Form layout"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Line 1:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Line 2, long text:")), new QComboBox);
    layout->addRow(new QLabel(tr("Line 3:")), new QSpinBox);
    formGroupBox->setLayout(layout);
}

