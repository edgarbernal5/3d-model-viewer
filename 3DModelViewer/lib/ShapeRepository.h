#ifndef SHAPEREPOSITORY_H
#define SHAPEREPOSITORY_H

#include "IShapeRepository.h"

#include <QMap>

class ShapeRepository : public IShapeRepository
{
public:
    ShapeRepository();
    ~ShapeRepository();

    QSharedPointer<Shape> get(const QString &id) const override;
    QSharedPointer<Shape> create(const QString &type, const QString &id) override;
    bool exists(const QString &id) const override;
    void remove(const QString &id) override;
    QVector<QSharedPointer<Shape>> getAll() override;

protected:
    QMap<QString, QSharedPointer<Shape>> m_shapeMap;
};

#endif // SHAPEREPOSITORY_H
