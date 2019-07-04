#include "ocvfaciallandmarksdetector.h"

#include <string>
#include <vector>

#include "QCoreApplication"

#include "opencv2/core.hpp"
#include "opencv2/face.hpp"

using namespace landmarks_detector;
using namespace std;
using namespace cv;
using namespace cv::face;

const string OcvFacialLandmarksDetector::lbfModelPath = "../lbfmodel.yaml";

OcvFacialLandmarksDetector::OcvFacialLandmarksDetector()
{
  facemark = FacemarkLBF::create();
  facemark->loadModel(OcvFacialLandmarksDetector::lbfModelPath);
}

OcvFacialLandmarksDetector::~OcvFacialLandmarksDetector()
{

}

vector<vector<Point2f>> OcvFacialLandmarksDetector::detectLandmarks(const cv::Mat& img, const vector<Rect>& detections)
{
//  detections.at(0).height = detections.at(0).height * 1.05f;
  vector<vector<Point2f>> landmarks;

  facemark->fit(img, detections, landmarks);

  return landmarks;
}
