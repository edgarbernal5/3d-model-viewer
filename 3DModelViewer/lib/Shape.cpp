#include "Shape.h"
#include <QDebug>

Shape::Shape(const QString &id)
    : m_id(id)
{
}

Shape::~Shape()
{
    qDebug() << "Deallocating shape, id = " << m_id << endl;
}

const QString& Shape::getId() const
{
    return m_id;
}
