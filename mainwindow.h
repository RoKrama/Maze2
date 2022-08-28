#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "maze.h"

#include <windows.h>

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QLabel *mazegraph = new QLabel(this);
    QImage image;
    Memo* Iterator;

    void setmazegraph(Maze &mymaze);
    void setimgcell(Maze *mymaze, int &x, int &y, QRgb colrin, QRgb colorwall);
    void setimgpath(Maze *mymaze);
    QPixmap imagepixmap = QPixmap(1000, 1000);
    QRectF myrect = QRectF(59,59,50,50);
        QPainter* Paint;


    public slots:
        void setimgpath_slot(Maze *mymaze, bool forward);

private:
    Ui::MainWindow *ui;

    int resolution =4;
    int wallsize = 1;
    int rslmwll = resolution - wallsize;

    int* iteratePrev(Memo** iterator);

};
#endif // MAINWINDOW_H
