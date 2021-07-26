#include "tst_scenemanager.h"
#include "ShapeRepository.h"

#include "DuplicateIdException.h"
#include "Camera.h"

TestSceneManager::TestSceneManager()
{

}

TestSceneManager::~TestSceneManager()
{

}

void TestSceneManager::cannotCreateCubeWithSameId()
{
    Camera camera;
    SceneManager sceneManager(QSharedPointer<IShapeRepository>(new ShapeRepository()), &camera);
    QString shapeType("Cube");
    QString shapeId("cube1");
    sceneManager.createShape(shapeType, shapeId);

    QVERIFY_EXCEPTION_THROWN(sceneManager.createShape(shapeType, shapeId), DuplicateIdException);
}

//QTEST_APPLESS_MAIN(TestSceneManager)

//#include "tst_scenemanager.moc"
