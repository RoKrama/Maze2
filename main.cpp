#include "mainwindow.h"
#include <QApplication>
#include "maze.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int hight = 150;
    int width = 200;

w.showMaximized();
w.repaint();
    Maze labirint(hight, width);
    w.setmazegraph(labirint);

 //   w.repaint();
 //   w.qprintcell(labirint);

    //labirint.findPath(50, 50);

   // labirint.printMaze();
    return a.exec();
}
