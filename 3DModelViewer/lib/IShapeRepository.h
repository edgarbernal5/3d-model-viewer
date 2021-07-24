#ifndef ISHAPEREPOSITORY_H
#define ISHAPEREPOSITORY_H

#include <QString>
#include <QSharedPointer>

class Shape;

class IShapeRepository
{
public:
    IShapeRepository();
    virtual ~IShapeRepository();

    virtual QSharedPointer<Shape> getShape(const QString &id) const = 0;
    virtual QSharedPointer<Shape> createShape(const QString &type, QString &id) = 0;
    virtual void removeShape(const QString &id) = 0;
};

#endif // ISHAPEREPOSITORY_H
