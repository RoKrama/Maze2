#include "mainwindow.h"
#include <QApplication>
#include "maze.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int hight = 353;
    int width = 639;

    w.showMaximized();
    Maze labirint(hight, width);
    w.setmazegraph(labirint);
    return a.exec();
}
