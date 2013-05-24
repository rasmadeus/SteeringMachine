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
    data/Data.cpp \
    data/AmplitudePhaseFrequency.cpp \
    data/APFC.cpp \
    main_window/view.cpp \
    function/output/Output.cpp \
    function/output/child/SteeringMachine.cpp \
    function/output/OutMaker.cpp \
    function/output/Delegate.cpp \
    function/output/child/NewAntiBlendFilter.cpp

HEADERS  +=  function/Function.h \
    function/input/Input.h \
    data/Data.h \
    data/AmplitudePhaseFrequency.h \
    data/APFC.h \
    main_window/view.h \
    function/output/Output.h \
    function/output/child/SteeringMachine.h \
    function/output/OutMaker.h \
    function/output/Delegate.h \
    function/output/child/NewAntiBlendFilter.h

FORMS    +=  main_window/view.ui

RESOURCES += \
    resources.qrc























































