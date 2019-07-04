#include "settingswindow.h"
#include "ui_settingswindow.h"

#include <QComboBox>

#include "mainwindow.h"


SettingsWindow::SettingsWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SettingsWindow)
{
  ui->setupUi(this);

  this->ui->cameraResolutions->addItem("320 x 240", QVariant(Ui::resolutions::small));
  this->ui->cameraResolutions->addItem("640 x 480", QVariant(Ui::resolutions::medium));
  this->ui->cameraResolutions->addItem("1280 x 720", QVariant(Ui::resolutions::hd));

  this->ui->faceDetectionMethods->addItem("HOG (CPU)", QVariant(Ui::detectionMethods::hog));
  this->ui->faceDetectionMethods->addItem("Haar (OpenCL 1.2 CPU, GPU)", QVariant(Ui::detectionMethods::haar));

  connect(ui->cameraResolutions, SIGNAL(currentIndexChanged(int)), this, SLOT(updateResolution(int)));
  connect(ui->faceDetectionMethods, SIGNAL(currentIndexChanged(int)), this, SLOT(updateDetectionMethod(int)));
  connect(ui->sensitivityX, SIGNAL(valueChanged(int)), this, SLOT(updateSensitivityX(int)));
  connect(ui->sensitivityY, SIGNAL(valueChanged(int)), this, SLOT(updateSensitivityY(int)));
}

SettingsWindow::~SettingsWindow()
{
  delete ui;
}

void SettingsWindow::updateResolution(int resolutionCode)
{
  emit resolutionChanged(resolutionCode);
}

void SettingsWindow::updateDetectionMethod(int methodCode)
{
  emit detectionMethodChanged(methodCode);
}

void SettingsWindow::updateSensitivityX(int sensitivity)
{
  ui->infoScaleX->setText(QString::number(sensitivity));
  emit sensitivityXChanged(sensitivity);
}

void SettingsWindow::updateSensitivityY(int sensitivity)
{
  ui->infoScaleY->setText(QString::number(sensitivity));
  emit sensitivityYChanged(sensitivity);
}
