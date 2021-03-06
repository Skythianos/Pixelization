#ifndef CANVAS_H
#define CANVAS_H

#include <QtGui>
#include <QtCore>
#include "layer.h"

class Canvas
{
public:
    Canvas(int r, int c);
    Canvas(Canvas *c, int r, int col);
    ~Canvas();

    void setLayerName(QString s);
    void setLayerName(int layerindex, QString name);
    QString getLayerName();
    QString getLayerName(int index);

    void setLayerTransparency(bool t);
    void setLayerTransparency(int layerindex, bool t);

    void setActiveLayer(int index);

    void setColorofPixel(int index, QColor color);
    QColor getColorofPixel(int index);
    QColor getColorofPixel(int layerindex, int pixelindex);
    bool isPixelClear(int index);
    bool isPixelClear(int layerindex, int pixelindex);
    void clearPixel(int index);
    void clearLayer();

    void moveLayerUp();
    void moveLayerDown();
    void moveLayerLeft();
    void moveLayerRight();

    void moveFrameUp();
    void moveFrameDown();
    void moveFrameLeft();
    void moveFrameRight();

    void updateCombined();
    void updateCombinedLayer(int index);

    int numberofLayers();
    bool getTransparency(int index);

    int getnumberofcolumns(int index);
    int getnumberofrows(int index);

    void addLayer();
    void addLayer(int index);
    void removeActiveLayer();
    void switchLayers(int i, int j);

    Layer *getLayer(int index);
    int getActive();

    void initialize();
    void initializeLayer();

    void clearAll();
    void setNumberofrows(int layerindex, int number);
    void setNumberofcolumns(int layerindex, int number);

    void addLayerPixels(int layerindex, QString data);

    void setDefaultActives();

    int getLayerSize();

private:
    int originalnumberofcolumns, originalnumberofrows;

    QList<Layer*> layers;
    Layer* activeLayer;

    Layer* combinedLayer;
};

#endif // CANVAS_H
