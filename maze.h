#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <random>
#include <cstdlib>
#include <algorithm>

using namespace std;

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

};

enum direction { null, U, D, L, R };
class Cell
{
	Cell();
	friend class Maze;

	bool visit;

	void setto(direction);
	void setfrom(direction);
    void printcell();

public:
    bool wallleft;
    bool walldown;
};

class Maze
{
	int x, y;

	typedef Cell* cellPtr;
	cellPtr* cell;
	Memo Path;
    void generate(int xp, int yp);


public:
	Maze(int xsize, int ysize);
	~Maze();

	void printMaze();
    const cellPtr* getcells() const {return(cell);}
    const int getx() const {return (x);};
    const int gety() const {return (y);};

};
#endif // MAZE_H
