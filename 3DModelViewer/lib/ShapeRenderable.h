#ifndef SHAPERENDERABLE_H
#define SHAPERENDERABLE_H

#include <QOpenGLShaderProgram>

class ShapeRenderable
{
public:
    ShapeRenderable();
    virtual ~ShapeRenderable();

    virtual void render(QOpenGLShaderProgram *program) = 0;
};

#endif // SHAPERENDERABLE_H
