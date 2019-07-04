#include "workingthread.h"

#include <bits/stl_vector.h>

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/face.hpp"

#include "mainwindow.h"
#include "faces_detector/hog_facedetector/hogfacesdetector.h"
#include "faces_detector/ocv_ocl_faces_detector/ocvoclfacesdetector.h"


using namespace cv;
using namespace std;
using namespace Ui;

WorkingThread::WorkingThread()
{
  imgWidth = 320;
  imgHeight = 240;
  isWorking = true;
}

void WorkingThread::run()
{
  Mat img, frame;

  backend.getCamera()->initialize();
  backend.getCamera()->start();

  double fps= 0;
  while (isWorking)
  {
    double t = cv::getTickCount();

    backend.getCamera()->snapshot(frame);

    GaussianBlur(frame, img, cv::Size(0, 0), 3);
    addWeighted(frame, 1.5, img, -0.5, 0, img);
    resize(img, img, Size(imgWidth, imgHeight));
    auto faces = backend.getDetector()->detect(img);

    if (!faces.empty())
    {
      auto landmarks = backend.getLandmarksDetector()->detectLandmarks(img, faces);

      if (backend.getEventsHandler()->getControlRect() != nullptr && backend.getEventsHandler()->getAnchorPoint() != nullptr)
        backend.getEventsHandler()->generateEvents(landmarks.at(0), faces.at(0));

      for (auto face : faces)
        rectangle(img, face, Scalar(255, 100, 0));
      face::drawFacemarks(img, landmarks.at(0), Scalar(12, 100, 1));
    }

    if (backend.getEventsHandler()->getControlRect() != nullptr)
      rectangle(img, *(backend.getEventsHandler()->getControlRect()), Scalar(0, 0, 255));
    if (backend.getEventsHandler()->getAnchorPoint() != nullptr)
      drawMarker(img, *(backend.getEventsHandler()->getAnchorPoint()), Scalar(0, 0, 255), cv::MARKER_TILTED_CROSS);

    fps = 1 * getTickFrequency() / (getTickCount() - t);
    this->snapshotChanged(img, fps);
    }
}

void WorkingThread::setDetectionMethod(int methodCode)
{
  if (methodCode == Ui::detectionMethods::hog)
      backend.setFacesDetector(new faces_detector::HogFacesDetector());
  else if (methodCode == Ui::detectionMethods::haar)
    backend.setFacesDetector(new faces_detector::OcvOclFacesDetector());
}

void WorkingThread::setSensitivityX(int sensitivity)
{
  backend.getEventsHandler()->setSensitivityX(sensitivity * 1.f);
}

void WorkingThread::setSensitivityY(int sensitivity)
{
  backend.getEventsHandler()->setSensitivityY(sensitivity * 1.f);
}

float WorkingThread::getSensitivityX()
{
  return backend.getEventsHandler()->getSensitivityX();
}

float WorkingThread::getSensitivityY()
{
  return backend.getEventsHandler()->getSensitivityY();
}

void WorkingThread::finalize()
{
  isWorking = false;
}

void WorkingThread::setImgResolution(int width, int height)
{
//  this->exit(0);
  this->imgWidth = width;
  this->imgHeight = height;
//  this->start();
}

void WorkingThread::updateControlRegion()
{
  Mat img;
  backend.getCamera()->snapshot(img);
  resize(img, img, Size(imgWidth, imgHeight));

  auto face = backend.getDetector()->detect(img);

  if (face.empty())
    return;

  auto points = backend.getLandmarksDetector()->detectLandmarks(img, face);

  backend.getEventsHandler()->freeze(points.at(0).at(30), face.at(0));
}
