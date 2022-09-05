#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "maze.h"

#include <windows.h>

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>

class Labirint : public QWidget
{
    Q_OBJECT

public:
    Labirint (QWidget *parent = nullptr);
    ~Labirint();




    void setimgpath(Maze *mymaze);


    virtual void paintEvent(QPaintEvent *event) override;

//    public slots:
//void setimgpath_slot(Maze *mymaze, bool forward);

private:
    int resolution = 2;
    int wallsize   = 1;
    int rslmwll = resolution - wallsize;

    Memo*  Iterator;
    QRectF leftwall_rect;
    QRectF downwall_rect;
    QRectF cellbody_rect;

    void color_empty_maze(Maze &mymaze);
    void color_cells(Maze *mymaze, int &x, int &y, QRgb colrin, QRgb colorwall);

    QPainter* Paint;
};
#endif // MAINWINDOW_H
