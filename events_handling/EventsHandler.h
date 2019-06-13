//
// Created by Serg on 05.06.2019.
//

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "opencv2/core.hpp"

namespace events_handling {

    class EventsHandler {
    public:
        virtual void generateEvents(const vector<cv::Point2f> &landmarks, const cv::Rect &faceRegion) = 0;
        virtual void freeze(const cv::Point2f &anchorPoint, const Rect2f &controlRect) = 0;
        virtual const Point2f* getAnchorPoint() = 0;
        virtual const Rect2f* getControlRect() = 0;
    };

}

#endif
