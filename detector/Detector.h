//
// Created by Serg on 31.05.2019.
//

#ifndef DETECTOR_H
#define DETECTOR_H

#include "opencv2/core.hpp"

//TODO Remove opencv dependencies

namespace detector {

    class Detector {
    public:
        virtual ~Detector() {}

        virtual vector<Rect> detector(UMat *img) = 0;
    };

}

#endif
