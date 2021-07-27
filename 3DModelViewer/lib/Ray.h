#ifndef RAY_H
#define RAY_H

#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>
#include "BoundingBox.h"
struct Ray
{
public:
    Ray();

    QVector3D m_origin;
    QVector3D m_direction;

    bool intersects(BoundingBox& box);

    static Ray createFromScreenPosition(int x, int y, int width, int height, const QMatrix4x4& view, const QMatrix4x4& projection);
};

#endif // RAY_H
