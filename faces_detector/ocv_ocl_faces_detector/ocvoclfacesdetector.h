#ifndef OCVOCLFACESDETECTOR_H
#define OCVOCLFACESDETECTOR_H

#include <string>
#include <vector>

#include "opencv2/core.hpp"
#include "opencv2/objdetect.hpp"

#include "../facesdetector.h"

namespace faces_detector
{

  class OcvOclFacesDetector : public FacesDetector
  {
  private:
    static const std::string haarcascadePath;
    cv::CascadeClassifier classifier;

  public:
    OcvOclFacesDetector();
    ~OcvOclFacesDetector() override;
    std::vector<cv::Rect> detect(const cv::Mat& img) override;
  };

}

#endif // OCVOCLFACESDETECTOR_H
