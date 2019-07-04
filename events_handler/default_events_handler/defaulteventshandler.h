#ifndef DEFAULTEVENTSHANDLER_H
#define DEFAULTEVENTSHANDLER_H

#include <vector>

#include <bits/unique_ptr.h>

#include "opencv2/core.hpp"

#include "../eventshandler.h"
#include "../../os/os.h"
#include "../../os/oswindows.h"

namespace events_handling
{

  class DefaultEventsHandler :public EventsHandler
  {
  public:

    DefaultEventsHandler();

    ~DefaultEventsHandler() override;

    void generateEvents(const std::vector<cv::Point2f> &landmarks, const cv::Rect &faceRegion) override;
    void freeze(const cv::Point2f& anchorPoint, const cv::Rect2f& controlRect) override;
    const cv::Point2f* getAnchorPoint() override;
    const cv::Rect2f* getControlRect() override;
    void setSensitivityX(float sensitivity) override;
    void setSensitivityY(float sensitivity) override;
    float getSensitivityX() override;
    float getSensitivityY() override;

  private:
    const int RIGHT_EYE_RIGHT = 36;
    const int RIGHT_EYE_LEFT = 39;
    const int RIGHT_EYE_TOP_RIGHT = 37;
    const int RIGHT_EYE_TOP_LEFT = 38;
    const int RIGHT_EYE_BOTTOM_RIGHT = 41;
    const int RIGHT_EYE_BOTTOM_LEFT = 40;

    const int LEFT_EYE_RIGHT = 42;
    const int LEFT_EYE_LEFT = 45;
    const int LEFT_EYE_TOP_RIGHT = 43;
    const int LEFT_EYE_TOP_LEFT = 44;
    const int LEFT_EYE_BOTTOM_RIGHT = 47;
    const int LEFT_EYE_BOTTOM_LEFT = 46;

    const int MOUTH_RIGHT = 60;
    const int MOUTH_LEFT = 64;
    const int MOUTH_TOP_RIGHT = 61;
    const int MOUTH_TOP_MID = 62;
    const int MOUTH_TOP_LEFT = 63;
    const int MOUTH_BOTTOM_RIGHT = 67;
    const int MOUTH_BOTTOM_MID = 66;
    const int MOUTH_BOTTOM_LEFT = 65;

    const float EYE_WIDE_OPENED_AR = 0.3f;
    const float EYE_WINK_AR = 0.14f;
    const float EYE_CLOSED_AR = 0.15f;
    const float EYE_ACTION_DELTA = 0.01f;
    const float MOUTH_OPENED_AR = 0.7f;

    std::unique_ptr<cv::Point2f> anchorPoint;
    std::unique_ptr<cv::Rect2f> controlRegion;

    cv::Rect2f screenSize;
    std::unique_ptr<os::OS> osWrapper;
    bool leftEyeWasClosed = false;
    bool rightEyeWasClosed = false;
    float sensitivityX;
    float sensitivityY;

    float euclideanDistance(const cv::Point2f& point0, const cv::Point2f& point1);

    inline bool isEyeClosed(float EAR);
    inline bool isEyeWink(float EAR);
    inline bool isEyeWideOpened(float EAR);
    inline bool isMouthOpened(float MAR);
  };

}

#endif // DEFAULTEVENTSHANDLER_H
