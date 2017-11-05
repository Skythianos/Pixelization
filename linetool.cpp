#include "linetool.h"

LineTool::LineTool(QObject *parent) :
    PaintTool(parent)
{

}

LineTool::~LineTool()
{

}

void LineTool::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    startPoint = event->scenePos();
}

void LineTool::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    endPoint = event->scenePos();
}

void LineTool::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    endPoint = event->scenePos();
    if(startPoint != endPoint)
        drawPixelLine();
}

void LineTool::drawPixelLine()
{
    //drawFillablePixelLine();
    drawAccuratePixelLine();
}

void LineTool::drawFillablePixelLine()
{
    //Getting nearest Pixels:
    QRect begin = controller->nearestPixelRect(startPoint.x(), startPoint.y());
    QRect end = controller->nearestPixelRect(endPoint.x(), endPoint.y());

    //Determination of parameters
    int startIndex = controller->containsPoint(begin.x(),begin.y());
    int endIndex = controller->containsPoint(end.x(),end.y());


    int startX = startIndex % (controller->originalnumberofcolumns());
    int startY = startIndex / (controller->originalnumberofcolumns());
    int endX = endIndex % (controller->originalnumberofcolumns());
    int endY = endIndex / (controller->originalnumberofcolumns());


    QTextStream(stdout) << "Batman: "<< startIndex<< " % "<< (controller->originalnumberofcolumns()) << " = " << startX << endl;

    
    int deltaX = (endX-startX);
    int deltaY = (endY-startY);
    float m = 0.0;
    if(deltaX != 0)
    {
        m = (deltaY + 0.0)/(deltaX - 0.0);
    }
    float length = sqrtf(deltaX*deltaX + deltaY*deltaY);


    QTextStream(stdout) << "This \"wants\" to be interesting: "<< deltaX<< " , "<< deltaY << endl;
    QTextStream(stdout) << "Start: "<< startIndex<< " ,end "<< endIndex << endl;

    
    float precision = 1.0;
    float direction = (deltaX==0) ? (deltaY/abs(deltaY)) : (deltaX/abs(deltaX));
    float distance = 0.0;

    
    while(fabs(distance) <= length)
    {

        QTextStream(stdout) << "For the king: "<< distance<< " <= "<< length << endl;
        float x, y;
        
        if(deltaX == 0)
        {
            x = startX;
            y = startY + distance;
        }
        else
        {
            
            x =startX + direction * sqrtf( distance*distance/(1 + m*m) );
            y =startY + (x - startX)*m;
        }
        QTextStream(stdout) << "    -and also: "<< x<< " ... "<< y << endl;

        int xId = x;
        int yId = y;
        
        int index = xId + yId * (controller->originalnumberofcolumns());
        if(index != -1)
            controller->setColorofPixel(index);

        
        distance +=  direction*precision;
    }


}

void LineTool::drawAccuratePixelLine()
{
    //Getting nearest Pixels:
    QRect begin = controller->nearestPixelRect(startPoint.x(), startPoint.y());
    QRect end = controller->nearestPixelRect(endPoint.x(), endPoint.y());

    //New starting and ending points
    float startX = begin.center().x();
    float startY = begin.center().y();
    float endX = end.center().x();
    float endY = end.center().y();

    //Slope
    float deltaX = (endX-startX);
    float deltaY = (endY-startY);
    float m = 0.0;
    if(deltaX != 0.0)
    {
        m = deltaY/deltaX;
    }
    float length = sqrtf(deltaX*deltaX + deltaY*deltaY);


    
    float precision = controller->getPixelSize();
    float direction = (deltaX ==0) ? (deltaY/fabs(deltaY)) :(deltaX/fabs(deltaX));
    float distance = 0.0;

    
    while(fabs(distance) <= length)
    {
        float x, y;
        
        if(deltaX == 0.0)
        {
            x  = startX;
            y = startY + distance;
        }
        else
        {
            
            x = startX + direction * sqrtf( distance*distance/(1 + m*m) );
            y = startY + (x - startX)*m;
        }

        //Drawing
        int index = controller->containsPoint(x,y);
        if(index != -1)
            controller->setColorofPixel(index);

       
        distance += direction*precision;
    }
}
