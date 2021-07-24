#ifndef SHAPE_H
#define SHAPE_H

#include <QString>

class Shape
{
public:
    Shape(const QString &id);
    virtual ~Shape();

    const QString& getId() const;

protected:
    QString m_id;
};

#endif // SHAPE_H
