//
// Created by Serg on 05.06.2019.
//

#include "DefaultEventsHandler.h"
#include "windows.h"
#include <iostream>


using namespace events_handling;

using namespace cv;

DefaultEventsHandler::DefaultEventsHandler() {
    screenSize = Rect2f(0, 0, GetSystemMetrics(SM_CXFULLSCREEN) * 1.f, GetSystemMetrics(SM_CYFULLSCREEN) * 1.f);
//    screenCenter = Point2f(screenSize.width / 2.f, screenSize.height / 2.f);
    anchorPoint = unique_ptr<Point2f>(nullptr);
    controlRegion = unique_ptr<Rect2f>(nullptr);
}

DefaultEventsHandler::~DefaultEventsHandler() {

}

void DefaultEventsHandler::generateEvents(const vector<Point2f>& landmarks, const Rect& faceRegion) {
    if (anchorPoint.get() == nullptr || controlRegion == nullptr)
        return;

    float screenPerFacePixelsWidth = screenSize.width / controlRegion->width;
    float screenPerFacePixelsHeight = screenSize.height / controlRegion->height;

    Point cursorPos = Point();
    cursorPos.x = screenSize.width * (1 - (landmarks.at(30).x - controlRegion->x) / controlRegion->width);
    cursorPos.y = screenSize.height - screenSize.height * (1 - (landmarks.at(30).y - controlRegion->y) / controlRegion->height);

    SetCursorPos(cursorPos.x, cursorPos.y);

    float rightEyeAR = (euclideanDistance(landmarks.at(RIGHT_EYE_TOP_RIGHT), landmarks.at(RIGHT_EYE_BOTTOM_RIGHT)) + euclideanDistance(landmarks.at(RIGHT_EYE_TOP_LEFT), landmarks.at(RIGHT_EYE_BOTTOM_LEFT))) / (2.f * euclideanDistance(landmarks.at(RIGHT_EYE_RIGHT), landmarks.at(RIGHT_EYE_LEFT)));
    float leftEyeAR = (euclideanDistance(landmarks.at(LEFT_EYE_TOP_RIGHT), landmarks.at(LEFT_EYE_BOTTOM_RIGHT)) + euclideanDistance(landmarks.at(LEFT_EYE_TOP_LEFT), landmarks.at(LEFT_EYE_BOTTOM_LEFT))) / (2.f * euclideanDistance(landmarks.at(LEFT_EYE_RIGHT), landmarks.at(LEFT_EYE_LEFT)));
    float mouthAR = (
            euclideanDistance(landmarks.at(MOUTH_TOP_RIGHT), landmarks.at(MOUTH_BOTTOM_RIGHT)) +
            euclideanDistance(landmarks.at(MOUTH_TOP_MID), landmarks.at(MOUTH_BOTTOM_MID)) +
            euclideanDistance(landmarks.at(MOUTH_TOP_LEFT), landmarks.at(MOUTH_BOTTOM_LEFT))) /
            (2 * (euclideanDistance(landmarks.at(MOUTH_RIGHT), landmarks.at(MOUTH_LEFT))));

//    blink
    if (isEyeClosed(leftEyeAR) && isEyeClosed(rightEyeAR)) {
        cout << "BLINK" << endl;
        return;
    }
    if (isEyeClosed(leftEyeAR)) {
        cout << "LEFT EYE CLOSED" << endl;
    }
    if (isEyeClosed(rightEyeAR)) {
        cout << "RIGHT EYE CLOSED" << endl;
    }
    if (isEyeWink(leftEyeAR) && isEyeWink(rightEyeAR)) {
        cout << "WINK" << endl;
        return;
    }
    if (isEyeWink(leftEyeAR)) {
        cout << "LEFT EYE WINK" << endl;
    }
    if (isEyeWink(rightEyeAR)) {
        cout << "RIGHT EYE WINK" << endl;
    }
    if (isEyeWideOpened(leftEyeAR) && isEyeWideOpened(rightEyeAR)) {
        cout << "WIDE OPENED" << endl;
        return;
    }
    if (isEyeWideOpened(leftEyeAR)) {
        cout << "LEFT EYE WIDE OPENED" << endl;
    }
    if (isEyeWideOpened(rightEyeAR)) {
        cout << "RIGHT EYE WIDE OPENED" << endl;
    }

}

void DefaultEventsHandler::freeze(const Point2f& anchorPoint, const Rect2f& controlRect) {
    this->anchorPoint.reset(new Point2f(anchorPoint));
    this->controlRegion.reset(new Rect2f(controlRect));
}

const Point2f* DefaultEventsHandler::getAnchorPoint() {
    return anchorPoint.get();
}

const Rect2f* DefaultEventsHandler::getControlRect() {
    return controlRegion.get();
}

float DefaultEventsHandler::euclideanDistance(const Point2f& point0, const Point2f& point1) {
    Point2f distance = point0 - point1;
    float result = cv::sqrt(distance.x * distance.x + distance.y * distance.y);
    return result;
}

inline bool DefaultEventsHandler::isEyeClosed(float EAR) {
    return EAR < EYE_WINK_AR - 0.1;
}

inline bool DefaultEventsHandler::isEyeWink(float EAR) {
    return EAR < EYE_WINK_AR + EYE_ACTION_DELTA && EAR > EYE_WINK_AR - EYE_ACTION_DELTA;
}

inline bool DefaultEventsHandler::isEyeWideOpened(float EAR){
    return EAR > EYE_WIDE_OPENED_AR - EYE_ACTION_DELTA;
}

//void countDistance() {
//
//}
