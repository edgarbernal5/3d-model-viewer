#ifndef SHAPEREPOSITORY_H
#define SHAPEREPOSITORY_H

#include "IShapeRepository.h"

#include <QMap>

class ShapeRepository : public IShapeRepository
{
public:
    ShapeRepository();
    ~ShapeRepository();

    QSharedPointer<Shape> getShape(const QString &id) const override;
    QSharedPointer<Shape> createShape(const QString &type, QString &id) override;
    void removeShape(const QString &id) override;

protected:
    QMap<QString, QSharedPointer<Shape>> m_shapeMap;
};

#endif // SHAPEREPOSITORY_H
