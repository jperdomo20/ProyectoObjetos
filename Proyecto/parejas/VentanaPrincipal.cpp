#include <QtGui>

#include "VentanaPrincipal.h"

VentanaPrincipal::VentanaPrincipal()
{
    crearControl();

    cargarImagenes();
    crearMenu();
    crearPanelTitulo();
    crearTablero();
    crearPanelPie();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(horizontalGroupBox);
    mainLayout->addWidget(gridGroupBox);
    mainLayout->addWidget(horizontalGroupBox2);
    setLayout(mainLayout);

    setWindowTitle(tr("Parejas"));
}

void VentanaPrincipal::crearControl()
{
    p = new Puntajes();
    objControlador = new control(12, p);
}

void VentanaPrincipal::cargarImagenes()
{
    turno = 0;
    nul = 13;
    ultimaCeldaVisitada = NULL;
    for(int i=0; i<14; i++)
        pixMaps[i] = new QPixmap(tr("imgPack/%1.png").arg(i));
}

void VentanaPrincipal::crearMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&Archivo"), this);
    newAction = fileMenu->addAction(tr("&Nuevo"));
    exitAction = fileMenu->addAction(tr("E&xit"));

    fileScore = new QMenu(tr("&Score"), this);
    scoreAction = fileScore->addAction(tr("&Ver"));

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(fileScore);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
    connect(newAction, SIGNAL(triggered()), this, SLOT(nuevoJuego()));
    connect(scoreAction, SIGNAL(triggered()), this, SLOT(verPuntajes()));
}

void VentanaPrincipal::verPuntajes()
{
    QMessageBox msgBox;
    QString p =  QString::fromStdString(objControlador->retomarPuntajesMaximos());
        msgBox.setText("ScoreBoard");
        msgBox.setInformativeText(p);
        msgBox.setStandardButtons(QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        msgBox.exec();
}

void VentanaPrincipal::nuevoJuego()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Jugadores"),
                                            tr("Ingresa el número de jugadores (maximo 2):"), QLineEdit::Normal,
                                            "", &ok);

    if( text.toInt() == 2)
    {
        numerojugadores=2;
        numeroParejas = 12;
    }else
    {
        numerojugadores=text.toInt();
        numeroParejas = 12;
    }
    iniciarTablero();
}

void VentanaPrincipal::crearPanelTitulo()
{
    horizontalGroupBox = new QGroupBox();
    QHBoxLayout *layout = new QHBoxLayout;
    titulo = new QLabel();
    QPixmap imgTitulo("imgPack/titulo.png");
    titulo->setPixmap(imgTitulo);
    layout->addWidget(titulo);

    horizontalGroupBox->setLayout(layout);
}

void VentanaPrincipal::crearTablero()
{
    gridGroupBox = new QGroupBox(tr("Tablero"));

    QGridLayout *glayout = new QGridLayout();
    glayout->setSpacing(2);
    glayout->setContentsMargins(0,0,0,0);

    int largo = objControlador->ancho;
    int ancho = objControlador->largo; //6 x 4
    int id=0;

    for (int i = 0; i < ancho; ++i) {
        QVector<Celda*> fila;

        for (int j=0; j < largo; ++j, id++)
        {
            Celda *boton = new Celda();
            boton->construirCelda(tr("%1").arg(nul), id, i, j);
            boton->setPixmap(*pixMaps[nul]);
            fila.push_back(boton);
            glayout->addWidget(boton, i + 1, j+1);
            connect(boton,SIGNAL(clicked()),this, SLOT(manejadorBoton()));
        }
        botones.push_back(fila);
    }
    //std::cout << botones[0].size() << endl;
    gridGroupBox->setLayout(glayout);
}

