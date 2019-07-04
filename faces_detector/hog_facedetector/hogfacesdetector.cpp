#include "hogfacesdetector.h"

#include <vector>

#include "opencv2/core.hpp"

#include "dlib/opencv.h"
#include "dlib/image_processing.h"
#include "dlib/image_processing/frontal_face_detector.h"

using namespace std;
using namespace dlib;
using namespace cv;
using namespace faces_detector;

HogFacesDetector::HogFacesDetector()
{
  detector = dlib::get_frontal_face_detector();
}

HogFacesDetector::~HogFacesDetector()
{

}

std::vector<Rect> HogFacesDetector::detect(const Mat& img) {
    auto result = std::vector<Rect>();
    auto dlibImg = cv_image<bgr_pixel>(img);

    std::vector<dlib::rectangle> detections = detector(dlibImg);

    for (auto rect : detections)
    {
      result.push_back(Rect(rect.left(), rect.top(), rect.width(), rect.height()));
    }

    return result;
}
