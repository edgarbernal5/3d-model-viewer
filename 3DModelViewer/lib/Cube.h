#ifndef CUBE_H
#define CUBE_H

#include <Shape.h>

class Cube : public Shape
{
public:
    Cube(const QString &id, float size);

    BoundingBox& getBoundingBox() override;
private:
    float m_size;
    BoundingBox m_aabb;
};

#endif // CUBE_H
