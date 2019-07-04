#ifndef OS_H
#define OS_H

#include "opencv2/core.hpp"

namespace os
{

  class OS
  {
  public:
    virtual ~OS();

    virtual cv::Rect getScreenSize() = 0;
    virtual void setCursorPosition(const cv::Point position) = 0;
    virtual void mouseLBDown() = 0;
    virtual void mouseLBUp() = 0;
    virtual void mouseRBDown() = 0;
    virtual void mouseRBUp() = 0;
    virtual cv::Point2f getScreenCenter() = 0;
  };

}

#endif // OS_H
