#ifndef SHAPE_H
#define SHAPE_H

#include <QString>
#include <QSharedPointer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLFunctions>
#include "ShapeBuffers.h"
#include "ShapeRenderable.h"

#include "BoundingBox.h"

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
    void render(QOpenGLShaderProgram *program) override;

    QVector3D getPosition();
    void setPosition(const QVector3D &position);
    QMatrix4x4 getTransformation();
    virtual BoundingBox& getBoundingBox() = 0;

    void setMaterial(QSharedPointer<Material> material);

protected:
    QString m_id;

    QSharedPointer<Mesh> m_mesh;

    QOpenGLBuffer m_verticesBuffer;
    QOpenGLBuffer m_indicesBuffer;
    QOpenGLVertexArrayObject m_vao;

    QSharedPointer<Material> m_material;
    QVector3D m_position;
};

#endif // SHAPE_H
