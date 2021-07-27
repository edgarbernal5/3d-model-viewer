#include "Cube.h"

#include "Mesh.h"
#include <QVector>

Cube::Cube(const QString &id, float size)
    : Shape(id), m_size(size)
{
    VertexData verticesArray[] = {
        VertexData ( QVector3D{-0.5f, -0.5f, -0.5f},  QVector3D{0.0f,  0.0f, -1.0f}),
        VertexData ( QVector3D{0.5f, -0.5f, -0.5f},  QVector3D{0.0f,  0.0f, -1.0f}),
        VertexData ( QVector3D{0.5f,  0.5f, -0.5f},  QVector3D{0.0f,  0.0f, -1.0f}),
        VertexData ( QVector3D{0.5f,  0.5f, -0.5f},  QVector3D{0.0f,  0.0f, -1.0f}),
        VertexData ( QVector3D{-0.5f, 0.5f, -0.5f},  QVector3D{0.0f,  0.0f, -1.0f}),
        VertexData ( QVector3D{-0.5f, -0.5f, -0.5f},  QVector3D{0.0f,  0.0f, -1.0f}),

        VertexData ( QVector3D{-0.5f, -0.5f, 0.5f},  QVector3D{0.0f,  0.0f, 1.0f}),
        VertexData ( QVector3D{0.5f, -0.5f, 0.5f},  QVector3D{0.0f,  0.0f, 1.0f}),
        VertexData ( QVector3D{0.5f,  0.5f, 0.5f},  QVector3D{0.0f,  0.0f, 1.0f}),
        VertexData ( QVector3D{0.5f,  0.5f, 0.5f},  QVector3D{0.0f,  0.0f, 1.0f}),
        VertexData ( QVector3D{-0.5f,  0.5f, 0.5f},  QVector3D{0.0f,  0.0f, 1.0f}),
        VertexData ( QVector3D{-0.5f, -0.5f, 0.5f},  QVector3D{0.0f,  0.0f, 1.0f}),

        VertexData ( QVector3D{-0.5f,  0.5f,  0.5f},  QVector3D{-1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f,  0.5f, -0.5f},  QVector3D{-1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f, -0.5f, -0.5f},  QVector3D{-1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f, -0.5f, -0.5f},  QVector3D{-1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f, -0.5f,  0.5f},  QVector3D{-1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f,  0.5f,  0.5f},  QVector3D{-1.0f,  0.0f, 0.0f}),

        VertexData ( QVector3D{0.5f,  0.5f,  0.5f},  QVector3D{1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{0.5f,  0.5f, -0.5f},  QVector3D{1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{0.5f, -0.5f, -0.5f},  QVector3D{1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{0.5f, -0.5f, -0.5f},  QVector3D{1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{0.5f, -0.5f,  0.5f},  QVector3D{1.0f,  0.0f, 0.0f}),
        VertexData ( QVector3D{0.5f,  0.5f,  0.5f},  QVector3D{1.0f,  0.0f, 0.0f}),

        VertexData ( QVector3D{-0.5f, -0.5f, -0.5f},  QVector3D{0.0f,  -1.0f, 0.0f}),
        VertexData ( QVector3D{0.5f, -0.5f, -0.5f},  QVector3D{0.0f,  -1.0f, 0.0f}),
        VertexData ( QVector3D{0.5f, -0.5f,  0.5f},  QVector3D{0.0f,  -1.0f, 0.0f}),
        VertexData ( QVector3D{0.5f, -0.5f,  0.5f},  QVector3D{0.0f,  -1.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f, -0.5f,  0.5f},  QVector3D{0.0f,  -1.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f, -0.5f, -0.5f},  QVector3D{0.0f,  -1.0f, 0.0f}),

        VertexData ( QVector3D{-0.5f,  0.5f, -0.5f},  QVector3D{0.0f,  1.0f, 0.0f}),
        VertexData ( QVector3D{0.5f,  0.5f, -0.5f},  QVector3D{0.0f,  1.0f, 0.0f}),
        VertexData ( QVector3D{0.5f,  0.5f,  0.5f},  QVector3D{0.0f,  1.0f, 0.0f}),
        VertexData ( QVector3D{0.5f,  0.5f,  0.5f},  QVector3D{0.0f,  1.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f,  0.5f,  0.5f},  QVector3D{0.0f,  1.0f, 0.0f}),
        VertexData ( QVector3D{-0.5f,  0.5f, -0.5f},  QVector3D{0.0f,  1.0f, 0.0f})
        };

    int vertSize =sizeof(verticesArray) / sizeof(verticesArray[0]);
    QVector<VertexData> vertices(vertSize);
    qCopy(verticesArray, verticesArray + vertSize, vertices.begin());

    unsigned short indicesArray[] = {
        0,  1,  2,  3,  3,     // Face 0 - triangle strip ( v0,  v1,  v2,  v3)
        4,  4,  5,  6,  7,  7, // Face 1 - triangle strip ( v4,  v5,  v6,  v7)
        8,  8,  9, 10, 11, 11, // Face 2 - triangle strip ( v8,  v9, v10, v11)
       12, 12, 13, 14, 15, 15, // Face 3 - triangle strip (v12, v13, v14, v15)
       16, 16, 17, 18, 19, 19, // Face 4 - triangle strip (v16, v17, v18, v19)
       20, 20, 21, 22, 23      // Face 5 - triangle strip (v20, v21, v22, v23)
    };
    QVector<unsigned short> indices(34);
    qCopy(indicesArray, indicesArray + 34, indices.begin());

    m_mesh.reset(new Mesh(vertices, indices));
}

BoundingBox& Cube::getBoundingBox()
{
    m_aabb.m_max = m_position + QVector3D(1,1,1) * m_size;
    m_aabb.m_min = m_position - QVector3D(1,1,1) * m_size;

    return m_aabb;
}
