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
    void setpixcell(Maze &mymaze, int &x, int &y);
    void qprintcell(Maze &mymaze);

private:
    Ui::MainWindow *ui;

    int resolution =8;
    int wallsize = 4;
    int rslmwll = resolution - wallsize;
};
#endif // MAINWINDOW_H
