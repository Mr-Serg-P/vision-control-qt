#include "backend.h"

#include <QObject>

#include "opencv2/core.hpp"

#include "camera/ocv_camera/ocvcamera.h"
#include "faces_detector/ocv_ocl_faces_detector/ocvoclfacesdetector.h"
#include "faces_detector/hog_facedetector/hogfacesdetector.h"
#include "landmarks_detector/ocv_facial_landmarks_detector/ocvfaciallandmarksdetector.h"
#include "landmarks_detector/dlib_facial_landmarks_detector/dlibfaciallandmarksdetector.h"
#include "events_handler/default_events_handler/defaulteventshandler.h"
#include "events_handler/dlib_events_handler/dlibeventshandler.h"


using namespace camera;
using namespace faces_detector;
using namespace landmarks_detector;
using namespace events_handling;

Backend::Backend()
{
  cv::setUseOptimized(true);

  camera.reset(new OCVCamera());
//  facesDetector.reset(new OcvOclFacesDetector());
  facesDetector.reset(new HogFacesDetector());
//  landmarksDetector.reset(new OcvFacialLandmarksDetector());
  landmarksDetector.reset(new DlibFacialLandmarksDetector());
  eventsHandler.reset(new DefaultEventsHandler());
//  eventsHandler.reset(new DlibEventsHandler());
}

Backend::~Backend()
{

}

Camera* Backend::getCamera()
{
    return camera.get();
}

FacesDetector* Backend::getDetector()
{
    return facesDetector.get();
}

FacialLandmarksDetector* Backend::getLandmarksDetector()
{
    return landmarksDetector.get();
}

EventsHandler* Backend::getEventsHandler()
{
  return eventsHandler.get();
}

void Backend::setFacesDetector(FacesDetector *detector)
{
  facesDetector.reset(detector);
}
