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
    m_verticesBuffer.create();
    m_verticesBuffer.bind();
    m_verticesBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_verticesBuffer.allocate(mesh->getVertices().data(), mesh->getVertices().size() * sizeof(VertexData));

    m_indicesBuffer.create();
    m_indicesBuffer.bind();
   // m_indicesBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    //m_indicesBuffer.allocate(mesh->getIndices().data(), mesh->getIndices().size() * sizeof(unsigned short));
}

QOpenGLBuffer& Shape::getVerticesBuffer()
{
    return m_verticesBuffer;
}

QOpenGLVertexArrayObject& Shape::getIndicesBuffer()
{
    return m_indicesBuffer;
}

void Shape::render(QOpenGLShaderProgram *program){

    QOpenGLExtraFunctions *f = QOpenGLContext::currentContext()->extraFunctions();

    program->setUniformValue("vBaseColor", m_material->getBaseColor());
    program->setUniformValue("vAmbientColor", m_material->getAmbientColor());
    program->setUniformValue("vDiffuseColor", m_material->getDiffuseColor());
    program->setUniformValue("vSpecularColor", m_material->getSpecularColor());
    program->setUniformValue("shininess", 128.0f);

    m_verticesBuffer.bind();
    m_indicesBuffer.bind();

    quintptr offset = 0;
    int vertexLocation = program->attributeLocation("position");
    int normalLocation = program->attributeLocation("normal");
    program->enableAttributeArray(vertexLocation);
    program->enableAttributeArray(normalLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);

    program->setAttributeBuffer(normalLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    f->glDrawArrays(GL_TRIANGLES, 0, m_mesh->getVertices().size());

    //m_verticesBuffer.release();
    //m_indicesBuffer.release();
}

void Shape::setMaterial(Material* material)
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
void Shape::setPosition(QVector3D &position)
{
    m_position = position;
}


