#ifndef LINETOOL_H
#define LINETOOL_H

#include "painttool.h"

class LineTool : public PaintTool
{
    Q_OBJECT

public:
    LineTool(QObject *parent);
    ~LineTool();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    
    void drawPixelLine();
    
    void drawAccuratePixelLine();
    
    void drawFillablePixelLine();
};

#endif // LINETOOL_H
