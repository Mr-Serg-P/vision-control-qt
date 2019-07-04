CONFIG += console c++17

INCLUDEPATH += "googletest-1-8-1/include"
INCLUDEPATH += "googletest-1-8-1/"
INCLUDEPATH += "../../"
INCLUDEPATH += $$(OPENCV_SDK_DIR)/include
INCLUDEPATH += $$(DLIB_DIR)/include

SOURCES += \
    ../../events_handler/default_events_handler/defaulteventshandler.cpp \
    ../../events_handler/eventshandler.cpp \
    ../../faces_detector/facesdetector.cpp \
    ../../faces_detector/hog_facedetector/hogfacesdetector.cpp \
    ../../faces_detector/ocv_ocl_faces_detector/ocvoclfacesdetector.cpp \
    ../../landmarks_detector/dlib_facial_landmarks_detector/dlibfaciallandmarksdetector.cpp \
    ../../landmarks_detector/faciallandmarksdetector.cpp \
    ../../landmarks_detector/ocv_facial_landmarks_detector/ocvfaciallandmarksdetector.cpp \
    googletest-1-8-1/src/gtest-all.cc \
    googletest-1-8-1/src/gtest-death-test.cc \
    googletest-1-8-1/src/gtest-filepath.cc \
    googletest-1-8-1/src/gtest-port.cc \
    googletest-1-8-1/src/gtest-printers.cc \
    googletest-1-8-1/src/gtest-test-part.cc \
    googletest-1-8-1/src/gtest-typed-test.cc \
    googletest-1-8-1/src/gtest.cc \
    main.cpp

HEADERS += \
    ../../events_handler/default_events_handler/defaulteventshandler.h \
    ../../events_handler/eventshandler.h \
    ../../faces_detector/facesdetector.h \
    ../../faces_detector/hog_facedetector/hogfacesdetector.h \
    ../../faces_detector/ocv_ocl_faces_detector/ocvoclfacesdetector.h \
    ../../landmarks_detector/dlib_facial_landmarks_detector/dlibfaciallandmarksdetector.h \
    ../../landmarks_detector/faciallandmarksdetector.h \
    ../../landmarks_detector/ocv_facial_landmarks_detector/ocvfaciallandmarksdetector.h

LIBS += -L$$(OPENCV_SDK_DIR)/x64/mingw/lib \
        -lopencv_core410 \
        -lopencv_imgproc410 \
        -lopencv_videoio410 \
        -lopencv_objdetect410 \
        -lopencv_face410 \
        -lopencv_imgcodecs410
LIBS += $$(DLIB_DIR)/lib/libdlib.a
