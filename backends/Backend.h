//
// Created by Serg on 31.05.2019.
//

#ifndef VISION_CONTROL_BACKEND_H
#define VISION_CONTROL_BACKEND_H

#include "../camera/Camera.h"
#include "../detector/Detector.h"
#include "../detector/LandmarksDetector.h"
#include "../events_handling/EventsHandler.h"


class Backend {
public:
    virtual camera::Camera* getCamera() = 0;
    virtual detector::Detector* getDetector() = 0;
    virtual detector::LandmarksDetector* getLandmarksDetector() = 0;
    virtual events_handling::EventsHandler* getEventsHandler() = 0;
};


#endif //VISION_CONTROL_BACKEND_H
