QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Cube.cpp \
    IShapeRepository.cpp \
    Material.cpp \
    Mesh.cpp \
    SceneManager.cpp \
    Shape.cpp \
    ShapeRepository.cpp

HEADERS += \
    Cube.h \
    DuplicateIdException.h \
    IShapeRepository.h \
    Material.h \
    Mesh.h \
    SceneManager.h \
    Shape.h \
    ShapeRepository.h \
    UnsupportedShapeException.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
