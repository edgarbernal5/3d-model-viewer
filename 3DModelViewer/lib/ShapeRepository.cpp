#include "ShapeRepository.h"
#include "UnsupportedShapeException.h"

#include "Cube.h"

ShapeRepository::ShapeRepository()
{
}

ShapeRepository::~ShapeRepository()
{
}

QSharedPointer<Shape> ShapeRepository::getShape(const QString &id) const
{
    return m_shapeMap[id];
}

QSharedPointer<Shape> ShapeRepository::createShape(const QString &type, QString &id)
{
    if (type == "Cube"){
        auto shape = QSharedPointer<Shape>(new Cube(id, 1.0f));
        m_shapeMap[id] = shape;

        return shape;
    }
    throw UnsupportedShapeException();
}

void ShapeRepository::removeShape(const QString &id)
{
    m_shapeMap.remove(id);
}
