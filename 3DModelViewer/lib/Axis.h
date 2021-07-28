#ifndef AXIS_H
#define AXIS_H

#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include "AxisData.h"

class Axis
{
public:
    Axis();

    void render(QOpenGLShaderProgram *program);
private:
    QOpenGLBuffer m_verticesBuffer;
    QOpenGLVertexArrayObject m_vertexArrayObj;
};

#endif // AXIS_H
