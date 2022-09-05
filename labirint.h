#ifndef LABIRINT_H
#define LABIRINT_H

#include "engine.h"
#include <QObject>
#include <QWidget>
#include <QPainter>

class Cell_graphics;

class Labirint : public QWidget
{
    Q_OBJECT

public:

    Labirint(QWidget *parent = nullptr);
    ~Labirint();

    void connect_engine(const Engine &engine);

private:

    int bodysize, wallsize, wholesize;

    const Engine* Scene_engine;
    int x,y;
    void construct_scene();

    QColor Colorof_wall;
    QColor Colorof_body_default;
    QColor Colorof_body_path;
    QColor Colorof_path_backtrack;

    typedef Cell_graphics* Cell_graphics_Ptr;
    Cell_graphics_Ptr* cell_graphics_arrayPtr;

    void add_full_cell(const int &i, const int &j, Cell_graphics &this_cell);

public slots:
    void color_path(const int &signal_x, const int &signal_y, bool forward);
signals:
    void call_updater();

protected:
    void paintEvent(QPaintEvent* event);
};

class Cell_graphics
{
    friend class Labirint;

    Cell_graphics();
    Cell_graphics(QRectF* bodyPtrVal,
                  QRectF* leftPtrVal,
                  QRectF* downPtrVal);
  //  ~Cell_graphics();

    QRectF* bodyPtr;
    QRectF* leftPtr;
    QRectF* downPtr;

    bool visited;
    bool visiting;
};

#endif // LABIRINT_H
