//
// Created by Serg on 01.06.2019.
//

#ifndef LANDMARKSDETECTOR_H
#define LANDMARKSDETECTOR_H

#include "opencv2/core.hpp"

//TODO Remove opencv dependencies

namespace detector {

    class LandmarksDetector {
    public:
        virtual ~LandmarksDetector() {}

        virtual vector<vector<Point2f>> detectLandmarks(const UMat *img, const vector<Rect>* detections) = 0;
    };

}


#endif
