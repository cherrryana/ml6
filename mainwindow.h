#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

class Rect;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    QVector <Rect *> rects;
    QVector <Rect *> colored;
    bool firstPoint = true;
    Rect *r = nullptr;
    int color = 0;

};
#endif // MAINWINDOW_H
