#ifndef WINDOW_H
#define WINDOW_H

#include <QtCore>
#include <QtGui>
#include <QList>
#include "pixel.h"

class Pixel;

class Window
{
public:
    //create window
    Window();
    ~Window();

    //indexes of pixels that are in the window
    QList<int> indexes;
};

#endif // WINDOW_H
