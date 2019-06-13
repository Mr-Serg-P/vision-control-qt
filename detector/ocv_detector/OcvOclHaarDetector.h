//
// Created by Serg on 31.05.2019.
//

#ifndef OCVOCLHAARDETECTOR_H
#define OCVOCLHAARDETECTOR_H

#include <string.h>

#include "opencv2/core.hpp"
#include "opencv2/objdetect.hpp"

#include "../Detector.h"

//TODO Change haarcascadePath

namespace detector {

    class OcvOclHaarDetector : public Detector {
    private:
        static const std::string haarcascadePath;
        cv::CascadeClassifier classifier;

    public:
        OcvOclHaarDetector();

        ~OcvOclHaarDetector() override;

        vector<Rect> detector(UMat *img) override;
    };

}

#include "OcvOclHaarDetector.cpp"

#endif
