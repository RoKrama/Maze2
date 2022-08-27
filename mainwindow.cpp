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
                setpixcell(mymaze, i, j, QColor("white").rgb(), QColor("white").rgb());

    qprintcell(mymaze);

    mazegraph->setGeometry(resolution, resolution, (x*resolution+wallsize), (y*resolution+wallsize));
    mazegraph->setPixmap(QPixmap::fromImage(image));

}
void MainWindow::setpixcell(Maze &mymaze, int &x, int &y, QRgb colrin, QRgb colrwall)
{
    for (int i = 0; i<rslmwll; i++)
        for (int j = 0; j<rslmwll; j++)
            image.setPixel(x*resolution+i+wallsize,
                           y*resolution+j+wallsize, QColor(colrwall).rgb());

    if(mymaze.getcells()[y][x].getWallleft() == false)
        for (int i = rslmwll; i<resolution; i++)
            for (int j = 0; j<rslmwll; j++)
                image.setPixel(x*resolution+i+wallsize,
                               y*resolution+j+wallsize, QColor(colrin).rgb());

    if(mymaze.getcells()[y][x].getWalldown() == false)
        for (int i = 0; i<rslmwll; i++)
            for (int j = rslmwll; j<resolution; j++)
                image.setPixel(x*resolution+i+wallsize,
                               y*resolution+j+wallsize, QColor(colrin).rgb());

    return;
}

void MainWindow::qprintcell(Maze &mymaze)
{
    Memo* Iterator = mymaze.getPositionLog(0,0);

    while(true)
    {
         setpixcell(mymaze, Iterator->getPosition()[1], Iterator->getPosition()[0],
                 QColor("pink").rgb(), QColor("pink").rgb()) ;

            if(!(Iterator->getPosition()[1] == 0 &&
                 Iterator->getPosition()[0] == 0))
                Iterator = mymaze.getPositionLog(Iterator);

            else return;
    }
}
