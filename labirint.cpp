#include "labirint.h"

Labirint::Labirint(QWidget *parent) :
    QWidget(parent),

    bodysize(2), wallsize(1),
    wholesize(bodysize+wallsize),
    x(0), y(0),

    Scene_engine(nullptr),

    Colorof_wall(QColor("black").rgb()),
    Colorof_body_default(QColor("gray").rgb()),
    Colorof_body_path(QColor("orange").rgb()),
    Colorof_path_backtrack(QColor("pink").rgb()),

    cell_graphics_arrayPtr(nullptr)
{
    setWindowTitle("Labirint");
    setGeometry(0,0,1500, 1500);
}
Labirint::~Labirint()
{

    for (int i = 0; i < x; i++)
        delete[] cell_graphics_arrayPtr[i];
    delete[] cell_graphics_arrayPtr;
}

void Labirint::connect_engine(const Engine &engine)
{
    Scene_engine = &engine;
    connect(&engine, &Engine::sendsignal, this, &Labirint::color_path);
    y = Scene_engine->getx();
    x = Scene_engine->gety();

    cell_graphics_arrayPtr = new Cell_graphics_Ptr[x];
    for(int i=0; i < x; i++)
        cell_graphics_arrayPtr[i] = new Cell_graphics[y];

    construct_scene();
}
void Labirint::construct_scene()
{
    for(int i=0; i < x; i++) for(int j=0; j < y; j++)
        add_full_cell(i, j, cell_graphics_arrayPtr[i][j]);

}
void Labirint::add_full_cell(const int &i, const int &j, Cell_graphics &this_cell)
{
    QRectF* bodyPtr;
    QRectF* leftPtr;
    QRectF* downPtr;

    bodyPtr = new QRectF(i*wholesize, j*wholesize, bodysize, bodysize);
    downPtr = new QRectF(i*wholesize, j*wholesize + bodysize, bodysize, wallsize);
    leftPtr = new QRectF(i*wholesize + bodysize, j*wholesize, wallsize, bodysize);

    this_cell = Cell_graphics(bodyPtr, leftPtr, downPtr);
}

void Labirint::color_path(const int &signal_x, const int &signal_y, bool forward)
{
    if (forward)
        cell_graphics_arrayPtr[signal_y][signal_x].visiting = true;

    else
    {
        cell_graphics_arrayPtr[signal_y][signal_x].visiting = false;
        cell_graphics_arrayPtr[signal_y][signal_x].visited = true;
    }
    call_updater();
}
void Labirint::paintEvent(QPaintEvent* event)
{

    QPainter Painter;
    Painter.begin(this);

    for(int i=0; i < x; i++) for(int j=0; j < y; j++)
    {
        Painter.fillRect((i+1)*wholesize-wallsize, (j+1)*wholesize-wallsize, wallsize, wallsize, Colorof_wall);

        if (cell_graphics_arrayPtr[i][j].visiting == true)
        {
            Painter.fillRect(*cell_graphics_arrayPtr[i][j].bodyPtr, Colorof_body_path);

            if(Scene_engine->getcells()[j][i].getWalldown() == false)
                Painter.fillRect(*cell_graphics_arrayPtr[i][j].downPtr, Colorof_body_path);
            else
                Painter.fillRect(*cell_graphics_arrayPtr[i][j].downPtr, Colorof_wall);
            if(Scene_engine->getcells()[j][i].getWallleft() == false)
                Painter.fillRect(*cell_graphics_arrayPtr[i][j].leftPtr, Colorof_body_path);
            else
                Painter.fillRect(*cell_graphics_arrayPtr[i][j].leftPtr, Colorof_wall);
            continue;
        }
        if (cell_graphics_arrayPtr[i][j].visited == true)
        {
            Painter.fillRect(*cell_graphics_arrayPtr[i][j].bodyPtr, Colorof_path_backtrack);

            if(Scene_engine->getcells()[j][i].getWalldown() == false)
                Painter.fillRect(*cell_graphics_arrayPtr[i][j].downPtr, Colorof_path_backtrack);
            else
                Painter.fillRect(*cell_graphics_arrayPtr[i][j].downPtr, Colorof_wall);
            if(Scene_engine->getcells()[j][i].getWallleft() == false)
                Painter.fillRect(*cell_graphics_arrayPtr[i][j].leftPtr, Colorof_path_backtrack);
            else
                Painter.fillRect(*cell_graphics_arrayPtr[i][j].leftPtr, Colorof_wall);
            continue;
        }
        else
        {
            Painter.fillRect(*cell_graphics_arrayPtr[i][j].bodyPtr, Colorof_body_default);

            if(Scene_engine->getcells()[j][i].getWalldown() == false)
                Painter.fillRect(*cell_graphics_arrayPtr[i][j].downPtr, Colorof_body_default);
            else
                Painter.fillRect(*cell_graphics_arrayPtr[i][j].downPtr, Colorof_wall);
            if(Scene_engine->getcells()[j][i].getWallleft() == false)
                Painter.fillRect(*cell_graphics_arrayPtr[i][j].leftPtr, Colorof_body_default);
            else
                Painter.fillRect(*cell_graphics_arrayPtr[i][j].leftPtr, Colorof_wall);
        }
    }
    Painter.end();
}

Cell_graphics::Cell_graphics(){}
Cell_graphics::Cell_graphics(QRectF* bodyPtrVal,
                             QRectF* leftPtrVal,
                             QRectF* downPtrVal) :
    bodyPtr(bodyPtrVal),
    leftPtr(leftPtrVal),
    downPtr(downPtrVal),
    visiting(false),
    visited(false)
{}
//Cell_graphics::~Cell_graphics()
//{
//    delete bodyPtr;
//    delete leftPtr;
//    delete downPtr;
//}
