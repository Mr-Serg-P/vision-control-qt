#include "OcvOclBackend.h"
#include "../../camera/Camera.h"
#include "../../camera/ocv_camera/OCVCamera.h"
#include "../../detector/Detector.h"
#include "../../detector/ocv_detector/OcvOclHaarDetector.h"
#include "../../detector/ocv_detector/OcvOclLandmarksDetector.h"
#include "../../events_handling/EventsHandler.h"
#include "../../events_handling/events_handlers/DefaultEventsHandler.h"

using namespace camera;
using namespace detector;
using namespace events_handling;

OcvOclBackend::OcvOclBackend() {
    camera = new OCVCamera();
    camera->initialize();

    detector = new OcvOclHaarDetector();
    landmarksDetector = new OcvOclLandmarksDetector();
    eventsHandler = new DefaultEventsHandler();
}

OcvOclBackend::~OcvOclBackend() {
    delete this->camera;
    delete this->detector;
    delete this->landmarksDetector;
    delete this->eventsHandler;
}


Camera* OcvOclBackend::getCamera() {
    return camera;
}

Detector* OcvOclBackend::getDetector() {
    return detector;
}

LandmarksDetector* OcvOclBackend::getLandmarksDetector() {
    return landmarksDetector;
}

EventsHandler* OcvOclBackend::getEventsHandler() {
    return eventsHandler;
}
