QT           += opengl

CONFIG       += qt
TEMPLATE      = app

DEPENDPATH   +=.
INCLUDEPATH  += /usr/include/glm \
               ../../Model

FORMS        += MyForm.ui

HEADERS      += MyForm.h  \
                MyEuler.h \
                MyColorTerra.h

SOURCES      += main.cpp    \
                MyForm.cpp  \
                MyEuler.cpp \
                MyColorTerra.cpp \
                ../../Model/model.cpp
