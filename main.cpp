#include "mainwindow.h"
#include <QApplication>
#include "maze.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int hight = 20;
    int width = 20;
    w.showMaximized();

    Maze labirint(hight, width);
    w.setmazegraph(labirint);


//    labirint.printMaze();
    return a.exec();
}
