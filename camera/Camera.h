//
// Created by Serg on 27.05.2019.
//

#ifndef CAMERA_H
#define CAMERA_H

#include "opencv2/core.hpp"

//TODO Make Matrix abstraction

namespace camera {

    class Camera {
    public:
        virtual ~Camera() {};

        virtual void initialize() = 0;
        virtual void start() = 0;
        virtual void snapshot(cv::UMat* matrix) = 0;
        virtual void stop() = 0;
        virtual void release() = 0;
    };

}


#endif //VISION_CONTROL_CAMERA_H
