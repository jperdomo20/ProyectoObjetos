#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <iostream>
#include <QAction>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QIcon>
#include <QMenu>
#include <QVector>
#include <QMenuBar>
#include <QPushButton>
#include <QTextEdit>
#include <QGridLayout>
#include "celda.h"
#include "control.h"

class VentanaPrincipal : public QDialog
{
    Q_OBJECT

public:
    VentanaPrincipal();

    void comparadorCeldas();
private:
    void crearMenu();
    void crearControl();
    void crearPanelTitulo();
    void crearTablero();
    void crearPanelPie();
    void cargarImagenes();
    int  randInt(int low, int high);
    void cambiarImagen(int i, Celda *clickedButton);
    void iniciarTablero();

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QGroupBox *horizontalGroupBox2;
    QGroupBox *gridGroupBox;
    QVector<QVector<Celda* > > botones;

    QPixmap *pixMaps[14];
    QPixmap *nula;
    QLabel *titulo;
    QLabel *labelTurno ;
    QMenu *fileMenu;
    QAction *exitAction;
    QAction *newAction;
    QMenu *fileScore;
    QAction *scoreAction;
    control *objControlador;

    Celda *ultimaCeldaVisitada;
    Celda *clickedButton;
    QVector<Celda*> dosUltimas;
    int turno;
    int numeroParejas;
    int numerojugadores;
    int nul;
    Puntajes *p;
private slots:
    void manejadorBoton();
    void nuevoJuego();
    void verPuntajes();
};

#endif
