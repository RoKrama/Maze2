#include "mainwindow.h"
#include <QApplication>
#include "maze.h"
#include <QTimer>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int hight = 26; //352;
    int width = 44; //638;

    MainWindow window;
        window.showMaximized();
    Maze labirint(hight, width);
    qRegisterMetaType<Maze>();
    QObject::connect(&labirint, &Maze::sendsignal,
                     &window, &MainWindow::setimgpath_slot, Qt::QueuedConnection);
        window.imagepixmap.fill();
            labirint.findPath(0,0);
    window.setmazegraph(labirint);

window.setimgpath(&labirint);

  //  window.mazegraph->setPixmap(QPixmap::fromImage(window.image));

    return a.exec();
}
