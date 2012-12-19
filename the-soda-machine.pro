QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sodamac
TEMPLATE = app

OBJECTS_DIR = build/objects
MOC_DIR = build/moc
UI_DIR = build/ui

SOURCES += src/main.cpp \
        src/sodamachine.cpp \
        src/nosoda.cpp \
    src/await.cpp \
    src/amountnotfulfilled.cpp \
    src/poweredon.cpp
#\
    #src/state.cpp

HEADERS += src/sodamachine.h \
        src/nosoda.h \
    src/await.h \
    src/amountnotfulfilled.h \
    src/poweredon.h \
    src/state.h

FORMS += src/ui/sodamachine.ui
