#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <windows.h>

#include <bits/unique_ptr.h>

#include <QMainWindow>
#include <QCloseEvent>
#include <QDebug>

#include "opencv2/core.hpp"

#include "workingthread.h"
#include "settingswindow.h"


using namespace std;
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->settingsMenu, &QMenu::aboutToShow, this, &MainWindow::openSettingsWindow);

  ui->graphicsView->setScene(new QGraphicsScene(this));
  ui->graphicsView->scene()->addItem(&pixmap);

  isWorking = true;

  settingsWindow = new SettingsWindow();
  settingsWindow->hide();

  connect(settingsWindow, SIGNAL(resolutionChanged(int)), this, SLOT(updateResolution(int)), Qt::ConnectionType::QueuedConnection);
  connect(settingsWindow, SIGNAL(detectionMethodChanged(int)), this, SLOT(updateDetectionMethod(int)), Qt::ConnectionType::QueuedConnection);
  connect(settingsWindow, SIGNAL(sensitivityXChanged(int)), this, SLOT(updateSensitivityX(int)));
  connect(settingsWindow, SIGNAL(sensitivityYChanged(int)), this, SLOT(updateSensitivityY(int)));

  workingThread = new WorkingThread();

  connect(ui->startBtn, &QPushButton::clicked, workingThread, &WorkingThread::updateControlRegion, Qt::ConnectionType::QueuedConnection);

  connect(workingThread, &WorkingThread::snapshotChanged, this, &MainWindow::updateSnapshot, Qt::ConnectionType::BlockingQueuedConnection);

  workingThread->start(QThread::NormalPriority);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::closeEvent(QCloseEvent* event)
{
  workingThread->finalize();
  workingThread->exit(0);

  event->accept();
}

void MainWindow::updateSnapshot(Mat snapshot, double fps)
{
  auto qimg = QImage(snapshot.data,
                     snapshot.cols,
                     snapshot.rows,
                     snapshot.step,
                     QImage::Format_RGB888);
  pixmap.setPixmap(QPixmap::fromImage(qimg.rgbSwapped()));
  ui->graphicsView->fitInView(&pixmap, Qt::KeepAspectRatio);
  qApp->processEvents();

  this->statusBar()->showMessage(QString("FPS: ") + QString::number(fps));
}

void MainWindow::onStartBtnClick()
{
  emit freezeControlRegion();
}

void MainWindow::openSettingsWindow()
{
  settingsWindow->show();
}

void MainWindow::updateResolution(int resolutionCode)
{
  switch (resolutionCode)
  {
    case Ui::resolutions::small:
      workingThread->setImgResolution(320, 240);
      break;
    case Ui::resolutions::medium:
      workingThread->setImgResolution(640, 480);
      break;
    case Ui::resolutions::hd:
      workingThread->setImgResolution(1280, 720);
      break;
    }
}

void MainWindow::updateDetectionMethod(int methodCode)
{
  workingThread->setDetectionMethod(methodCode);
}

void MainWindow::updateSensitivityX(int sensitivity)
{
  workingThread->setSensitivityX(sensitivity);
}

void MainWindow::updateSensitivityY(int sensitivity)
{
  workingThread->setSensitivityY(sensitivity);
}
