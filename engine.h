#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <random>
#include <cstdlib>
#include <algorithm>
#include <qtmetamacros.h>
#include <QMetaObject>
#include <QString>
#include "qobject.h"
#include <QThread>

class Memo
{
    friend class Engine;

    Memo();
    Memo(int, int);

    int position[2];
    Memo* prev;
    Memo* create;

    Memo* move();
    void insert(int xcr, int ycr);

public:
    int* getPosition() {return (&position[0]);};
    Memo* iteratePrev(int times);
};

enum direction { null, U, D, L, R };
class Cell
{
    Cell();
    friend class Engine;

    bool visit;
    bool searchVisit;
    bool wallleft;
    bool walldown;

    void setto(direction);
    void setfrom(direction);
    void printcell();

public:
    const bool getWallleft() const {return wallleft;};
    const bool getWalldown() const {return walldown;};
};

class Engine : public QObject
{
    Q_OBJECT

    int x, y;

    typedef Cell* cellPtr;
    cellPtr* cell;

    Memo Path;
    Memo searchPath;
    Memo* searchPositionLog;

    void generate(int xp, int yp);

    bool findPathcalled;

public:

    Engine(int xsize, int ysize);
    ~Engine();

    void printEngine() const;
    const cellPtr* getcells() const {return(cell);}
    const int getx() const {return (x);};
    const int gety() const {return (y);};
    void findPath(int startx, int starty);

    Memo* getPositionLog(int fromx, int formy);
    Memo* getPositionLog(Memo* Iterator);

signals:
    void sendsignal(const int &signal_x, const int &signal_y, bool forward);

};

#endif // ENGINE_H
