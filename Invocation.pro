TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    FunctionInvoker.cpp \
    Invocable.cpp \
    InvocationTest.cpp \
    SaveInvocation.cpp \
    StrategyInvocationHelpers.cpp \
    StreamOperatorOverloads.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    FunctionInvoker.h \
    Invocable.h \
    InvokerHelperDefines.h \
    MethodInvoker.h \
    RepeatDefines.h \
    SaveInvocation.h \
    StrategyInvocationHelpers.h

