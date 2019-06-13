//
// Created by Serg on 26.05.2019.
//

//#pragma once
#ifndef OCVCAMERA_H
#define OCVCAMERA_H

#include "../Camera.h"
#include "opencv2/videoio.hpp"
#include <thread>

namespace camera {

    class OCVCamera : public Camera {
    private:
        cv::VideoCapture capturer;
        bool running;

        inline bool isOccupied();

    public:
        OCVCamera();

        ~OCVCamera();

        void initialize() override;
        void start() override;
        void snapshot(cv::UMat *frame) override;
        void stop() override;
        void release() override;
    };

}

#include "OCVCamera.cpp"
#endif
//#include "OCVCamera.cpp"