//
// Created by Serg on 05.06.2019.
//

#ifndef DEFAULTEVENTSHANDLER_H
#define DEFAULTEVENTSHANDLER_H

#include "opencv2/core.hpp"

#include "../EventsHandler.h"

using namespace cv;

using namespace events_handling;

namespace events_handling {

    class DefaultEventsHandler : public EventsHandler {
    public:
        unique_ptr<cv::Point2f> anchorPoint;
        unique_ptr<cv::Rect2f> controlRegion;

        DefaultEventsHandler();

        ~DefaultEventsHandler();

        void generateEvents(const vector<cv::Point2f>& landmarks, const cv::Rect& faceRegion) override;
        void freeze(const cv::Point2f &anchorPoint, const cv::Rect2f &controlRect) override;
        virtual const Point2f * getAnchorPoint() override;
        virtual const Rect2f * getControlRect()  override;

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

        const int MOUTH_RIGHT = 48;
        const int MOUTH_LEFT = 54;
        const int MOUTH_TOP_RIGHT = 60;
        const int MOUTH_TOP_MID = 61;
        const int MOUTH_TOP_LEFT = 62;
        const int MOUTH_BOTTOM_RIGHT = 65;
        const int MOUTH_BOTTOM_MID = 64;
        const int MOUTH_BOTTOM_LEFT = 63;

        cv::Rect2f screenSize;

        const float EYE_WIDE_OPENED_AR = 0.3;
        const float EYE_WINK_AR = 0.16;
        const float EYE_CLOSED_AR = 0.15;
        const float EYE_ACTION_DELTA = 0.01;
        const float MOUTH_OPENED_AR = 0.63;

        float euclideanDistance(const Point2f& point0, const Point2f& point1);

        inline bool isEyeClosed(float EAR);
        inline bool isEyeWink(float EAR);
        inline bool isEyeWideOpened(float EAR);
;    };

}

#include "DefaultEventsHandler.cpp"

#endif
