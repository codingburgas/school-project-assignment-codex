QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/loggedInWindow.cpp \
    src/loggedInWindowAdmin.cpp \
    src/db.cpp \
    src/mainWindow.cpp \
    src/main.cpp

HEADERS += \
    include/db.h \
    include/mainWindow.h \
    include/loggedInWindow.h \
    include/loggedInWindowAdmin.h \
    include/pch.h

FORMS += \
    forms/mainWindow.ui \
    forms/loggedInWindow.ui \
    forms/loggedInWindowAdmin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    brainstorm.pro.user
