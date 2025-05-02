QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminwindow.cpp \
    bookcreatewindow.cpp \
    borrowreturnwindow.cpp \
    dashboardwindow.cpp \
    generatereportswindow.cpp \
    loginwindow.cpp \
    main.cpp \
    viewbookswindow.cpp

HEADERS += \
    adminwindow.h \
    bookcreatewindow.h \
    borrowreturnwindow.h \
    dashboardwindow.h \
    generatereportswindow.h \
    loginwindow.h \
    viewbookswindow.h

FORMS += \
    adminwindow.ui \
    bookcreatewindow.ui \
    borrowreturnwindow.ui \
    dashboardwindow.ui \
    generatereportswindow.ui \
    loginwindow.ui \
    viewbookswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
