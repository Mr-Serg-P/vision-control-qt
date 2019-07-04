#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <windows.h>

#include <bits/unique_ptr.h>

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QCloseEvent>
#include <QThread>

#include <string>

#include "opencv2/core.hpp"

#include "workingthread.h"
#include "settingswindow.h"


namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

  ~MainWindow();

public slots:
  void updateResolution(int resolutionCode);
  void updateDetectionMethod(int methodCode);
  void updateSensitivityX(int sensitivity);
  void updateSensitivityY(int sensitivity);

protected:
  void closeEvent(QCloseEvent* event);

private:
  Ui::MainWindow *ui;
  QMenu* settingsBtn;
  SettingsWindow* settingsWindow;

  QGraphicsPixmapItem pixmap;

  bool isWorking;

  QThread* mouseControlThread;

  WorkingThread* workingThread;

private slots:
  void updateSnapshot(cv::Mat snapshot, double fps);
  void onStartBtnClick();
  void openSettingsWindow();

signals:
  void freezeControlRegion();

};

#endif // MAINWINDOW_H
