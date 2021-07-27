#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <QVector3D>

struct BoundingBox
{
public:
    BoundingBox();
    BoundingBox( QVector3D min, QVector3D max);
    QVector3D m_min, m_max;
};

#endif // BOUNDINGBOX_H
