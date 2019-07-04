#ifndef CAMERA_H
#define CAMERA_H

#include "opencv2/core.hpp"

namespace camera {

    class Camera {
    public:
        virtual ~Camera();

        virtual void initialize() = 0;
        virtual void start() = 0;
        virtual void snapshot(cv::Mat& matrix) = 0;
        virtual void stop() = 0;
        virtual void release() = 0;
    };

}

#endif // CAMERA_H
