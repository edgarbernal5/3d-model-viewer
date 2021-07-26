#include "Mesh.h"

Mesh::Mesh(QVector<VertexData>& vertices, QVector<unsigned short>& indices)
    : m_vertices(vertices),
       m_indices(indices)
{
}


const QVector<VertexData>& Mesh::getVertices()
{
    return m_vertices;
}

const QVector<unsigned short>& Mesh::getIndices()
{
    return m_indices;
}
