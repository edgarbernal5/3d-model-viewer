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

Ray Ray::createFromScreenPosition(int x, int y, int width, int height, const QMatrix4x4& view, const QMatrix4x4& projection)
{
    float dx = 2.0f * (float)x / (float)width - 1.0f;
    float dy = 2.0f * (float)y / (float)height - 1.0f;

    QMatrix4x4 viewProjection = projection * view;
    QMatrix4x4 viewProjectionInverse = viewProjection.inverted();
    QVector4D nearPoint(dx, -dy, -1, 1);

    QVector4D nearWorldPos = viewProjectionInverse * nearPoint;
    nearWorldPos.setW(1.0f / nearWorldPos.w());
    nearWorldPos.setX(nearWorldPos.x() * nearWorldPos.w());
    nearWorldPos.setY(nearWorldPos.y() * nearWorldPos.w());
    nearWorldPos.setZ(nearWorldPos.z() * nearWorldPos.w());

    QVector4D farPoint(dx, -dy, 1, 1);
    QVector4D farWorldPos = viewProjectionInverse * farPoint;
    farWorldPos.setW(1.0f / farWorldPos.w());
    farWorldPos.setX(farWorldPos.x() * farWorldPos.w());
    farWorldPos.setY(farWorldPos.y() * farWorldPos.w());
    farWorldPos.setZ(farWorldPos.z() * farWorldPos.w());

    QVector3D direction = (farWorldPos - nearWorldPos).toVector3D();
    direction.normalize();

    Ray ray;
    ray.m_direction = direction;
    ray.m_origin = nearWorldPos.toVector3D();

    return ray;
}
