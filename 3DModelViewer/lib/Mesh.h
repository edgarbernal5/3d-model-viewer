#ifndef MESH_H
#define MESH_H

#include <QVector>
#include <QVector3D>
#include <QVector2D>

#include "VertexData.h"

class Mesh
{
public:
    Mesh(QVector<VertexData>& vertices, QVector<unsigned short>& indices);

    const QVector<VertexData>& getVertices();
    const QVector<unsigned short>& getIndices();

private:
    QVector<VertexData> m_vertices;
    QVector<unsigned short> m_indices;
};

#endif // MESH_H
