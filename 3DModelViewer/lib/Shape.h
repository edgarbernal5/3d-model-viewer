#ifndef SHAPE_H
#define SHAPE_H

#include <QString>
#include <QSharedPointer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions>
#include "ShapeBuffers.h"
#include "ShapeRenderable.h"

class Mesh;
class Material;

class Shape : public ShapeBuffers, public ShapeRenderable, protected QOpenGLFunctions
{
public:
    Shape(const QString &id);
    virtual ~Shape();

    const QString& getId() const;
    Mesh* getMesh() const;

    void createBuffers(Mesh* mesh) override;
    QOpenGLBuffer& getVerticesBuffer() override;
    QOpenGLVertexArrayObject& getIndicesBuffer() override;

    void render(QOpenGLShaderProgram *program) override;

    void setMaterial(Material* material);
protected:
    QString m_id;

    QSharedPointer<Mesh> m_mesh;

    QOpenGLBuffer m_verticesBuffer;
    QOpenGLVertexArrayObject m_indicesBuffer;

    Material* m_material;
};

#endif // SHAPE_H
