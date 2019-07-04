#ifndef CAMERAOPENEXCEPTION_H
#define CAMERAOPENEXCEPTION_H

#include <exception>

using namespace std;

namespace camera {
  class CameraOpenException : public exception {
  public:
    CameraOpenException();
  };
}

#endif // CAMERAOPENEXCEPTION_H
