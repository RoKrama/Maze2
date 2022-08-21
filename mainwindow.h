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
    void setmazegraph(Maze &mymaze);
    void setpixcell(Maze &mymaze, int &x, int &y, QImage &image, int &rsl, int &rslmwll, int &wllsz);
    QLabel *mazegraph = new QLabel(this);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
