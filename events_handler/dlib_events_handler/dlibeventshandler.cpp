#include "dlibeventshandler.h"

#ifdef WIN32
  #include "../../os/oswindows.h"
#endif

//#ifdef DEBUG
  #include <iostream>
//#endif
#include <vector>
#include <bits/unique_ptr.h>

#include "opencv2/core.hpp"

#include "../../os/os.h"


using namespace std;
using namespace cv;
using namespace os;
using namespace events_handling;

DlibEventsHandler::DlibEventsHandler()
{
  //    screenCenter = Point2f(screenSize.width / 2.f, screenSize.height / 2.f);
  anchorPoint = unique_ptr<Point2f>(nullptr);
  controlRegion = unique_ptr<Rect2f>(nullptr);
#ifdef WIN32
  osWrapper = unique_ptr<OS>(new OSWindows());
#endif

  screenSize = osWrapper->getScreenSize();
}

DlibEventsHandler::~DlibEventsHandler()
{

}

void DlibEventsHandler::generateEvents(const vector<Point2f>& landmarks, const cv::Rect& faceRegion)
{
  if (anchorPoint.get() == nullptr || controlRegion == nullptr)
      return;

  float screenPerFacePixelsWidth = screenSize.width / controlRegion->width;
  float screenPerFacePixelsHeight = screenSize.height / controlRegion->height;

  Point cursorPos = Point();
  cursorPos.x = screenSize.width * (1 - (landmarks.at(30).x - controlRegion->x) / controlRegion->width);
  cursorPos.y = screenSize.height - screenSize.height * (1 - (landmarks.at(30).y - controlRegion->y * 1.f) / controlRegion->height);

  SetCursorPos(cursorPos.x, cursorPos.y);

  float rightEyeAR = (euclideanDistance(landmarks.at(RIGHT_EYE_TOP_RIGHT), landmarks.at(RIGHT_EYE_BOTTOM_RIGHT)) + euclideanDistance(landmarks.at(RIGHT_EYE_TOP_LEFT), landmarks.at(RIGHT_EYE_BOTTOM_LEFT))) / (2.f * euclideanDistance(landmarks.at(RIGHT_EYE_RIGHT), landmarks.at(RIGHT_EYE_LEFT)));
  float leftEyeAR = (euclideanDistance(landmarks.at(LEFT_EYE_TOP_RIGHT), landmarks.at(LEFT_EYE_BOTTOM_RIGHT)) + euclideanDistance(landmarks.at(LEFT_EYE_TOP_LEFT), landmarks.at(LEFT_EYE_BOTTOM_LEFT))) / (2.f * euclideanDistance(landmarks.at(LEFT_EYE_RIGHT), landmarks.at(LEFT_EYE_LEFT)));
  float mouthAR = (
          euclideanDistance(landmarks.at(MOUTH_TOP_RIGHT), landmarks.at(MOUTH_BOTTOM_RIGHT)) +
          euclideanDistance(landmarks.at(MOUTH_TOP_MID), landmarks.at(MOUTH_BOTTOM_MID)) +
          euclideanDistance(landmarks.at(MOUTH_TOP_LEFT), landmarks.at(MOUTH_BOTTOM_LEFT))) /
          (2 * (euclideanDistance(landmarks.at(MOUTH_RIGHT), landmarks.at(MOUTH_LEFT))));

  bool leftEyeIsClosed = isEyeWink(leftEyeAR);
  bool rightEyeIsClosed = isEyeWink(rightEyeAR);

  cout << rightEyeAR << '\t' << leftEyeAR <<endl;
  if (isMouthOpened(mouthAR))
  {
    controlRegion.reset();
    anchorPoint.reset();
  }

  if (leftEyeIsClosed && rightEyeIsClosed)
  {
#ifdef DEBUG
    cout << "BLINK" << endl;
#endif
    return;
  }

  if (leftEyeIsClosed)
  {
#ifdef DEBUG
    cout << "LEFT EYE CLOSED" << endl;
#endif
    osWrapper->mouseLBDown();
  }

  if (rightEyeIsClosed)
  {
#ifdef DEBUG
    cout << "RIGHT EYE CLOSED" << endl;
#endif
    osWrapper->mouseRBDown();
  }

//  if (leftEyeIsClosed)
//  {
//#ifdef DEBUG
//    cout << "LEFT EYE WINK" << endl;
//#endif
//    leftEyeWasClosed = leftEyeIsClosed;
//    osWrapper->mouseLBDown();
//  }
//  else
//  {
//      if (!leftEyeWasClosed)
//        return;

//      leftEyeWasClosed = false;
//      osWrapper->mouseRBUp();
//  }

//  if (rightEyeIsClosed)
//  {
//#ifdef DEBUG
//    cout << "RIGHT EYE WINK" << endl;
//#endif
//    rightEyeWasClosed = rightEyeIsClosed;
//    osWrapper->mouseRBDown();
//  }
//  else
//  {
//      if (!rightEyeWasClosed)
//        return;

//      rightEyeWasClosed = false;
//      osWrapper->mouseRBUp();
//  }


}

void DlibEventsHandler::freeze(const Point2f& anchorPoint, const Rect2f& controlRect)
{
//  Rect2f threshold = Rect2f(controlRect);
//  controlRegion.height = controlRegion
//  threshold.height = threshold.height * 1.05f;
  this->anchorPoint.reset(new Point2f(anchorPoint));
  this->controlRegion.reset(new Rect2f(controlRect));
}

const Point2f* DlibEventsHandler::getAnchorPoint()
{
  return anchorPoint.get();
}

const Rect2f* DlibEventsHandler::getControlRect()
{
  return controlRegion.get();
}

void DlibEventsHandler::setSensitivityX(float sensitivity)
{

}

void DlibEventsHandler::setSensitivityY(float sensitivity)
{

}

float DlibEventsHandler::getSensitivityX()
{
  return 0.f;
}

float DlibEventsHandler::getSensitivityY()
{
  return 0.f;
}

float DlibEventsHandler::euclideanDistance(const Point2f& point0, const Point2f& point1) {
    Point2f distance = point0 - point1;
    float result = cv::sqrt(distance.x * distance.x + distance.y * distance.y);
    return result;
}

inline bool DlibEventsHandler::isEyeClosed(float EAR) {
    return EAR < EYE_WINK_AR - EYE_ACTION_DELTA;
}

inline bool DlibEventsHandler::isEyeWink(float EAR) {
    return EAR < EYE_WINK_AR/* + EYE_ACTION_DELTA && EAR > EYE_WINK_AR - EYE_ACTION_DELTA*/;
}

inline bool DlibEventsHandler::isEyeWideOpened(float EAR){
    return EAR > EYE_WIDE_OPENED_AR - EYE_ACTION_DELTA;
}

inline bool DlibEventsHandler::isMouthOpened(float MAR)
{
  return MAR > MOUTH_OPENED_AR;
}
