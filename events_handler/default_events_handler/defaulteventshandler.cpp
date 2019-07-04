#include "defaulteventshandler.h"

#ifdef WIN32
  #include "../../os/oswindows.h"
#endif

//#ifdef DEBUG
  #include <iostream>
//#endif
#include <vector>
#include <bits/unique_ptr.h>

#include <QObject>

#include "opencv2/core.hpp"

#include "../../os/os.h"


using namespace std;
using namespace cv;
using namespace os;
using namespace events_handling;


DefaultEventsHandler::DefaultEventsHandler()
{
  sensitivityX = 1.f;
  sensitivityY = 1.f;

  osWrapper.reset(new OSWindows());
  auto screen = osWrapper->getScreenSize();

  screenSize = Rect2f(0, 0, screen.width * 1.f, screen.height * 1.f);
}

DefaultEventsHandler::~DefaultEventsHandler()
{

}

void DefaultEventsHandler::generateEvents(const vector<Point2f>& landmarks, const cv::Rect& faceRegion)
{
  if (anchorPoint.get() == nullptr || controlRegion == nullptr)
      return;
  cout << screenSize.width << " " << screenSize.height << endl;
  cout << controlRegion->width << " " << controlRegion->height << endl;
  float screenPerFacePixelsWidth = screenSize.width * 1.f / controlRegion->width;
  float screenPerFacePixelsHeight = screenSize.height * 1.f / controlRegion->height;

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
}

void DefaultEventsHandler::freeze(const Point2f& anchorPoint, const Rect2f& controlRect)
{
  this->anchorPoint.reset(new Point2f(anchorPoint));
  this->controlRegion.reset(new Rect2f(controlRect));
}

const Point2f* DefaultEventsHandler::getAnchorPoint()
{
  return anchorPoint.get();
}

const Rect2f* DefaultEventsHandler::getControlRect()
{
  return controlRegion.get();
}

void DefaultEventsHandler::setSensitivityX(float sensitivity)
{
  sensitivityX = sensitivity * 0.01f;
}

void DefaultEventsHandler::setSensitivityY(float sensitivity)
{
  sensitivityY = sensitivity * 0.01f;
}

float DefaultEventsHandler::getSensitivityX()
{
  return sensitivityX;
}

float DefaultEventsHandler::getSensitivityY()
{
  return sensitivityY;
}

float DefaultEventsHandler::euclideanDistance(const Point2f& point0, const Point2f& point1) {
    Point2f distance = point0 - point1;
    float result = cv::sqrt(distance.x * distance.x + distance.y * distance.y);
    return result;
}

inline bool DefaultEventsHandler::isEyeClosed(float EAR) {
    return EAR < EYE_WINK_AR - EYE_ACTION_DELTA;
}

inline bool DefaultEventsHandler::isEyeWink(float EAR) {
    return EAR < EYE_WINK_AR;
}

inline bool DefaultEventsHandler::isEyeWideOpened(float EAR){
    return EAR > EYE_WIDE_OPENED_AR - EYE_ACTION_DELTA;
}

inline bool DefaultEventsHandler::isMouthOpened(float MAR)
{
  return MAR > MOUTH_OPENED_AR;
}
