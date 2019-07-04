#include <windows.h>

#include <iostream>
#include <vector>

#include "events_handler/default_events_handler/defaulteventshandler.h"
//#include "faces_detector/hog_facedetector/hogfacesdetector.h"
#include "faces_detector/ocv_ocl_faces_detector/ocvoclfacesdetector.h"
//#include "landmarks_detector/dlib_facial_landmarks_detector/dlibfaciallandmarksdetector.h"
#include "landmarks_detector/ocv_facial_landmarks_detector/ocvfaciallandmarksdetector.h"

#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"

#include "gtest/gtest.h"


using namespace cv;
using namespace std;

//  DefaultEventsHandler
TEST(test_defaulteventshandler, test_freeze)
{
  events_handling::DefaultEventsHandler handler;
  Point2f point;
  Rect2f rect;
  handler.freeze(point, rect);

  ASSERT_NE(handler.getAnchorPoint(), nullptr);
  ASSERT_NE(handler.getControlRect(), nullptr);
}

TEST(test_defaulteventshandler, test_generate_events)
{
  events_handling::DefaultEventsHandler handler;

  Point2f point(5, 7);
  Rect2f rect(0, 0, 10, 15);
  handler.freeze(point, rect);

  vector<Point2f> landmarks(68);
  for (size_t i = 0; i < 68; i++)
    landmarks.push_back(Point(0.f, 0.f));

  landmarks.at(43).y = 15.f;
  landmarks.at(44).y = 15.f;
  landmarks.at(45).x = 10.f;

  SetCursorPos(10000, 10000);
  POINT cursorPos;
  GetCursorPos(&cursorPos);

  handler.generateEvents(landmarks, Rect(0, 0, 20, 20));

  POINT cursorPosAfter;
  GetCursorPos(&cursorPosAfter);

  ASSERT_NE(cursorPos.x, cursorPosAfter.x);
  ASSERT_NE(cursorPos.y, cursorPosAfter.y);
}

//  OcvOclFaceDetector
TEST(test_ocvoclfacesdetector, test_detect)
{
  faces_detector::OcvOclFacesDetector faceDetector;

  auto img = imread("data/lena.jpg", IMREAD_COLOR);

  auto detections = faceDetector.detect(img);

  ASSERT_NE(&detections, nullptr);
}

//  OcvFacialLandmarksDetector
TEST(test_ocvfaciallandmarksdetector, test_detectLandmarks)
{
  faces_detector::OcvOclFacesDetector faceDetector;
  landmarks_detector::OcvFacialLandmarksDetector landmarksDetector;

  auto img = imread("data/lena.jpg", IMREAD_COLOR);

  auto detections = faceDetector.detect(img);
  auto landmarksDetections = landmarksDetector.detectLandmarks(img, detections);

  ASSERT_NE(&detections, nullptr);
  ASSERT_NE(&landmarksDetections, nullptr);
}


int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
