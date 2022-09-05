#include "mainwindow.h"

Labirint::Labirint(QWidget *parent)
    : QWidget(parent),
      leftwall_rect(QRectF(resolution+rslmwll, resolution, wallsize, resolution)),
      downwall_rect(QRectF(resolution, resolution+rslmwll, resolution, wallsize)),
      cellbody_rect(QRectF(resolution, resolution, rslmwll, rslmwll)),
      Paint(new QPainter(this))
{
    setWindowTitle("Labirint");
}
Labirint::~Labirint()
{
    delete Paint;
}

void Labirint::color_empty_maze(Maze &mymaze)
{
    int y = mymaze.getx();
    int x = mymaze.gety();

        for(int i = 0; i<x*resolution+wallsize; i++)
        {
            leftwall_rect.setX(x*resolution+wallsize);
            for(int j = 0; j<y*resolution+wallsize; j++)
            {
                leftwall_rect.setY(y*resolution+wallsize);

                Paint->fillRect(leftwall_rect, QColor("black").rgb());
                Paint->fillRect(downwall_rect, QColor("black").rgb());
            }
        }


//        for(int i = 0; i<x; i++)
//            for(int j = 0; j<y; j++)
//                color_cells(&mymaze, i, j, QColor("grey").rgb(), QColor("grey").rgb());


}
//void Labirint::color_cells(Maze *mymaze, int &x, int &y, QRgb colrin, QRgb colrwall)
//{
//    for (int i = 0; i<rslmwll; i++)
//        for (int j = 0; j<rslmwll; j++)


//    if(mymaze->getcells()[y][x].getWallleft() == false)
//        for (int i = rslmwll; i<resolution; i++)
//            for (int j = 0; j<rslmwll; j++)


//    if(mymaze->getcells()[y][x].getWalldown() == false)
//        for (int i = 0; i<rslmwll; i++)
//            for (int j = rslmwll; j<resolution; j++)



//    return;
//}

//void Labirint::setimgpath(Maze *mymaze)
//{
//    Iterator = mymaze->getPositionLog(0,0);

//    while(true)
//    {
//        setimgcell(mymaze, Iterator->getPosition()[1], Iterator->getPosition()[0],
//             QColor("pink").rgb(), QColor("pink").rgb()) ;

//        if(!(Iterator->getPosition()[1] == 0 &&
//             Iterator->getPosition()[0] == 0) )
//                Iterator = mymaze->getPositionLog(Iterator);
//        else return;

//    }
//}

//void Labirint::setimgpath_slot(Maze *mymaze, bool forward)
//{
//    if (forward == true)
//    {
//    Iterator = mymaze->getPositionLog(0,0);
//    setimgcell(mymaze, Iterator->getPosition()[1], Iterator->getPosition()[0],
//         QColor("black").rgb(), QColor("black").rgb()) ;
//    }
//    if (forward == false)
//    {
//        Iterator = mymaze->getPositionLog(0,0);
//        setimgcell(mymaze, Iterator->getPosition()[1], Iterator->getPosition()[0],
//             QColor("pink").rgb(), QColor("pink").rgb()) ;
//    }
//   // mazegraph.update();
//}

void Labirint::paintEvent(QPaintEvent *event)
{

int y = 59;
int x = 55;

    for(int i = 0; i<x*resolution+wallsize; i++)
    {
        leftwall_rect.setX(x*resolution+wallsize);
        for(int j = 0; j<y*resolution+wallsize; j++)
        {
            leftwall_rect.setY(y*resolution+wallsize);

            Paint->fillRect(leftwall_rect, QColor("black").rgb());
            Paint->fillRect(downwall_rect, QColor("black").rgb());
        }
    }
}
