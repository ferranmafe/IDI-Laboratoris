TEMPLATE    = app
QT         += opengl

INCLUDEPATH +=  /usr/include/glm \
                ../../Model

FORMS += MyForm.ui

HEADERS += MyForm.h MyGLWidget.h MyColorTerra.h

SOURCES += main.cpp MyForm.cpp \
        MyGLWidget.cpp \
        ../../Model/model.cpp \
        MyColorTerra.cpp
