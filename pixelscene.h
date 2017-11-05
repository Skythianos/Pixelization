#ifndef PIXELSCENE_H
#define PIXELSCENE_H

#include <QtCore>
#include <QtGui>
#include "pixel.h"
#include "window.h"
#include "painttool.h"

class PaintTool;

class PixelScene : public QGraphicsScene
{

public:
    PixelScene(QObject * parent = 0);
    ~PixelScene();

    
    int originalnumberofcolumns();
    int originalnumberofrows();
    
    int numberofPixels();

    
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);

    
    void updatePixel(int index, bool clear, QColor color);

    
    QList<int> windowIndexes(int index);

    
    QColor getColorofPixel(int index);

    
    void setWindowToggled(bool checked);
    bool getWindowToggled();

    
    int getPixelSize();
    
    int getWidth();
    int getOnlyPixelsWidth();
    
    int getHeight();
    int getOnlyPixelsHeight();

    
    void setActivePaintTool(PaintTool* tool);

    
    int pixelUnderMouse();
    int containsPoint(float x, float y);
    
    int nearestPixel(float x, float y);
    QRect nearestPixelRect(float x, float y);
    
    QRect getPixelRect(int index);    

    
    void setoriginalnumberofcolumns();
    void setoriginalnumberofrows();

private:

    
    int pixelSize = 3;
    
    int gapWidth = 5, gapHeight = 15;
    
    int windowWidth = 3, windowHeight = 3;
    
    int windowXNumber = 16, windowYNumber = 13;
    
    int width, height, onlypixelswidth, onlypixelsheight;

    
    bool windowToggled = false;
    
    PaintTool *activePaintTool;

    
    QList<Pixel*> pixels;
    QList<Window*> windows;
};

#endif // PIXELSCENE_H
