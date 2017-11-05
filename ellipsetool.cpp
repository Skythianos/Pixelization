#include "ellipsetool.h"

#include <iostream>

EllipseTool::EllipseTool(QObject *parent) :
    PaintTool(parent)
{

}

EllipseTool::~EllipseTool()
{

}

void EllipseTool::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    startPoint = event->scenePos();
}

void EllipseTool::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    endPoint = event->scenePos();
}

void EllipseTool::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    endPoint = event->scenePos();
    if(startPoint!=endPoint)
        drawPixelEllipse();
}

void EllipseTool::drawPixelEllipse()
{
    //drawFillableEllipse();
    drawAccurateEllipse();
}

void EllipseTool::drawAccurateEllipse()
{
    float centerX = (endPoint.x()+startPoint.x())/2.0;
    float centerY = (endPoint.y()+startPoint.y())/2.0;
    float a = fabs(endPoint.x()-startPoint.x())/2.0;
    float b = fabs(endPoint.y()-startPoint.y())/2.0;

    QRect bottom = controller->nearestPixelRect(centerX, centerY + b);
    QRect top = controller->nearestPixelRect(centerX, centerY - b);
    QRect left = controller->nearestPixelRect(centerX - a, centerY);
    QRect right = controller->nearestPixelRect(centerX + a, centerY);

    float ellipseLeftBound = left.center().x();
    float ellipseRightBound = right.center().x();
    float ellipseTopBound = top.center().y();
    float ellipseBottomBound =  bottom.center().y();

    float ellipseCenterX = (ellipseLeftBound + ellipseRightBound)/2.0;
    float ellipseCenterY = (ellipseTopBound + ellipseBottomBound)/2.0;
    float ellipseA = fabs(ellipseLeftBound - ellipseRightBound)/2.0;
    float ellipseB = fabs(ellipseTopBound - ellipseBottomBound)/2.0;

    float precision = M_PI * 2.0 / 360;

    for(float i = 0; i<M_PI*2; i+=precision)
    {
        float x,y;
        x = ellipseCenterX + ellipseA * cosf(i);
        y = ellipseCenterY + ellipseB * sinf(i);

        int index = controller->containsPoint(x,y);
        if(index != -1)
            controller->setColorofPixel(index);
    }
}

void EllipseTool::drawFillableEllipse()
{
    QRect startPixel = controller->nearestPixelRect(startPoint.x(), startPoint.y());
    QRect endPixel = controller->nearestPixelRect(endPoint.x(), endPoint.y());
    
    float centerX = (endPixel.x()+startPixel.x())/2.0;
    float centerY = (endPixel.y()+startPixel.y())/2.0;
    float a = abs(endPixel.x()-startPixel.x())/2.0;
    float b = abs(endPixel.y()-startPixel.y())/2.0;

    QTextStream(stdout) << "Data: Center- " << centerX << " , " << centerY << "Radius a: "<< a <<" b: "<< b << endl;

    QRect bottom = controller->nearestPixelRect(centerX, centerY + b);
    QRect top = controller->nearestPixelRect(centerX, centerY - b);
    QRect left = controller->nearestPixelRect(centerX - a, centerY);
    QRect right = controller->nearestPixelRect(centerX + a, centerY);

    int bottomIndex = controller->containsPoint(bottom.x(),bottom.y());
    int topIndex = controller->containsPoint(top.x(),top.y());
    int leftIndex = controller->containsPoint(left.x(),left.y());
    int rightIndex = controller->containsPoint(right.x(),right.y());

    QTextStream(stdout) << "Calculated indexes: top-" << topIndex << " bottom-"<<bottomIndex << " left-"<<leftIndex << " right-"<<rightIndex  << endl;

    int ellipseA = abs(rightIndex - leftIndex)/2;
    int ellipseB = abs(topIndex - bottomIndex) / (controller->originalnumberofcolumns() * 2);
    int startIndex = topIndex - ellipseA;

    float precision = M_PI * 2.0 / 360;

    for(float i = 0; i<M_PI*2; i+=precision)
    {
        int x,y;
        x = ellipseA + ellipseA * cosf(i);
        y = ellipseB + ellipseB * sinf(i);

        int pixelIndex = startIndex + x + y*(controller->originalnumberofcolumns());
        //centerindex = startIndex + ellipseA + ellipseB*oszlopszám

        QTextStream(stdout) << "Drawing at index: "<< pixelIndex << endl;

        int index = pixelIndex;//controller->containsPoint(x,y);
        if(index != -1)
            controller->setColorofPixel(index);
    }
}
