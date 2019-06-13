//
// Created by Serg on 01.06.2019.
//

#ifndef OCVOCLLANDMARKSDETECTOR_H
#define OCVOCLLANDMARKSDETECTOR_H

#include <string.h>

#include "opencv2/core.hpp"
#include "opencv2/face.hpp"

#include "../LandmarksDetector.h"

class OcvOclLandmarksDetector : public LandmarksDetector {
private:
    static const std::string lbfModelPath;

    cv::Ptr<cv::face::Facemark> facemark;

public:
    OcvOclLandmarksDetector();

    ~OcvOclLandmarksDetector();

    vector<vector<Point2f>> detectLandmarks(const UMat* img, const vector<Rect>* detections) override;
};

#include "OcvOclLandmarksDetector.cpp"

#endif
