//
// Created by Serg on 27.05.2019.
//

#ifndef CAMERAOCCUPIEDEXCEPTION_H
#define CAMERAOCCUPIEDEXCEPTION_H

#include <exception>

using namespace std;

namespace camera {

    class CameraOccupiedException : public exception {

    };

}

#include "CameraOccupiedException.cpp"

#endif //CAMERAOCCUPIEDEXCEPTION_H
