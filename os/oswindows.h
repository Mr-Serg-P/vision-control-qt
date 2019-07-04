#ifndef WINDOWS_H
#define WINDOWS_H

#ifdef WIN32

#include <windows.h>

#include "opencv2/core.hpp"

#include "os.h"

namespace os
{

  class OSWindows : public OS
  {
  public:
    OSWindows();

    ~OSWindows() override;

    virtual cv::Rect getScreenSize() override;
    virtual void setCursorPosition(const cv::Point position) override;
    virtual void mouseLBDown() override;
    virtual void mouseLBUp() override;
    virtual void mouseRBDown() override;
    virtual void mouseRBUp() override;
    virtual cv::Point2f getScreenCenter() override;

  private:
    cv::Point2f screenCenter;
    cv::Rect screenSize;

    inline void sendInput(DWORD mouseEventFlag);
  };

}

#endif

#endif // WINDOWS_H
