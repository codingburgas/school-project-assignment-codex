QT += core gui
QT += sql
QT += widgets uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    src/admin.cpp \
    src/gradesButtons.cpp \
    src/grades.cpp \
    src/loggedInWindow.cpp \
    src/db.cpp \
    src/mainWindow.cpp \
    src/main.cpp

HEADERS += \
    include/admin.h \
    include/gradesButtons.h \
    include/db.h \
    include/grades.h \
    include/mainWindow.h \
    include/loggedInWindow.h \
    include/pch.h \
    include/validatorlib.h

FORMS += \
    forms/loggedInWindow.ui \
    forms/mainWindow.ui \
    forms/mainWindow.ui \
    forms/loggedInWindow.ui \
    forms/gradesButtons.ui

LIBS += -L$$PWD/../lib/ -lvalidatorlib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    brainstorm.pro.user \
    lib/validatorlib.lib

RESOURCES += \
    ../assets/bg.png/background.qrc
