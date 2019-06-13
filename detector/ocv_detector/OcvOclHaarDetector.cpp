//
// Created by Serg on 31.05.2019.
//

#include <string.h>

#include "OcvOclHaarDetector.h"

using namespace std;
using namespace cv;
using namespace detector;

const string OcvOclHaarDetector::haarcascadePath = "haarcascade_frontalface_alt2.xml";

OcvOclHaarDetector::OcvOclHaarDetector() {
    classifier = CascadeClassifier(haarcascadePath);
}

OcvOclHaarDetector::~OcvOclHaarDetector() {

}

vector<Rect> OcvOclHaarDetector::detector(UMat *img) {
    vector<Rect> detections;
    classifier.detectMultiScale(*img, detections);

    return detections;
}

