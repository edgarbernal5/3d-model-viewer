#ifndef TST_SHAPEREPOSITORY_H
#define TST_SHAPEREPOSITORY_H

#include <QtTest>

#include "ShapeRepository.h"

class Shape;

class FakeShapeRepository : public ShapeRepository
{
public:
    FakeShapeRepository(QVector<Shape*> shapes);
     ~FakeShapeRepository();
};

class TestShapeRepository : public QObject
{
    Q_OBJECT

public:
    TestShapeRepository();
    ~TestShapeRepository();

private slots:
    void createCubeShape();
    void getShapeGivenId();
    void returnEmptyOnInexistentShape();
    void removeShapeGivenId();
    void cannotCreateUnsupportedShape();
};


#endif // TST_SHAPEREPOSITORY_H
