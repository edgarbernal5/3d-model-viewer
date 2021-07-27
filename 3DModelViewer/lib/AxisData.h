#ifndef AXISDATA_H
#define AXISDATA_H

#include <QVector3D>

struct AxisData
{
    QVector3D m_position;
    QVector3D m_color;
    Q_DECL_CONSTEXPR AxisData();
    Q_DECL_CONSTEXPR explicit AxisData(const QVector3D &position, const QVector3D &color);
};
Q_DECL_CONSTEXPR inline AxisData::AxisData() {}
Q_DECL_CONSTEXPR inline AxisData::AxisData(const QVector3D &position, const QVector3D &color) : m_position(position), m_color(color) {}


#endif // AXISDATA_H
