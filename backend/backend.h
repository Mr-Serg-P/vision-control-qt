#ifndef BACKEND_H
#define BACKEND_H

#include <bits/unique_ptr.h>

#include "../camera/camera.h"
#include "../faces_detector/facesdetector.h"
#include "../landmarks_detector/faciallandmarksdetector.h"
#include "../events_handler/eventshandler.h"


class Backend
{
public:
  Backend();

  virtual ~Backend();

  camera::Camera* getCamera();
  faces_detector::FacesDetector* getDetector();
  landmarks_detector::FacialLandmarksDetector* getLandmarksDetector();
  events_handling::EventsHandler* getEventsHandler();
  void setFacesDetector(faces_detector::FacesDetector* detector);

private:
  std::unique_ptr<camera::Camera> camera;
  std::unique_ptr<faces_detector::FacesDetector> facesDetector;
  std::unique_ptr<landmarks_detector::FacialLandmarksDetector> landmarksDetector;
  std::unique_ptr<events_handling::EventsHandler> eventsHandler;
};

#endif // BACKEND_H
