#ifndef WORKINGTHREAD_H
#define WORKINGTHREAD_H

#include <QThread>
#include <QString>

#include "opencv2/core.hpp"

#include "settingswindow.h"
#include "backend/backend.h"


class WorkingThread : public QThread
{
  Q_OBJECT

public:
  explicit WorkingThread();

  void run();
  void setImgResolution(int width, int height);
  void setDetectionMethod(int methodCode);
  void setSensitivityX(int sensitivity);
  void setSensitivityY(int sensitivity);
  float getSensitivityX();
  float getSensitivityY();
  void finalize();

public slots:
  void updateControlRegion();

signals:
  void snapshotChanged(cv::Mat img, double fps);

private:
//  int nosePoint = 30;
  int imgWidth;
  int imgHeight;
  bool isWorking;

  Backend backend;
};

#endif // WORKINGTHREAD_H
