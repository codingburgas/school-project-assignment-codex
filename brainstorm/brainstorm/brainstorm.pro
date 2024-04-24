QT += core gui
QT += sql
QT += widgets uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    business/src/gradesButtons.cpp \
    business/src/loggedInWindow.cpp \
    business/src/main.cpp \
    business/src/mainWindow.cpp \
    data/src/absences.cpp \
    data/src/admin.cpp \
    data/src/feedback.cpp \
    data/src/grades.cpp \
    data/src/user.cpp

HEADERS += \
    business/include/gradesButtons.h \
    business/include/loggedInWindow.h \
    business/include/mainWindow.h \
    business/include/pch.h \
    business/include/validatorlib.h \
    data/include/absences.h \
    data/include/admin.h \
    data/include/db.h \
    data/include/feedback.h \
    data/include/grades.h \
    data/include/user.h

FORMS += \
    presentation/gradesButtons.ui \
    presentation/loggedInWindow.ui \
    presentation/mainWindow.ui

LIBS += -L../lib/ -lvalidatorlib \
        -L../lib/ -ldatabaselib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    assets/icons/lateness.png \
    brainstorm.pro.user \
    lib/validatorlib.lib \
    lib/databaselib.lib

RESOURCES += \
    ../assets/bg.png/background.qrc \
    icons.qrc
