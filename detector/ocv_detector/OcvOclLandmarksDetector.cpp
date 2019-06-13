//
// Created by Serg on 01.06.2019.
//

#include "OcvOclLandmarksDetector.h"

#include <string.h>

#include "opencv2/core.hpp"
#include "opencv2/face.hpp"

#include "../LandmarksDetector.h"

using namespace std;
using namespace cv;
using namespace cv::face;
using namespace detector;

const string OcvOclLandmarksDetector::lbfModelPath = "lbfmodel.yaml";

OcvOclLandmarksDetector::OcvOclLandmarksDetector() {
    facemark = FacemarkLBF::create();
    facemark->loadModel(OcvOclLandmarksDetector::lbfModelPath);
}

OcvOclLandmarksDetector::~OcvOclLandmarksDetector() {

}

vector<vector<Point2f>> OcvOclLandmarksDetector::detectLandmarks(const UMat *img, const vector<Rect>* detections) {
    vector<vector<Point2f>> landmarks;

    facemark->fit(*img, *detections, landmarks);

    return landmarks;
}
