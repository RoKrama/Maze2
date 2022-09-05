#include "anima.h"
#include "labirint.h"
#include "engine.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Labirint window;
    Animat Anima(&window);
    Engine Worker(470, 850);
    window.showMaximized();
    window.connect_engine(Worker);
    Worker.findPath(0,0);
    //Worker.printEngine();


    return a.exec();
}
