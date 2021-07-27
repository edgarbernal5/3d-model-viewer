#include "Axis.h"

#include <QOpenGLExtraFunctions>

Axis::Axis()
{
    AxisData verticesArray[] = {
        AxisData ( QVector3D{0.0f, 0.0f, 0.0f},  QVector3D{1.0f,  0.0f, 0.0f}),
        AxisData ( QVector3D{10.0f, 0.0f, 0.0f},  QVector3D{1.0f,  0.0f, 0.0f}),

        AxisData ( QVector3D{0.0f, 0.0f, 0.0f},  QVector3D{0.0f,  1.0f, 0.0f}),
        AxisData ( QVector3D{0.0f, 10.0f, 0.0f},  QVector3D{0.0f,  1.0f, 0.0f}),

        AxisData ( QVector3D{0.0f, 0.0f, 0.0f},  QVector3D{0.0f, 0.0f, 1.0f}),
        AxisData ( QVector3D{0.0f, 0.0f, 10.0f},  QVector3D{0.0f, 0.0f, 1.0f}),
    };

    int vertSize =sizeof(verticesArray) / sizeof(verticesArray[0]);
    QVector<AxisData> vertices(vertSize);
    qCopy(verticesArray, verticesArray + vertSize, vertices.begin());

    m_verticesBuffer.create();
    m_verticesBuffer.bind();
    m_verticesBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_verticesBuffer.allocate(vertices.data(), vertices.size() * sizeof(AxisData));

    m_indicesBuffer.create();
    m_indicesBuffer.bind();
}

void Axis::render(QOpenGLShaderProgram *program){
     QOpenGLExtraFunctions *f = QOpenGLContext::currentContext()->extraFunctions();

     m_verticesBuffer.bind();
     m_indicesBuffer.bind();

    quintptr offset = 0;
     int vertexLocation = program->attributeLocation("position");
     int colorLocation = program->attributeLocation("color");
     program->enableAttributeArray(vertexLocation);
     program->enableAttributeArray(colorLocation);
     program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(AxisData));

     offset += sizeof(QVector3D);

     program->setAttributeBuffer(colorLocation, GL_FLOAT, offset, 3, sizeof(AxisData));

     f->glDrawArrays(GL_LINES, 0, 6);
}
