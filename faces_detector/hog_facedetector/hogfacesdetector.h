#ifndef HOGFACEDETECTOR_H
#define HOGFACEDETECTOR_H

#include "../facesdetector.h"

#include "dlib/opencv.h"
#include "dlib/image_processing.h"
#include "dlib/image_processing/frontal_face_detector.h"

namespace faces_detector
{

  class HogFacesDetector : public FacesDetector
  {
  public:
    HogFacesDetector();
    ~HogFacesDetector();

    std::vector<cv::Rect> detect(const cv::Mat& img);

  private:
    dlib::frontal_face_detector detector;

  };

}

#endif // HOGFACEDETECTOR_H
