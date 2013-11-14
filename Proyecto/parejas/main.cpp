#include <QApplication>
#include <QTime>
#include "VentanaPrincipal.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    VentanaPrincipal dialog;
    dialog.show();
    return app.exec();
}
