#ifndef RECT_H
#define RECT_H
#include <QVector>

extern int minX;
extern int minY;
extern int maxX;
extern int maxY;
extern int k;

class QPainter;
class Rect
{
public:
    Rect();
    Rect(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, int color = 0);

    int getX1() const;
    void setX1(int value);

    int getY1() const;
    void setY1(int value);

    int getX2() const;
    void setX2(int value);

    int getY2() const;
    void setY2(int value);

    int getMaxX() const;
    int getMaxY() const;
    int getMinX() const;
    int getMinY() const;

    int minimum(int a, int b);
    int maximum(int a, int b);

    void draw(QPainter *painter);
    void fillcolor(QPainter *painter);
    bool contains(int x, int y);
    void colour();


private:
    int x1, y1, x2, y2, color;
};

#endif // RECT_H
