#-------------------------------------------------
#
# Project created by QtCreator 2019-06-13T11:16:48
#
#-------------------------------------------------


QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vision-control-qt
TEMPLATE = app
CONFIG += static

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES += \
        backend/backend.cpp \
        camera/camera.cpp \
        camera/cameraoccupiedexception.cpp \
        camera/cameraopenexception.cpp \
        camera/ocv_camera/ocvcamera.cpp \
        events_handler/default_events_handler/defaulteventshandler.cpp \
        events_handler/dlib_events_handler/dlibeventshandler.cpp \
        events_handler/eventshandler.cpp \
        faces_detector/facesdetector.cpp \
        faces_detector/hog_facedetector/hogfacesdetector.cpp \
        faces_detector/ocv_ocl_faces_detector/ocvoclfacesdetector.cpp \
        landmarks_detector/dlib_facial_landmarks_detector/dlibfaciallandmarksdetector.cpp \
        landmarks_detector/faciallandmarksdetector.cpp \
        landmarks_detector/ocv_facial_landmarks_detector/ocvfaciallandmarksdetector.cpp \
        main.cpp \
        mainwindow.cpp \
        os/os.cpp \
        os/oswindows.cpp \
        settingswindow.cpp \
        workingthread.cpp

HEADERS += \
        backend/backend.h \
        camera/camera.h \
        camera/cameraoccupiedexception.h \
        camera/cameraopenexception.h \
        camera/ocv_camera/ocvcamera.h \
        events_handler/default_events_handler/defaulteventshandler.h \
        events_handler/dlib_events_handler/dlibeventshandler.h \
        events_handler/eventshandler.h \
        faces_detector/facesdetector.h \
        faces_detector/hog_facedetector/hogfacesdetector.h \
        faces_detector/ocv_ocl_faces_detector/ocvoclfacesdetector.h \
        landmarks_detector/dlib_facial_landmarks_detector/dlibfaciallandmarksdetector.h \
        landmarks_detector/faciallandmarksdetector.h \
        landmarks_detector/ocv_facial_landmarks_detector/ocvfaciallandmarksdetector.h \
        mainwindow.h \
        os/os.h \
        os/oswindows.h \
        settingswindow.h \
        workingthread.h

FORMS += \
        mainwindow.ui \
        settingswindow.ui

INCLUDEPATH += $$(OPENCV_SDK_DIR)/include
INCLUDEPATH += $$(DLIB_DIR)/include

LIBS += -L$$(OPENCV_SDK_DIR)/x64/mingw/lib \
        -lopencv_core410 \
        -lopencv_imgproc410 \
        -lopencv_videoio410 \
        -lopencv_objdetect410 \
        -lopencv_face410
LIBS += $$(DLIB_DIR)/lib/libdlib.a

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
