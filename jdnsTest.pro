TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
           dnstester.cpp

HEADERS += dnstester.h

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

include(../jdns/jdns.pri)

HEADERS +=