void VentanaPrincipal::iniciarTablero()
{
    objControlador=new control(numeroParejas, p);
    int largo = objControlador->ancho;
    int ancho = objControlador->largo;
    int id=0;
    ultimaCeldaVisitada=NULL;
    clickedButton=NULL;
    dosUltimas.clear();
    turno =0;
    for (int i = 0; i < ancho; ++i) {
        for (int j=0; j < largo; ++j, id++)
        {
            Celda *boton = (botones.at(i)).at(j);
            if(boton != NULL)
            {
                boton->hasidoClickeada = false;
                boton->nula = false;

                QString s=  QString::fromStdString(objControlador->tab->obtenerElemento(i,j));
                boton->construirCelda(s, id, i, j);
                if(s.toInt()>=1 and s.toInt()<=13)
                {
                    boton->setPixmap(*pixMaps[0]);
                }
            }else {std::cout << "error" << endl;}
        }
    }
    objControlador->IniciarJuego(numerojugadores);
}
void VentanaPrincipal::comparadorCeldas()
{
    if (dosUltimas.size()==0) // si es nula entonces asigne
    {
        dosUltimas.push_back(clickedButton);
        std::cout << "Tiene 0" << std::endl;
    }
    else if(dosUltimas.size()==1)
    {
        dosUltimas.push_back(clickedButton);

    }
    else if(dosUltimas.size()==2)
    {
        std::cout << "Tiene 2" << std::endl;
        if((dosUltimas.at(0))->nomb == dosUltimas.at(1)->nomb
           && dosUltimas.at(0)->id != dosUltimas.at(1)->id) //ya que las parejas son iguales, entonces....
        {
            dosUltimas.at(0)->setPixmap(*pixMaps[nul]);
            dosUltimas.at(1)->setPixmap(*pixMaps[nul]);
            dosUltimas.at(0)->nomb= tr("%1").arg(nul);
            dosUltimas.at(1)->nomb= tr("%1").arg(nul);
            std::cout << "Son iguales" << std::endl;
            numeroParejas--;
            objControlador->asignarPuntajeJugador(10);
            if(numeroParejas==0)
            {
                bool ok;
                QString ganador =
                        QInputDialog::getText(this,
                                                  tr("Ganador"),
                                                  tr("Has ganado en %1 segundos \n Jugador:").arg(objControlador->tiempoTotal()),
                                                  QLineEdit::Normal,"", &ok);
                objControlador->asignarNombreJugador(ganador.toStdString());
            }
        }
        else
        {
            cambiarImagen(0, dosUltimas.at(0));
            cambiarImagen(0, dosUltimas.at(1));
            dosUltimas.at(0)->hasidoClickeada = false;
            dosUltimas.at(1)->hasidoClickeada = false;
            std::cout << "Son distintas" << std::endl;
            objControlador->siguienteJugador();
            turno= (turno+1)%numerojugadores;
        }        

        bool nueva = (clickedButton->id != dosUltimas.at(0)->id &&
           clickedButton->id != dosUltimas.at(1)->id);
        dosUltimas.clear();
        if(nueva)
            dosUltimas.push_back(clickedButton);
        labelTurno->setText(tr("Turno de %1").arg(turno+1));
    }else{std::cout << "Error" << std::endl;}
}

void VentanaPrincipal::manejadorBoton()
{
    clickedButton = qobject_cast<Celda *>(sender());
    int a = (clickedButton->nomb).toInt(); // numero correspondiente a la pareja
    if(a!=nul)          
    {
        if(clickedButton->hasidoClickeada && dosUltimas.size()==1)  
        {
            cambiarImagen(0, clickedButton);
            clickedButton->hasidoClickeada = false;
            dosUltimas.clear();
            std::cout << "Click sobre si misma" << std::endl;
        }else{
            cambiarImagen(a, clickedButton);
            clickedButton->hasidoClickeada = true;
            comparadorCeldas();
            std::cout << "Click sobre otra" << std::endl;
        }
    }
}

void VentanaPrincipal::cambiarImagen(int i,Celda * clickedButton)
{
    clickedButton->setPixmap(*pixMaps[i]);
}

void VentanaPrincipal::crearPanelPie()
{
    horizontalGroupBox2 = new QGroupBox();
    QHBoxLayout *layout = new QHBoxLayout;
    labelTurno = new QLabel("Empieza jugador 1");
    layout->addWidget(labelTurno);

    horizontalGroupBox2->setLayout(layout);
}

int VentanaPrincipal::randInt(int low, int high)
    {
    return qrand() % ((high + 1) - low) + low;
    }
