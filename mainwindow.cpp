#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rect.h"
#include <QPainter>
#include <QPoint>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if (r)
    {
        for (int k = 0; k < colored.size(); k++)
            colored[k] -> fillcolor(&painter);

        for (int i = 0; i < rects.size(); i++)
            rects[i] -> draw(&painter);
        color = 0;
    }
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event -> modifiers() & Qt::ControlModifier)
    {
        if (firstPoint)
        {
             r = new Rect(event -> x(), event -> y());
             if (r)
                 rects.append(r);
             firstPoint = false;
        }
        else
        {
            rects[rects.size() - 1] -> setX2(event -> x());
            rects[rects.size() - 1] -> setY2(event -> y());
            firstPoint = true;
            repaint(); 
        }
     }

     else
     {
        for (int i = 0; i < rects.size(); i++)
        {
            if (rects[i] -> contains(event -> x(), event -> y()))
            {
                rects[i] -> colour();
                color++;
            }
        }

        if (color > 1)
        {
            colored.append(new Rect(r -> getMaxX(), r -> getMaxY(), r -> getMinX(), r -> getMinY(), color));
            repaint();
        }
        else color = 0;
     }
}
