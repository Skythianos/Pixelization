#ifndef LAYERPIXEL_H
#define LAYERPIXEL_H

#include <QtGui>
#include <QtCore>

class LayerPixel
{
public:
    LayerPixel();
    LayerPixel(LayerPixel *lp);
    ~LayerPixel();

    
    bool clear = true;
    
    QColor color;
    
    int index;
};

#endif // LAYERPIXEL_H
