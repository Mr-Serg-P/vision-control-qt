#include "dlibfaciallandmarksdetector.h"

#include "opencv2/core.hpp"

#include "dlib/opencv.h"
#include "dlib/image_processing.h"
#include "dlib/image_processing/shape_predictor.h"


using namespace landmarks_detector;
using namespace cv;
using namespace dlib;

DlibFacialLandmarksDetector::DlibFacialLandmarksDetector()
{
  deserialize("shape_predictor_68_face_landmarks.dat") >> predictor;
}

DlibFacialLandmarksDetector::~DlibFacialLandmarksDetector()
{

}

std::vector<std::vector<cv::Point2f>> DlibFacialLandmarksDetector::detectLandmarks(const cv::Mat& img, const std::vector<cv::Rect>& detections)
{
  auto result = std::vector<std::vector<Point2f>>();
  auto dlibImg = cv_image<bgr_pixel>(img);

  auto dlibDetections = std::vector<rectangle>();
  for (auto rect : detections)
  {
    auto shape = predictor(dlibImg, rectangle(rect.x, rect.y, rect.x + rect.width, rect.y + rect.height));
    auto points = std::vector<Point2f>();
    for (unsigned long i = 0; i < shape.num_parts(); i++)
      points.push_back(Point2f(shape.part(i).x(), shape.part(i).y()));
    result.push_back(points);
  }

  return result;
}
