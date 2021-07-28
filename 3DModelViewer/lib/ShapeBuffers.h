#ifndef SHAPEBUFFERS_H
#define SHAPEBUFFERS_H

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class Mesh;

class ShapeBuffers
{
public:
    ShapeBuffers();
    virtual ~ShapeBuffers();

    virtual void createBuffers(Mesh* mesh) = 0;

};

#endif // SHAPEBUFFERS_H
