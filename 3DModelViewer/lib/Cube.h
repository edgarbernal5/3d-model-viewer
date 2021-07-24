#ifndef CUBE_H
#define CUBE_H

#include <Shape.h>

class Cube : public Shape
{
public:
    Cube(const QString &id, float size);

private:
    float m_size;
};

#endif // CUBE_H
