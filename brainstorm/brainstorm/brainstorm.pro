QT += core gui
QT += sql
QT += widgets uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    src/absences.cpp \
    src/admin.cpp \
    src/feedback.cpp \
    src/gradesButtons.cpp \
    src/grades.cpp \
    src/loggedInWindow.cpp \
    src/mainWindow.cpp \
    src/main.cpp \
    src/user.cpp

HEADERS += \
    include/absences.h \
    include/admin.h \
    include/feedback.h \
    include/gradesButtons.h \
    include/db.h \
    include/grades.h \
    include/mainWindow.h \
    include/loggedInWindow.h \
    include/pch.h \
    include/user.h \
    include/validatorlib.h

FORMS += \
    forms/loggedInWindow.ui \
    forms/mainWindow.ui \
    forms/mainWindow.ui \
    forms/loggedInWindow.ui \
    forms/gradesButtons.ui

LIBS += -L../lib/ -lvalidatorlib \
        -L../lib/ -ldatabaselib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    brainstorm.pro.user \
    lib/validatorlib.lib \
    lib/databaselib.lib

RESOURCES += \
    ../assets/bg.png/background.qrc
