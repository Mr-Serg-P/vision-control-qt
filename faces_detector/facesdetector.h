#ifndef FACESDETECTOR_H
#define FACESDETECTOR_H

#include "opencv2/core.hpp"

namespace faces_detector
{

  class FacesDetector
  {
  public:
    virtual ~FacesDetector();

    virtual std::vector<cv::Rect> detect(const cv::Mat& img) = 0;
  };

}
#endif // FACESDETECTOR_H
