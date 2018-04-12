TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    creature.cpp \
    grid.cpp \
    predator.cpp \
    prey.cpp \
    wall.cpp \
    hunger_predator.cpp \
    queen_prey.cpp \
    game.cpp

include(deployment.pri)
qtcAddDeployment()

LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"

CONFIG += c++11

HEADERS += \
    creature.h \
    grid.h \
    predator.h \
    prey.h \
    wall.h \
    hunger_predator.h \
    queen_prey.h \
    game.h
