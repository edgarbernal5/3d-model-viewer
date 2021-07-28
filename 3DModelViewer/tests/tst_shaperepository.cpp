#include "tst_shaperepository.h"

#include "Shape.h"
#include "ShapeRepository.h"
#include "UnsupportedShapeException.h"

#include "Cube.h"
#include "FakeShapeRepository.h"

ShapeRepositoryShould::ShapeRepositoryShould()
{
}

ShapeRepositoryShould::~ShapeRepositoryShould()
{
}

void ShapeRepositoryShould::createCubeShape()
{
    QString shapeType("Cube");
    QString shapeId("cube1");

    ShapeRepository repository;
    auto cube = repository.create(shapeType, shapeId);

    QVERIFY2(cube != nullptr, "Cannot create a cube");
    QCOMPARE(cube->getId(), QString("cube1"));
    QCOMPARE(repository.getAll().size(), 1);
}

void ShapeRepositoryShould::getShapeGivenId()
{
    QString shapeType("Cube");
    QString shapeId1("cube1");
    QString shapeId2("cube2");

    FakeShapeRepository repository({ new Cube(shapeId2, 1.0f), new Cube(shapeId1, 1.0f)});

    auto cube = repository.get(shapeId1);

    QVERIFY2(cube != nullptr, "Cannot get cube given its id");
    QCOMPARE(cube->getId(), QString("cube1"));
}

void ShapeRepositoryShould::returnEmptyOnInexistentShape(){
    QString shapeId("cube1");
    QString shapeId2("cube2");

    FakeShapeRepository repository({ new Cube(shapeId, 1.0f)});

    auto cube = repository.get(shapeId2);

    QVERIFY2(cube == nullptr, "There is not a cube with that id");
}

void ShapeRepositoryShould::removeShapeGivenId()
{
    QString shapeId1("cube1");
    QString shapeId2("cube2");

    FakeShapeRepository repository({ new Cube(shapeId2, 1.0f), new Cube(shapeId1, 1.0f)});

    repository.remove(shapeId2);
    auto emptyCube = repository.get(shapeId2);

    QVERIFY2(emptyCube == nullptr, "There is an issue removing shape");
    QCOMPARE(repository.getAll().size(), 1);
}

void ShapeRepositoryShould::cannotCreateUnsupportedShape()
{
    ShapeRepository repository;
    QString shapeType("Sphere");
    QString shapeId("sphere1");

    QVERIFY_EXCEPTION_THROWN(repository.create(shapeType, shapeId), UnsupportedShapeException);
}

//QTEST_APPLESS_MAIN(ShapeRepositoryShould)

//#include "tst_shaperepository.moc"
