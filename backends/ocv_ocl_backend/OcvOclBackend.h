//
// Created by Serg on 31.05.2019.
//

#ifndef OCVOCLBACKEND_H
#define OCVOCLBACKEND_H

#include "../Backend.h"

#include "../../camera/Camera.h"
#include "../../camera/ocv_camera/OCVCamera.h"
#include "../../detector/Detector.h"
#include "../../detector/ocv_detector/OcvOclHaarDetector.h"
#include "../../detector/ocv_detector/OcvOclLandmarksDetector.h"
#include "../../events_handling/EventsHandler.h"


class OcvOclBackend : public Backend {
private:
    camera::Camera* camera;
    detector::Detector* detector;
    detector::LandmarksDetector* landmarksDetector;
    events_handling::EventsHandler* eventsHandler;

public:
    OcvOclBackend();

    ~OcvOclBackend();

    camera::Camera* getCamera() override;
    detector::Detector* getDetector() override;
    LandmarksDetector *getLandmarksDetector() override;
    events_handling::EventsHandler *getEventsHandler() override;

};

#include "OcvOclBackend.cpp"

#endif
