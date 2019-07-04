#ifndef DLIBEVENTSHANDLER_H
#define DLIBEVENTSHANDLER_H

#include <vector>

#include <bits/unique_ptr.h>

#include "opencv2/core.hpp"

#include "../eventshandler.h"
#include "../../os/os.h"
#include "../../os/oswindows.h"

namespace events_handling
{

  class DlibEventsHandler : public EventsHandler
  {
  public:
    DlibEventsHandler();

    ~DlibEventsHandler() override;

    virtual void generateEvents(const std::vector<cv::Point2f> &landmarks, const cv::Rect &faceRegion) override;
    virtual void freeze(const cv::Point2f& anchorPoint, const cv::Rect2f& controlRect) override;
    virtual const cv::Point2f* getAnchorPoint() override;
    virtual const cv::Rect2f* getControlRect() override;
    void setSensitivityX(float sensitivity) override;
    void setSensitivityY(float sensitivity) override;
    float getSensitivityX() override;
    float getSensitivityY() override;

  private:
    const int RIGHT_EYE_RIGHT = 37;
    const int RIGHT_EYE_LEFT = 40;
    const int RIGHT_EYE_TOP_RIGHT = 38;
    const int RIGHT_EYE_TOP_LEFT = 39;
    const int RIGHT_EYE_BOTTOM_RIGHT = 42;
    const int RIGHT_EYE_BOTTOM_LEFT = 41;

    const int LEFT_EYE_RIGHT = 43;
    const int LEFT_EYE_LEFT = 46;
    const int LEFT_EYE_TOP_RIGHT = 44;
    const int LEFT_EYE_TOP_LEFT = 45;
    const int LEFT_EYE_BOTTOM_RIGHT = 48;
    const int LEFT_EYE_BOTTOM_LEFT = 47;

    const int MOUTH_RIGHT = 61;
    const int MOUTH_LEFT = 65;
    const int MOUTH_TOP_RIGHT = 62;
    const int MOUTH_TOP_MID = 63;
    const int MOUTH_TOP_LEFT = 64;
    const int MOUTH_BOTTOM_RIGHT = 68;
    const int MOUTH_BOTTOM_MID = 67;
    const int MOUTH_BOTTOM_LEFT = 66;

    const float EYE_WIDE_OPENED_AR = 0.3f;
    const float EYE_WINK_AR = 0.2f;
    const float EYE_CLOSED_AR = 0.15f;
    const float EYE_ACTION_DELTA = 0.01f;
    const float MOUTH_OPENED_AR = 0.7f;

    std::unique_ptr<cv::Point2f> anchorPoint;
    std::unique_ptr<cv::Rect2f> controlRegion;

    cv::Rect2f screenSize;
    std::unique_ptr<os::OS> osWrapper;
    bool leftEyeWasClosed = false;
    bool rightEyeWasClosed = false;

    float euclideanDistance(const cv::Point2f& point0, const cv::Point2f& point1);

    inline bool isEyeClosed(float EAR);
    inline bool isEyeWink(float EAR);
    inline bool isEyeWideOpened(float EAR);
    inline bool isMouthOpened(float MAR);
  };

}

#endif // DLIBEVENTSHANDLER_H
