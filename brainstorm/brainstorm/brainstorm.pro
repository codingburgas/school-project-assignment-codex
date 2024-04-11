QT += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    src/grades.cpp \
    src/loggedInWindow.cpp \
    src/loggedInWindowAdmin.cpp \
    src/db.cpp \
    src/mainWindow.cpp \
    src/main.cpp

HEADERS += \
    include/db.h \
    include/grades.h \
    include/mainWindow.h \
    include/loggedInWindow.h \
    include/loggedInWindowAdmin.h \
    include/pch.h \
    include/validatorlib.h

FORMS += \
    forms/loggedInWindow.ui \
    forms/loggedInWindowAdmin.ui \
    forms/mainWindow.ui \
    forms/mainWindow.ui \
    forms/loggedInWindow.ui \
    forms/loggedInWindowAdmin.ui

LIBS += -L../lib/ -lvalidatorlib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    brainstorm.pro.user \
    lib/validatorlib.lib
