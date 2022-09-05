#include "anima.h"

Animat::Animat(Labirint* mainW) :
    milisec(3),
    MainWindow(mainW)
{
    connect(MainWindow, &Labirint::call_updater, this, &Animat::updator);
}
void Animat::updator()
{
    //QThread::msleep(milisec);
    MainWindow->repaint();
}
