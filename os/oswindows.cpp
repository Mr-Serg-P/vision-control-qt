#include "oswindows.h"

#include <windows.h>

#include "opencv2/core.hpp"


using namespace os;
using namespace cv;

OSWindows::OSWindows()
{
  screenSize = Rect2f(0, 0, GetSystemMetrics(SM_CXFULLSCREEN) * 1.f, GetSystemMetrics(SM_CYFULLSCREEN) * 1.f);
  screenCenter = Point2f(screenSize.width / 2.f, screenSize.height / 2.f);
}

OSWindows::~OSWindows()
{

}

Rect OSWindows::getScreenSize()
{
  return screenSize;
}

void OSWindows::setCursorPosition(const Point position)
{
  SetCursorPos(position.x, position.y);
}

void OSWindows::sendInput(DWORD mouseEventFlag)
{
  INPUT input = {0};
  input.type = INPUT_MOUSE;
  input.mi.dwFlags = mouseEventFlag;
  SendInput(1, &input, sizeof(INPUT));
  ZeroMemory(&input, sizeof (INPUT));
}

void OSWindows::mouseLBDown()
{
  sendInput(MOUSEEVENTF_LEFTDOWN);
  mouseLBUp();
}

void OSWindows::mouseLBUp()
{
  sendInput(MOUSEEVENTF_LEFTUP);
}

void OSWindows::mouseRBDown()
{
  sendInput(MOUSEEVENTF_RIGHTDOWN);
  mouseRBUp();
}

void OSWindows::mouseRBUp()
{
  sendInput(MOUSEEVENTF_RIGHTUP);
}

Point2f OSWindows::getScreenCenter()
{
  return screenCenter;
}
