#include <QApplication>

#include "Ventanatriqui.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Ventanatriqui ventana;
    ventana.show();

    return app.exec();
}
