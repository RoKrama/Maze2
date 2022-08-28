#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <random>
#include <cstdlib>
#include <algorithm>
#include <windows.h>
#include <qtmetamacros.h>
#include <QMetaObject>
#include <QString>
#include "qobject.h"


class Memo
{
	friend class Maze;

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
	friend class Maze;

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

class Maze : public QObject
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

    signals:
        void sendsignal(Maze* mymaze, bool forward);



public:

	Maze(int xsize, int ysize);
	~Maze();

    void printMaze() const;
    const cellPtr* getcells() const {return(cell);}
    const int getx() const {return (x);};
    const int gety() const {return (y);};
    void findPath(int startx, int starty);

    Memo* getPositionLog(int fromx, int formy);
    Memo* getPositionLog(Memo* Iterator);
};
Q_DECLARE_METATYPE(Maze)
#endif // MAZE_H
