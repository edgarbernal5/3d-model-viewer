#ifndef ISHAPEREPOSITORY_H
#define ISHAPEREPOSITORY_H

#include <QString>
#include <QSharedPointer>
#include <QVector>

class Shape;

class IShapeRepository
{
public:
    IShapeRepository();
    virtual ~IShapeRepository();

    virtual QSharedPointer<Shape> get(const QString &id) const = 0;
    virtual QSharedPointer<Shape> create(const QString &type, const QString &id) = 0;
    virtual bool exists(const QString &id) const = 0;
    virtual void remove(const QString &id) = 0;
    virtual QVector<QSharedPointer<Shape>> getAll() = 0;
};

#endif // ISHAPEREPOSITORY_H
