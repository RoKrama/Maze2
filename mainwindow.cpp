#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Labirint");
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setmazegraph(Maze &mymaze)
{
    int y = mymaze.getx();
    int x = mymaze.gety();



    image = QImage((x*resolution+wallsize), (y*resolution+wallsize), QImage::Format_RGB16);
    for(int i = 0; i<x*resolution+wallsize; i++)
        for(int j = 0; j<y*resolution+wallsize; j++)
            image.setPixel(i,j,QColor("black").rgb());

    for(int i = wallsize; i<resolution; i++)
        for(int j = 0; j<wallsize; j++)
            image.setPixel(i,j,QColor("white").rgb());

    for(int i = 0; i<x; i++)
        for(int j = 0; j<y; j++)
            setpixcell(mymaze, i, j);
    qprintcell(mymaze);
    mazegraph->setGeometry(resolution, resolution, (x*resolution+wallsize), (y*resolution+wallsize));
    mazegraph->setPixmap(QPixmap::fromImage(image));

}
void MainWindow::setpixcell(Maze &mymaze, int &x, int &y)
{
        for (int i = 0; i<rslmwll; i++)
            for (int j = 0; j<rslmwll; j++)
                image.setPixel(x*resolution+i+wallsize, y*resolution+j+wallsize, QColor("white").rgb());

        if(mymaze.getcells()[y][x].getWallleft() == false)
            for (int i = rslmwll; i<resolution; i++)
                for (int j = 0; j<rslmwll; j++)
                    image.setPixel(x*resolution+i+wallsize, y*resolution+j+wallsize, QColor("white").rgb());

        if(mymaze.getcells()[y][x].getWalldown() == false)
            for (int i = 0; i<rslmwll; i++)
                for (int j = rslmwll; j<resolution; j++)
                    image.setPixel(x*resolution+i+wallsize, y*resolution+j+wallsize, QColor("white").rgb());

        return;
}

void MainWindow::qprintcell(Maze &mymaze)
{
    mymaze.getPositionLog(0,0);
    int times = 0;
    do
    {
        for (int i = 0; i<rslmwll; i++)
            for (int j = 0; j<rslmwll; j++)
            {
                 image.setPixel(mymaze.getPositionLog(0,0)->iteratePrev(times)->getPosition()[1]*resolution+i+wallsize,
                                mymaze.getPositionLog(0,0)->iteratePrev(times)->getPosition()[0]*resolution+j+wallsize,
                                QColor("red").rgb());
            }
        times++;
    }while(!(mymaze.getPositionLog(0,0)->iteratePrev(times -1)->getPosition()[1] == 0 &&
             mymaze.getPositionLog(0,0)->iteratePrev(times -1)->getPosition()[0] == 0));
}
