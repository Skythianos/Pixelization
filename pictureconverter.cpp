#include "pictureconverter.h"

pictureConverter::pictureConverter(PixelScene* scene)
{
    image = new QImage("./palinkaVSviz.jpg");
    int h = scene->height, w = scene->width;
    //if(h > w)

}

pictureConverter::~pictureConverter()
{
    delete image;
}

void pictureConverter::centerColor(PixelScene *scene)
{

}

