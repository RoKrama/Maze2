#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "maze.h"

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QPixmap>

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

    void setmazegraph(Maze &mymaze);
    void setpixcell(Maze &mymaze, int &x, int &y, QRgb colrin, QRgb colorwall);
    void qprintcell(Maze &mymaze);

private:
    Ui::MainWindow *ui;

    int resolution =4;
    int wallsize = 1;
    int rslmwll = resolution - wallsize;

    int* iteratePrev(Memo** iterator);
};
#endif // MAINWINDOW_H
