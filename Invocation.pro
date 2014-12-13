TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    FunctionInvoker.cpp \
    Invocable.cpp \
    InvocationTest.cpp \
    StreamOperatorOverloads.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    FunctionInvoker.h \
    Invocable.h \
    InvokerHelperDefines.h \
    MethodInvoker.h \
    RepeatDefines.h \
    StrategyInvocationHelpers.h

