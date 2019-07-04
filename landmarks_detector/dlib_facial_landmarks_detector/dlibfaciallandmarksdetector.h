#ifndef DLIBFACIALLANDMARKSDETECTOR_H
#define DLIBFACIALLANDMARKSDETECTOR_H

#include "opencv2/core.hpp"

#include "dlib/opencv.h"
#include "dlib/image_processing.h"
#include "dlib/image_processing/shape_predictor.h"

#include "../faciallandmarksdetector.h"

namespace landmarks_detector
{

  class DlibFacialLandmarksDetector : public FacialLandmarksDetector
  {
  public:
    DlibFacialLandmarksDetector();
    ~DlibFacialLandmarksDetector() override;

    std::vector<std::vector<cv::Point2f>> detectLandmarks(const cv::Mat& img, const std::vector<cv::Rect>& detections) override;

  private:
    dlib::shape_predictor predictor;
  };

}

#endif // DLIBFACIALLANDMARKSDETECTOR_H
