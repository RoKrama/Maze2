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
    int resolution =14;
    int wallsize = 2;
    int resminwall = resolution - wallsize;

    QImage image((x*resolution+wallsize), (y*resolution+wallsize), QImage::Format_Mono);

    for(int i = 0; i<x*resolution+wallsize; i++)
        for(int j = 0; j<y*resolution+wallsize; j++)
            image.setPixel(i,j,0);

    for(int i = wallsize; i<resolution; i++)
        for(int j = 0; j<wallsize; j++)
            image.setPixel(i,j,1);

    for(int i = 0; i<x; i++)
        for(int j = 0; j<y; j++)
            setpixcell(mymaze, i, j, image, resolution, resminwall, wallsize);

    mazegraph->setGeometry(resolution, resolution, (x*resolution+wallsize), (y*resolution+wallsize));
    mazegraph->setPixmap(QPixmap::fromImage(image));

}
void MainWindow::setpixcell(Maze &mymaze, int &x, int &y, QImage &image, int &rsl, int &rslmwll, int &wllsz)
{
        for (int i = 0; i<rslmwll; i++)
            for (int j = 0; j<rslmwll; j++)
                image.setPixel(x*rsl+i+wllsz, y*rsl+j+wllsz, 1);

        if(mymaze.getcells()[y][x].wallleft == false)
            for (int i = rslmwll; i<rsl; i++)
                for (int j = 0; j<rslmwll; j++)
                    image.setPixel(x*rsl+i+wllsz, y*rsl+j+wllsz, 1);

        if(mymaze.getcells()[y][x].walldown == false)
            for (int i = 0; i<rslmwll; i++)
                for (int j = rslmwll; j<rsl; j++)
                    image.setPixel(x*rsl+i+wllsz, y*rsl+j+wllsz, 1);

        return;
}
