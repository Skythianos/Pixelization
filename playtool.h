#ifndef PLAYTOOL_H
#define PLAYTOOL_H

#include "controller.h"
#include <QTimer>

class PlayTool : public QObject
{
    Q_OBJECT

public:
    PlayTool(Controller *c);
    ~PlayTool();

    
    void play();

public slots:
    
    void updateScene();
    
    void updateSlider();

signals:
    
    void positionChanged(int position);
private:
    
    Controller *controller;
    //frame counter
    int i = 0;
    
    float timesum = 0.0;
    
    QTimer timer;
};

#endif // PLAYTOOL_H
