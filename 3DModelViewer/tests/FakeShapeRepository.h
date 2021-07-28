#ifndef FAKESHAPEREPOSITORY_H
#define FAKESHAPEREPOSITORY_H

#include "ShapeRepository.h"

class Shape;

class FakeShapeRepository : public ShapeRepository
{
public:
    FakeShapeRepository(QVector<Shape*> shapes);
     ~FakeShapeRepository();
};

#endif // FAKESHAPEREPOSITORY_H
