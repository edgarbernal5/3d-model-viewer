#include "tst_scenemanager.h"
#include "ShapeRepository.h"

#include "DuplicateIdException.h"
#include "Camera.h"
#include "FakeShapeRepository.h"
#include "Cube.h"

TestSceneManager::TestSceneManager(QSharedPointer<IShapeRepository> shapeRepository)
{
    m_shapeRepository = shapeRepository;
}

void TestSceneManager::createBuffersFor(Shape* shape){

}

SceneManagerShould::SceneManagerShould()
{
}

SceneManagerShould::~SceneManagerShould()
{
}

void SceneManagerShould::cannotCreateCubeWithSameId()
{
    TestSceneManager sceneManager(QSharedPointer<IShapeRepository>(new ShapeRepository()));
    QString shapeType("Cube");
    QString shapeId("cube1");
    sceneManager.createShape(shapeType, shapeId);

    QVERIFY_EXCEPTION_THROWN(sceneManager.createShape(shapeType, shapeId), DuplicateIdException);
}

void SceneManagerShould::notPickingShapesOnEmptyScene()
{
    int viewportWidth = 800;
    int viewportHeight = 600;

    Camera camera;
    camera.setFarPlane(100.0f);
    camera.setNearPlane(1.0f);
    camera.setFieldOfView(45.0f);
    camera.setAspectRatio((float)viewportWidth / viewportHeight);

    camera.setPosition(QVector3D(12,12,12));
    camera.setTarget(QVector3D(0,0,0));
    camera.setUp(QVector3D(0,1,0));
    camera.init();

    TestSceneManager sceneManager(QSharedPointer<IShapeRepository>(new FakeShapeRepository({})));
    sceneManager.setCamera(&camera);

    Shape* selectedShape = sceneManager.pickShape(400, 300, viewportWidth, viewportHeight);

    QVERIFY2(selectedShape == nullptr, "Error picking shape on empty scene");
}

void SceneManagerShould::shapeIsSelectedByPicking()
{
    int viewportWidth = 800;
    int viewportHeight = 600;

    Camera camera;
    camera.setFarPlane(100.0f);
    camera.setNearPlane(1.0f);
    camera.setFieldOfView(45.0f);
    camera.setAspectRatio((float)viewportWidth / viewportHeight);

    camera.setPosition(QVector3D(12,12,12));
    camera.setTarget(QVector3D(0,0,0));
    camera.setUp(QVector3D(0,1,0));
    camera.init();

    QString shapeId1("cube1");

    Cube* cube1 = new Cube(shapeId1, 1.0f);
    cube1->setPosition(QVector3D(0,0,0));

    TestSceneManager sceneManager(QSharedPointer<IShapeRepository>(new FakeShapeRepository({cube1})));
    sceneManager.setCamera(&camera);

    Shape* selectedShape = sceneManager.pickShape(400, 300, viewportWidth, viewportHeight);

    QVERIFY2(selectedShape != nullptr, "Error picking shape");
}

void SceneManagerShould::pickClosestShape()
{
    int viewportWidth = 800;
    int viewportHeight = 600;

    Camera camera;
    camera.setFarPlane(100.0f);
    camera.setNearPlane(1.0f);
    camera.setFieldOfView(45.0f);
    camera.setAspectRatio((float)viewportWidth / viewportHeight);

    camera.setPosition(QVector3D(0,12,12));
    camera.setTarget(QVector3D(0,0,0));
    camera.setUp(QVector3D(0,1,0));
    camera.init();

    QString shapeId1("cube1");
    QString shapeId2("cube2");
    Cube* cube1 = new Cube(shapeId1, 1.0f);
    cube1->setPosition(QVector3D(0,0,0));

    Cube* cube2 = new Cube(shapeId2, 1.0f);
    cube2->setPosition(QVector3D(0,0,0.5f));

    TestSceneManager sceneManager(QSharedPointer<IShapeRepository>(new FakeShapeRepository({cube1, cube2})));
    sceneManager.setCamera(&camera);

    Shape* selectedShape = sceneManager.pickShape(400,300,viewportWidth, viewportHeight);

    QVERIFY2(selectedShape != nullptr, "Error picking shape");
    QCOMPARE(selectedShape->getId(), QString("cube2"));
}



void SceneManagerShould::notPickingShapeWhenRayDontIntersects()
{
    int viewportWidth = 800;
    int viewportHeight = 600;

    Camera camera;
    camera.setFarPlane(100.0f);
    camera.setNearPlane(1.0f);
    camera.setFieldOfView(45.0f);
    camera.setAspectRatio((float)viewportWidth / viewportHeight);

    camera.setPosition(QVector3D(12,12,12));
    camera.setTarget(QVector3D(0,0,0));
    camera.setUp(QVector3D(0,1,0));
    camera.init();

    QString shapeId1("cube1");

    Cube* cube1 = new Cube(shapeId1, 1.0f);
    cube1->setPosition(QVector3D(0,0,0));

    TestSceneManager sceneManager(QSharedPointer<IShapeRepository>(new FakeShapeRepository({cube1})));
    sceneManager.setCamera(&camera);

    Shape* selectedShape = sceneManager.pickShape(0, 0, viewportWidth, viewportHeight);

    QVERIFY2(selectedShape == nullptr, "Error on shape intersection");
}
