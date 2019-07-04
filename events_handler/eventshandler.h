#ifndef EVENTSHANDLER_H
#define EVENTSHANDLER_H

#include <vector>

#include "opencv2/core.hpp"


namespace events_handling
{
  class EventsHandler
  {
  public:
    virtual ~EventsHandler();

    virtual void generateEvents(const std::vector<cv::Point2f> &landmarks, const cv::Rect &faceRegion) = 0;
    virtual void freeze(const cv::Point2f& anchorPoint, const cv::Rect2f& controlRect) = 0;
    virtual const cv::Point2f* getAnchorPoint() = 0;
    virtual const cv::Rect2f* getControlRect() = 0;
    virtual void setSensitivityX(float sensitivity) = 0;
    virtual void setSensitivityY(float sensitivity) = 0;
    virtual float getSensitivityX() = 0;
    virtual float getSensitivityY() = 0;
  };
}

#endif // EVENTSHANDLER_H
