#include "ocvcamera.h"

#include "opencv2/videoio.hpp"

#include "../CameraOccupiedException.h"
#include "../CameraOpenException.h"


using namespace camera;
using namespace cv;
using namespace std;

camera::OCVCamera::OCVCamera() {
    capturer = VideoCapture(0);
}

OCVCamera::~OCVCamera() {
    release();
}

void OCVCamera::initialize() {
    running = false;
//    capturer = VideoCapture(0);
//    if (!isOccupied())
//        throw CameraOccupiedException();
}

void OCVCamera::start() {
//    capturer = VideoCapture(0);
//    capturer.set(CAP_PROP_FRAME_WIDTH, 320);
//    capturer.set(CAP_PROP_FRAME_HEIGHT, 240);

    if (!capturer.open(0))
        isOccupied() ? throw CameraOccupiedException() : throw CameraOpenException();
    running = true;
}


void OCVCamera::snapshot(Mat& frame) {
    capturer.read(frame);
}

void OCVCamera::stop() {
    capturer.release();
    running = false;
}

void OCVCamera::release() {
    stop();
}

inline bool OCVCamera::isOccupied() {
    return capturer.isOpened();
}

