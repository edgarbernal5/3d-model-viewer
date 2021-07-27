#include "Ray.h"

Ray::Ray()
{

}

bool Ray::intersects(BoundingBox& box)
{
    QVector3D tMin = (box.m_min - m_origin) / m_direction;
    QVector3D tMax = (box.m_max - m_origin) / m_direction;

    QVector3D t1(std::min(tMin.x(), tMax.x()), std::min(tMin.y(), tMax.y()), std::min(tMin.z(), tMax.z()));
    QVector3D t2(std::max(tMin.x(), tMax.x()), std::max(tMin.y(), tMax.y()), std::max(tMin.z(), tMax.z()));

    float tNear = std::max(std::max(t1.x(), t1.y()), t1.z());
    float tFar = std::min(std::min(t2.x(), t2.y()), t2.z());

    return  tNear <= tFar;
}
