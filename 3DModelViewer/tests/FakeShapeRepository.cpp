#include "FakeShapeRepository.h"

#include "Shape.h"

FakeShapeRepository::FakeShapeRepository(QVector<Shape*> shapes)
{
    for(int i = 0; i < shapes.size(); ++i)
    {
        m_shapeMap[shapes[i]->getId()] = QSharedPointer<Shape>(shapes[i]);
    }
}

FakeShapeRepository::~FakeShapeRepository()
{
}
