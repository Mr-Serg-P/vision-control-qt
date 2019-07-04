#ifndef CAMERAOCCUPIEDEXCEPTION_H
#define CAMERAOCCUPIEDEXCEPTION_H


#include <exception>

using namespace std;

namespace camera {

    class CameraOccupiedException : public exception {
    public:
      CameraOccupiedException();
    };

}

#endif // CAMERAOCCUPIEDEXCEPTION_H
