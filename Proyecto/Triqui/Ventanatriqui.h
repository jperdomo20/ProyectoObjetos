
#ifndef Ventanatriqui_H
#define Ventanatriqui_H

#include "libSonic/Jugador.hpp"
#include "libSonic/Tablero.hpp"
#include "Celda.h"
#include <iostream>
#include <QDialog>

#include <QAction>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QTextEdit>
#include <QBoxLayout>
#include <QSpinBox>
#include <QGroupBox>
#include <QFormLayout>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
#include <QString>

class Ventanatriqui : public QDialog
{
    Q_OBJECT

public:
    Ventanatriqui();

private:
    void crearMenu();
    void crearPanelTitulo();
    void crearTablero();
    void createFormGroupBox();
    void crearSubPanelJugadores();
    bool validarGanador(Tablero *matriz,string simbolo);

    enum { numeroDeCeldas = 3, NumButtons = 4 };

    int turno;
    bool iniciar;

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QGroupBox *gridGroupBox;
    QGroupBox *formGroupBox;
    QTextEdit *smallEditor;
    QTextEdit *bigEditor;
    QLabel *labels[numeroDeCeldas];
    QLineEdit *lineEdits[numeroDeCeldas];
    QPushButton *buttons[NumButtons];
    Celda *botones[numeroDeCeldas][numeroDeCeldas];
    QDialogButtonBox *buttonBox;
    QPixmap *pixMapX;
    QPixmap *pixMapO;
    QIcon *ButtonX;
    QIcon *ButtonO;

    QMenu *fileMenu;
    QAction *exitAction;
    QAction *scoreAction;


    QGroupBox *gbJugadores;
    QTextEdit *qteJugadorUno;
    QTextEdit *qteJugadorDos;
    QLabel *qlJugadorUno;
    QLabel *qlJugadorDos;
    QFormLayout *layoutF;

    Jugador *jugadorUno,*jugadorDos;
    Tablero *tableroJuego;

private slots:
    void manejadorBoton();
    void manejarSesionJUno();
    void manejarSesionJDos();
    void verPuntajes();
};


#endif
