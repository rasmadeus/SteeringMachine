#-------------------------------------------------
#
# Project created by QtCreator 2013-05-20T10:57:18
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    function/output/child/NewAntiBlendFilter.cpp \
    data/APF.cpp \
    function/output/child/rudder_play/CRudderPlay.cpp \
    function/output/child/RudderPlay.cpp \
    function/output/child/rudder_play_child/WithoutBackLink.cpp \
    function/output/child/rudder_play_child/WithBackLink.cpp \
    function/output/child/rudder_play_child/WithoutBackLinkSave.cpp \
    function/output/child/OscillatoryLink.cpp \
    function/output/child/Sinus.cpp \
    main_window/APFCThread.cpp

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
    function/output/child/NewAntiBlendFilter.h \
    function/output/child/rudder_play/CRudderPlay.h \
    function/output/child/RudderPlay.h \
    function/output/child/rudder_play_child/WithoutBackLink.h \
    function/output/child/rudder_play_child/WithBackLink.h \
    function/output/child/rudder_play_child/WithoutBackLinkSave.h \
    function/output/child/OscillatoryLink.h \
    function/output/child/Sinus.h \
    main_window/APFCThread.h

FORMS    +=  main_window/view.ui

RESOURCES += \
    resources.qrc




























































































