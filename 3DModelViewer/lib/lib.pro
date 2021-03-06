#QT += gui
QT += widgets
QT += opengl

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Axis.cpp \
    BoundingBox.cpp \
    Camera.cpp \
    Cube.cpp \
    IShapeRepository.cpp \
    Material.cpp \
    Mesh.cpp \
    Ray.cpp \
    SceneManager.cpp \
    Shape.cpp \
    ShapeBuffers.cpp \
    ShapeRenderable.cpp \
    ShapeRepository.cpp

HEADERS += \
    Axis.h \
    AxisData.h \
    BoundingBox.h \
    Camera.h \
    Cube.h \
    DuplicateIdException.h \
    IShapeRepository.h \
    Material.h \
    Mesh.h \
    Ray.h \
    SceneManager.h \
    SceneRenderer.h \
    Shape.h \
    ShapeBuffers.h \
    ShapeRenderable.h \
    ShapeRepository.h \
    UnsupportedShapeException.h \
    VertexData.h

LIBS += -lOpenGL32

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
