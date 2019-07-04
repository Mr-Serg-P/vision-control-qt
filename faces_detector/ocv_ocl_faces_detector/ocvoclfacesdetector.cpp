#include "ocvoclfacesdetector.h"

#include <QString>
#include <string>
#include <vector>

#include "opencv2/core.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/objdetect.hpp"

using namespace std;
using namespace cv;
using namespace cv::ocl;
using namespace faces_detector;

const string faces_detector::OcvOclFacesDetector::haarcascadePath = "../haarcascade_frontalface_alt2.xml";

faces_detector::OcvOclFacesDetector::OcvOclFacesDetector()
{
  setUseOpenCL(true);
#ifdef DEBUG
  cout << "USE OPENCL: " << useOpenCL(); << endl;
#endif

  classifier = CascadeClassifier(haarcascadePath);
}

faces_detector::OcvOclFacesDetector::~OcvOclFacesDetector()
{
  ocl::setUseOpenCL(false);
  classifier.~CascadeClassifier();
}

vector<Rect> OcvOclFacesDetector::detect(const cv::Mat& img) {
    vector<Rect> detections;
    UMat uimg = img.getUMat(ACCESS_READ);
    classifier.detectMultiScale(uimg, detections);

    return detections;
}
