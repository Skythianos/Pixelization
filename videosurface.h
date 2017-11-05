#ifndef VIDEOSURFACE_H
#define VIDEOSURFACE_H

#include <QAbstractVideoSurface>
#include "controller.h"

class VideoSurface : public QAbstractVideoSurface
{
public:
    //creation of videosurface with controller and player pointer
    VideoSurface(Controller *c, QMediaPlayer *p);
    ~VideoSurface();

    
    QList<QVideoFrame::PixelFormat> supportedPixelFormats(
            QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const;

    //handles actual frame
    bool present(const QVideoFrame &frame);

    
    void reset();

private:
    
    Controller *controller;
    
    QMediaPlayer *player;

    //length of video
    float videosum = 0.0;
};

#endif // VIDEOSURFACE_H
