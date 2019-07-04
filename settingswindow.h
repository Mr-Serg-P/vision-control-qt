#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>

namespace Ui {
  enum resolutions {small, medium, hd};
  enum detectionMethods {hog, haar};

  class SettingsWindow;
}

class SettingsWindow : public QWidget
{
  Q_OBJECT

public:
  explicit SettingsWindow(QWidget *parent = nullptr);
  ~SettingsWindow();

signals:
  void resolutionChanged(int resolutionCode);
  void detectionMethodChanged(int detectionMethod);
  void sensitivityXChanged(int sensitivity);
  void sensitivityYChanged(int sensitivity);

private:
  Ui::SettingsWindow *ui;

private slots:
  void updateResolution(int resolutionCode);
  void updateDetectionMethod(int methodCode);
  void updateSensitivityX(int sensitivity);
  void updateSensitivityY(int sensitivity);
};

#endif // SETTINGSWINDOW_H
