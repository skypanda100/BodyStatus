#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QApplication::setPalette(QApplication::style()->standardPalette());

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
