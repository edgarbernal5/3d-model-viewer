#include "ShapeRepository.h"
#include "UnsupportedShapeException.h"

#include "Cube.h"

ShapeRepository::ShapeRepository()
{
}

ShapeRepository::~ShapeRepository()
{
}

QSharedPointer<Shape> ShapeRepository::get(const QString &id) const
{
    return m_shapeMap[id];
}

QSharedPointer<Shape> ShapeRepository::create(const QString &type, const QString &id)
{
    if (type == "Cube"){
        auto shape = QSharedPointer<Shape>(new Cube(id, 1.0f));
        m_shapeMap[id] = shape;

        return shape;
    }
    throw UnsupportedShapeException();
}

bool ShapeRepository::exists(const QString &id) const
{
    return m_shapeMap.find(id) != m_shapeMap.end();
}

void ShapeRepository::remove(const QString &id)
{
    m_shapeMap.remove(id);
}

QVector<QSharedPointer<Shape>> ShapeRepository::getAll()
{
    return QVector<QSharedPointer<Shape>>::fromList(m_shapeMap.values());
}
