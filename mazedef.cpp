#include "maze.h"


Maze::Maze(int xsize, int ysize) :
    x(xsize), y(ysize),
    Path(0, 0),
    searchPositionLog(&searchPath),
    findPathcalled(false),
    cell(new cellPtr[x])
{
	for (int i = 0; i < x; i++)
        cell[i] = new Cell[y];

    generate((x-1), (y-1));
}
void Maze::generate(int xpos, int ypos)
{
	int tried;
	Path = Memo(xpos, ypos);
	cell[xpos][ypos].visit = true;
	cell[x - 1][y - 1].setfrom(R);

    std::random_device rng;
    std::mt19937 rngnr(rng());

	int cases[4] = { 0,1,2,3 };

	do {
		tried = 0;
		while (tried != 4)
		{
        std::shuffle(&cases[0], &cases[4], rngnr);
			tried = 0;

			for (int i = 0; i < 4; i++)
			{
				if (cases[i] == 0)
				{
					if (ypos < (y - 1) && cell[xpos][ypos + 1].visit == false)
					{

						cell[xpos][ypos].setto(L);
						ypos = ypos + 1;

						cell[xpos][ypos].visit = true;
						Path.insert(xpos, ypos);

                        break;
					}
					tried++;
					continue;
				}
				if (cases[i] == 1)
				{
					if (xpos > 0 && cell[xpos - 1][ypos].visit == false)
					{
						xpos = xpos - 1;

						cell[xpos][ypos].visit = true;
						cell[xpos][ypos].setfrom(D);
						Path.insert(xpos, ypos);

                        break;
					}
					tried++;
					continue;
				}
				if (cases[i] == 2)
				{
					if (ypos > 0 && cell[xpos][ypos - 1].visit == false)
					{
						ypos = ypos - 1;

						cell[xpos][ypos].visit = true;
						cell[xpos][ypos].setfrom(R);
						Path.insert(xpos, ypos);

                        break;
					}
					tried++;
					continue;
				}
				if (cases[i] == 3)
				{
					if (xpos < (x - 1) && cell[xpos + 1][ypos].visit == false)
					{
						cell[xpos][ypos].setto(U);
						xpos = xpos + 1;

						cell[xpos][ypos].visit = true;
						Path.insert(xpos, ypos);

                        break;
					}
					tried++;
					continue;
				}
			}
        }
		Path.move();
		xpos = Path.prev->position[0];
		ypos = Path.prev->position[1];
	}
	while (Path.prev->prev != nullptr);

}
void Maze::findPath(int startx, int starty)
{
    int tried;
    searchPath = Memo(startx, starty);
    searchPath.insert(startx, starty);

    std::random_device rng;
    std::mt19937 rngnr(rng());

    int cases[4] = { 0,1,2,3 };

    do {
        tried = 0;
        while (tried < 4)
        {
        std::shuffle(&cases[0], &cases[4], rngnr);
            tried = 0;

            for (int i = 0; i < 4; i++)
            {
                if (cases[i] == 0)
                {
                    if (starty < (y - 1) && cell[startx][starty + 1].searchVisit == false)
                    {
                        if(cell[startx][starty].wallleft == false)
                        {
                            starty = starty + 1;
                            cell[startx][starty].searchVisit = true;
                            searchPath.insert(startx, starty);
                            break;
                        }
                    }
                    tried++;
                    continue;
                }
                if (cases[i] == 1)
                {
                    if (startx > 0 && cell[startx - 1][starty].searchVisit == false)
                    {
                        if(cell[startx - 1][starty].walldown == false)
                        {
                        startx = startx - 1;
                        cell[startx][starty].searchVisit = true;
                        searchPath.insert(startx, starty);
                        break;
                        }
                    }
                    tried++;
                    continue;
                }
                if (cases[i] == 2)
                {
                    if (starty > 0 && cell[startx][starty - 1].searchVisit == false)
                    {
                        if(cell[startx][starty - 1].wallleft == false)
                        {
                        starty = starty - 1;
                        cell[startx][starty].searchVisit = true;
                        searchPath.insert(startx, starty);
                        break;
                        }
                    }
                    tried++;
                    continue;
                }
                if (cases[i] == 3)
                {
                    if (startx < (x - 1) && cell[startx + 1][starty].searchVisit == false)
                    {
                        if (cell[startx][starty].walldown == false)
                        {
                        startx = startx + 1;
                        cell[startx][starty].searchVisit = true;
                        searchPath.insert(startx, starty);
                        break;
                        }
                    }
                    tried++;
                    continue;
                }
            }
          //  Sleep(1090);
            if (startx == x-1 && starty == y-1)
                return;
           // emit sendsignal(this, true);
        }
     //   emit sendsignal(this, false);
        searchPath.move();
        startx = searchPath.prev->position[0];
        starty = searchPath.prev->position[1];
    }
    while (searchPath.prev->prev != nullptr);
    return;
}
Memo* Maze::getPositionLog(int fromx, int fromy)
{
/*    if(findPathcalled == false)
    {
        findPath(fromx, fromy);
        findPathcalled = true;
    } */
    return (searchPositionLog->iteratePrev(0));
}
Memo* Maze::getPositionLog(Memo* Iterator){
    return(Iterator->iteratePrev(0));
}
void Maze::printMaze() const
{
    std::cout << ' ';
    for (int k = 0; k < y; k++)
        std::cout << "_ ";
    std::cout << std::endl << ' ';

    for (int i = 0; i < x; i++)
	{
        for (int j = 0; j < y; j++)
            //cell[i][j].printcell();
            //std::cout<<"i:"<<i<<" j:"<<j;
            cell[searchPath.position[0]][searchPath.position[1]].printcell();
        std::cout << std::endl << '|';
	}
    std::cout << "\b ";
}
Maze::~Maze()
{
	for (int j = 0; j < x; j++)
		delete[] cell[j];
	delete[] cell;
}

Cell::Cell() :
	wallleft(true), walldown(true),
    visit(false), searchVisit(false) {}
void Cell::setfrom(direction frm)
{
	if (frm == D) walldown = false;
	if (frm == R) wallleft = false;
}
void Cell::setto(direction t)
{
	if (t == U) walldown = false;
	if (t == L) wallleft = false;
}
void Cell::printcell()
{
    if (walldown == true) std::cout << '_';
    else std::cout << ' ';

    if (wallleft == true) std::cout << '|';
    else std::cout << ' ';
}

Memo::Memo() :
	prev(nullptr), create(nullptr)
{
	position[0] = 0;
	position[1] = 0;
}
Memo::Memo(int xcr, int ycr) :
	prev(nullptr), create(nullptr)
{
	position[0] = xcr;
	position[1] = ycr;
}
void Memo::insert(int xcr, int ycr)
{
	create = new Memo(xcr, ycr);
	create->prev = prev;
	prev = create;
	return;
}
Memo* Memo::move()
{
	prev = prev->prev;
	return (prev);
}
Memo* Memo::iteratePrev(int times)
{
    if(prev != nullptr && times > 0)
    {
        times--;
        return(prev->iteratePrev(times));
    }
    return(prev);
}
