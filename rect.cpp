#include "rect.h"
#include <QPainter>

int maxX = 0;
int maxY = 0;
int minX = 0;
int minY = 0;
int k = 0;

Rect::Rect(int x1, int y1, int x2, int y2, int color)
    : x1(x1), y1(y1), x2(x2), y2(y2), color(color)
{

}

int Rect::getX1() const
{
    return x1;
}

void Rect::setX1(int value)
{
    x1 = value;
}

int Rect::getY1() const
{
    return y1;
}

void Rect::setY1(int value)
{
    y1 = value;
}

int Rect::getX2() const
{
    return x2;
}

void Rect::setX2(int value)
{
    x2 = value;
}

int Rect::getY2() const
{
    return y2;
}

void Rect::setY2(int value)
{
    y2 = value;
}

int Rect::getMaxX() const
{
    return maxX;
}

int Rect::getMaxY() const
{
    return maxY;
}

int Rect::getMinX() const
{
    return minX;
}

int Rect::getMinY() const
{
    return minY;
}

int Rect::minimum(int a, int b)
{
    return (a > b) ? b : a;
}

int Rect::maximum(int a, int b)
{
    return (a > b) ? a : b;
}


void Rect::draw(QPainter *painter)
{

    painter -> drawLine(x1, y1, x1, y2);
    painter -> drawLine(x1, y1, x2, y1);
    painter -> drawLine(x2, y1, x2, y2);
    painter -> drawLine(x1, y2, x2, y2);

}

void Rect::fillcolor(QPainter *painter)
{
    if (color == 2)
    {
    painter -> setBrush(QBrush(Qt::red));
    painter -> drawRect(QRect(x2, y2, x1 - x2, y1 - y2));
    }
    if (color == 3)
    {
    painter -> setBrush(QBrush(Qt::yellow));
    painter -> drawRect(QRect(x2, y2, x1 - x2, y1 - y2));
    }
    if (color == 4)
    {
    painter -> setBrush(QBrush(Qt::green));
    painter -> drawRect(QRect(x2, y2, x1 - x2, y1 - y2));
    }
    if (color == 5)
    {
    painter -> setBrush(QBrush(Qt::blue));
    painter -> drawRect(QRect(x2, y2, x1 - x2, y1 - y2));
    }
    if (color >= 6)
    {
    painter -> setBrush(QBrush(Qt::black));
    painter -> drawRect(QRect(x2, y2, x1 - x2, y1 - y2));
    }

    k = 0;
}

bool Rect::contains(int a, int b)
{
    return ((a >= minimum(x1, x2)) && (a <= maximum(x1, x2)) && (b >= minimum(y1, y2)) && (b <= maximum(y1, y2))) ? true : false;
}

void Rect::colour()
{

    if ((minimum(y1, y2) > minY) || k == 0) minY = minimum(y1, y2);
    if ((minimum(x1, x2) > minX) || k == 0) minX = minimum(x1, x2);

    if ((maximum(y1, y2) < maxY) || k == 0) maxY = maximum(y1, y2);
    if ((maximum(x1, x2) < maxX) || k == 0) maxX = maximum(x1, x2);

    k++;
}
