#ifndef VERTEXDATA_H
#define VERTEXDATA_H

#include <QVector3D>

struct VertexData
{
    QVector3D m_position;
    QVector3D m_normal;
    Q_DECL_CONSTEXPR VertexData();
    Q_DECL_CONSTEXPR explicit VertexData(const QVector3D &position, const QVector3D &normal);
};
Q_DECL_CONSTEXPR inline VertexData::VertexData() {}
Q_DECL_CONSTEXPR inline VertexData::VertexData(const QVector3D &position, const QVector3D &normal) : m_position(position), m_normal(normal) {}
#endif // VERTEXDATA_H
