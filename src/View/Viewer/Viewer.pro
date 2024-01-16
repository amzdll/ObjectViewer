QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../Controller/Object_Controller/object_controller.cc \
    ../../Controller/Style_Controller/style_controlloer.cc \
    ../../Model/Object_Handler/Recorder/V_F_Recorder/v_f_parser.cc \
    ../../Model/Object_Handler/object_facade.cc \
    ../../Model/Style_Handler/style_handler.cc \
    ../../main.cc \
    ../Interaction_Panel/Modification_Panel/modification_panel.cc \
    ../Object_Observer/object_observer.cc \
    ../Interaction_Panel/Style_Panel/style_panel.cc \
    ../Object_Observer/updater.cc \
    ../Panel_Mediator/Mediator.cc \
    viewer.cc

HEADERS += \
    ../../Controller/Object_Controller/object_controller.h \
    ../../Controller/Style_Controller/style_controlloer.h \
    ../../Model/Object_Handler/Recorder/V_F_Recorder/v_f_parser.h \
    ../../Model/Object_Handler/Recorder/strategy_recorder.h \
    ../../Model/Object_Handler/common.h \
    ../../Model/Object_Handler/object_facade.h \
    ../../Model/Style_Handler/style_handler.h \
    ../Interaction_Panel/Modification_Panel/modification_panel.h \
    ../Object_Observer/object_observer.h \
    ../Interaction_Panel/Style_Panel/style_panel.h \
    ../Panel_Mediator/Mediator.h \
    viewer.h

FORMS += \
    ../Object_Observer/object_observer.ui \
    ../Interaction_Panel/Style_Panel/style_panel.ui \
    ../Interaction_Panel/Modification_Panel/modification_panel.ui \
    viewer.ui

ICON = $${PWD}/viewer.icns

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
