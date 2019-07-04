#ifdef QT_DEBUG
    #define DEBUG
#else
  #undef DEBUG
#endif

#include "mainwindow.h"

#include <QApplication>

#include <iostream>

#include "opencv2/core.hpp"
#include "opencv2/core/ocl.hpp"

#include "backend/backend.h"

using namespace std;
using namespace cv;
using namespace cv::ocl;

int main(int argc, char *argv[])
{
  QStringList paths = QCoreApplication::libraryPaths();
  paths.append(".");
  paths.append("platforms");
  QCoreApplication::setLibraryPaths(paths);

  QApplication a(argc, argv);
  qRegisterMetaType<cv::Mat>("cv::Mat");
  qRegisterMetaType<cv::Rect>("cv::Rect");
  qRegisterMetaType<cv::Point>("cv::Point");

#ifdef DEBUG
  std::cout << QCoreApplication::applicationFilePath().toStdString() << std::endl;
#endif

  MainWindow w;
  w.show();

  return a.exec();
}
