#include "Cube.h"

#include "Mesh.h"
#include <QVector>

Cube::Cube(const QString &id, float size)
    : Shape(id), m_size(size)
{
    VertexData verticesArray[] = {
        VertexData ( QVector3D{0.5f, 0.5f, 0.5f},  QVector3D{0.0f,  0.0f, 1.0f}),
        VertexData ( QVector3D{-0.5f, 0.5f, 0.5f},  QVector3D{0.0f,  0.0f, 1.0f}),
        VertexData ( QVector3D{-0.5f, -0.5f, 0.5f},  QVector3D{0.0f,  0.0f, 1.0f}),
        VertexData ( QVector3D{0.5f, -0.5f, 0.5f},  QVector3D{0.0f,  0.0f, 1.0f}),

        VertexData ( QVector3D{0.5f, 0.5f, 0.5f},  QVector3D{1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{0.5f, -0.5f, 0.5f},  QVector3D{1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{0.5f, -0.5f, -0.5f},  QVector3D{1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{0.5f, 0.5f, -0.5f},  QVector3D{1.0f,  0.0f, 0.0f}),

        VertexData ( QVector3D{0.5f, 0.5f, 0.5f},  QVector3D{0.0f,  1.0f, 0.0f}),
        VertexData ( QVector3D{0.5f, 0.5f, -0.5f},  QVector3D{0.0f,  1.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f, 0.5f, -0.5f},  QVector3D{0.0f,  1.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f, 0.5f, 0.5f},  QVector3D{0.0f,  1.0f, 0.0f}),

        VertexData ( QVector3D{-0.5f, 0.5f, 0.5f},  QVector3D{-1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f, 0.5f, -0.5f},  QVector3D{-1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f, -0.5f, -0.5f},  QVector3D{-1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f, -0.5f, 0.5f},  QVector3D{-1.0f,  0.0f, 0.0f}),

        VertexData ( QVector3D{-0.5f, -0.5f, -0.5f},  QVector3D{0.0f, -1.0f, 0.0f}),
        VertexData ( QVector3D{0.5f, -0.5f, -0.5f},  QVector3D{0.0f, -1.0f, 0.0f}),
        VertexData ( QVector3D{0.5f, -0.5f, 0.5f},  QVector3D{0.0f, -1.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f, -0.5f, 0.5f},  QVector3D{0.0f, -1.0f, 0.0f}),

        VertexData ( QVector3D{0.5f, -0.5f, -0.5f},  QVector3D{0.0f, 0.0f, -1.0f}),
        VertexData ( QVector3D{-0.5f, -0.5f, -0.5f},  QVector3D{0.0f, 0.0f, -1.0f}),
        VertexData ( QVector3D{-0.5f, 0.5f, -0.5f},  QVector3D{0.0f, 0.0f, -1.0f}),
        VertexData ( QVector3D{0.5f, 0.5f, -0.5f},  QVector3D{0.0f, 0.0f, -1.0f}),
    };

    int vertSize =sizeof(verticesArray) / sizeof(verticesArray[0]);
    QVector<VertexData> vertices(vertSize);
    qCopy(verticesArray, verticesArray + vertSize, vertices.begin());

   unsigned short indicesArray[] = {
        0, 1, 2,   2, 3, 0,
        4, 5, 6,   6, 7, 4,
        8, 9,10,  10,11, 8,
        12,13,14,  14,15,12,
        16,17,18,  18,19,16,
        20,21,22,  22,23,20
    };
    int indicesSize =sizeof(indicesArray) / sizeof(indicesArray[0]);
    QVector<unsigned short> indices(indicesSize);
    qCopy(indicesArray, indicesArray + indicesSize, indices.begin());

    m_mesh.reset(new Mesh(vertices, indices));
}

BoundingBox& Cube::getBoundingBox()
{
    m_aabb.m_max = m_position + QVector3D(1,1,1) * m_size * 0.5f;
    m_aabb.m_min = m_position - QVector3D(1,1,1) * m_size * 0.5f;

    return m_aabb;
}
