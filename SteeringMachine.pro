#-------------------------------------------------
#
# Project created by QtCreator 2013-05-20T10:57:18
#
#-------------------------------------------------

QT       += core gui

TARGET = SteeringMachine
TEMPLATE = app


SOURCES += main.cpp\
    function/Function.cpp \
    function/input/Input.cpp \
    function/steering_machine/SteeringMachine.cpp \  
    data/Data.cpp \
    data/AmplitudePhaseFrequency.cpp \
    data/APFC.cpp \
    main_window/view.cpp

HEADERS  +=  function/Function.h \
    function/input/Input.h \
    function/steering_machine/SteeringMachine.h \
    data/Data.h \
    data/AmplitudePhaseFrequency.h \
    data/APFC.h \
    main_window/view.h

FORMS    +=  main_window/view.ui

RESOURCES += \
    resources.qrc































