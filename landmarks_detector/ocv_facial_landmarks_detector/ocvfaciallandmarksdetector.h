#ifndef OCVFACIALLANDMARKSDETECTOR_H
#define OCVFACIALLANDMARKSDETECTOR_H

#include <string>
#include <vector>

#include "opencv2/core.hpp"
#include "opencv2/face.hpp"

#include "../faciallandmarksdetector.h"

namespace landmarks_detector
{

  class OcvFacialLandmarksDetector : public FacialLandmarksDetector
  {
  private:
    static const std::string lbfModelPath;

    cv::Ptr<cv::face::Facemark> facemark;

  public:
    OcvFacialLandmarksDetector();

    ~OcvFacialLandmarksDetector() override;

    std::vector<std::vector<cv::Point2f>> detectLandmarks(const cv::Mat& img, const std::vector<cv::Rect>& detections) override;
  };

}

#endif // OCVFACIALLANDMARKSDETECTOR_H
