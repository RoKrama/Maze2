#ifndef ANIMA_H
#define ANIMA_H
#include "labirint.h"

class Animat : public QWidget
{
    Q_OBJECT

    Labirint* MainWindow;
    const int milisec;

public slots:
    void updator();

public:
    Animat(Labirint* mainW);
};
#endif // ANIMA_H
