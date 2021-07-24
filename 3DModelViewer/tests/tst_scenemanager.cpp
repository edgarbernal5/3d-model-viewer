#include "tst_scenemanager.h"

TestSceneManager::TestSceneManager()
{

}

TestSceneManager::~TestSceneManager()
{

}

void TestSceneManager::createCubeShape()
{
    SceneManager sceneManager;
    QString shapeType("Cube");
    QString shapeId("cube1");
    auto cube = sceneManager.createShape(shapeType, shapeId);

    QVERIFY2(cube != nullptr, "Cannot create cube");
    QCOMPARE(cube->getId(), QString("cube1"));
}

void TestSceneManager::cannotCreateCubeWithSameId()
{
    /*SceneManager sceneManager;
    QString shapeType("Cube");
    QString shapeId("cube1");
    sceneManager.createShape(shapeType, shapeId);
    auto secondCube = sceneManager.createShape(shapeType, shapeId);

    QVERIFY2(secondCube == nullptr, "Cannot create cube");*/
}

//QTEST_APPLESS_MAIN(TestSceneManager)

//#include "tst_scenemanager.moc"
