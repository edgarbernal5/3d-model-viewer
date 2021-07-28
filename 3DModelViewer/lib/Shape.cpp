#include "Shape.h"
#include <QDebug>
#include <QOpenGLExtraFunctions>
#include "Mesh.h"
#include "Material.h"

Shape::Shape(const QString &id)
    : m_id(id)
{
}

Shape::~Shape()
{
    qDebug() << "Deallocating shape, id = " << m_id << endl;
}

const QString& Shape::getId() const
{
    return m_id;
}

Mesh* Shape::getMesh() const
{
    return m_mesh.get();
}

void Shape::createBuffers(Mesh* mesh)
{
    m_vao.create();
    m_vao.bind();

    m_verticesBuffer = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    m_verticesBuffer.create();
    m_verticesBuffer.bind();
    m_verticesBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_verticesBuffer.allocate(mesh->getVertices().data(), mesh->getVertices().size() * sizeof(VertexData));

    m_indicesBuffer = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    m_indicesBuffer.create();
    m_indicesBuffer.bind();
    m_indicesBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_indicesBuffer.allocate(mesh->getIndices().data(), mesh->getIndices().size() * sizeof(unsigned short));

    m_vao.release();
}

void Shape::render(QOpenGLShaderProgram *program){

    QOpenGLExtraFunctions *f = QOpenGLContext::currentContext()->extraFunctions();

    m_vao.bind();
    program->setUniformValue("vBaseColor", m_material->getBaseColor());
    program->setUniformValue("vAmbientColor", m_material->getAmbientColor());
    program->setUniformValue("vDiffuseColor", m_material->getDiffuseColor());
    program->setUniformValue("vSpecularColor", m_material->getSpecularColor());
    program->setUniformValue("fShininess", m_material->getShininess());

    m_verticesBuffer.bind();

    quintptr offset = 0;
    int vertexLocation = program->attributeLocation("position");
    int normalLocation = program->attributeLocation("normal");
    program->enableAttributeArray(vertexLocation);
    program->enableAttributeArray(normalLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);
    program->setAttributeBuffer(normalLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    f->glDrawElements(GL_TRIANGLES, m_mesh->getIndices().size(), GL_UNSIGNED_SHORT, 0);

    m_vao.release();
}

void Shape::setMaterial(QSharedPointer<Material> material)
{
    m_material = material;
}

QMatrix4x4 Shape::getTransformation()
{
    QMatrix4x4 modelMatrix;
    modelMatrix.setToIdentity();
    modelMatrix.translate(m_position);
    return modelMatrix;
}

QVector3D Shape::getPosition()
{
    return m_position;
}

void Shape::setPosition(const QVector3D &position)
{
    m_position = position;
}


