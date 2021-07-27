#ifndef RAY_H
#define RAY_H

#include <QVector3D>
#include "BoundingBox.h"
struct Ray
{
public:
    Ray();

    QVector3D m_origin;
    QVector3D m_direction;

    bool intersects(BoundingBox& box);
};

#endif // RAY_H
