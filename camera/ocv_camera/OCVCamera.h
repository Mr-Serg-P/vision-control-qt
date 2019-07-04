#ifndef OCVCAMERA_H
#define OCVCAMERA_H

#include "../Camera.h"
#include "opencv2/videoio.hpp"


namespace camera {

    class OCVCamera : public Camera {
    private:
        cv::VideoCapture capturer;
        bool running;

        inline bool isOccupied();

    public:
        OCVCamera();

        ~OCVCamera() override;

        void initialize() override;
        void start() override;
        void snapshot(cv::Mat& frame) override;
        void stop() override;
        void release() override;
    };

}

#endif // OCVCAMERA_H
