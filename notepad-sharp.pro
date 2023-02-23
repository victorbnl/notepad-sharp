QT += core gui widgets printsupport

SOURCES += \
    src/closedialog.cpp \
    src/editor.cpp \
    src/editortabs.cpp \
    src/findform.cpp \
    src/main.cpp \
    src/notepad.cpp \
    src/statusbar.cpp \
    src/textfile.cpp

HEADERS += \
    include/closedialog.h \
    include/editor.h \
    include/editortabs.h \
    include/findform.h \
    include/notepad.h \
    include/statusbar.h \
    include/textfile.h

FORMS += \
    forms/closedialog.ui \
    forms/findform.ui \
    forms/notepad.ui

RESOURCES += \
    icons/icons.qrc

TRANSLATIONS += \
    i18n/fr_FR.ts

INCLUDEPATH += include

CONFIG += lrelease embed_translations
