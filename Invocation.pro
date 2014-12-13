TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11


SOURCES += \
    Invocable.cpp \
    InvocationTest.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    FunctionInvoker.h \
    Invocable.h \
    InvokerHelperDefines.h \
    MethodInvoker.h \
    RepeatDefines.h \
    StrategyInvocationHelpers.h \
    StringUtilities.hpp

