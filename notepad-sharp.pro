QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    closedialog.cpp \
    editor.cpp \
    editortabs.cpp \
    main.cpp \
    notepad.cpp \
    textfile.cpp

HEADERS += \
    closedialog.h \
    editor.h \
    editortabs.h \
    notepad.h \
    textfile.h

FORMS += \
    closedialog.ui \
    notepad.ui

CONFIG += lrelease

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
