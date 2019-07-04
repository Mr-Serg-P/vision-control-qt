#ifndef FACIALLANDMARKSDETECTOR_H
#define FACIALLANDMARKSDETECTOR_H

#include <vector>

#include "opencv2/core.hpp"


namespace landmarks_detector
{

  class FacialLandmarksDetector
  {
  public:
    virtual ~FacialLandmarksDetector();

    virtual std::vector<std::vector<cv::Point2f>> detectLandmarks(const cv::Mat& img, const std::vector<cv::Rect>& detections) = 0;
  };

}

#endif // FACIALLANDMARKSDETECTOR_H
