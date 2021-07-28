#ifndef TST_SCENEMANAGER_H
#define TST_SCENEMANAGER_H

#include <QtTest>

#include "SceneManager.h"

#include "Shape.h"

class TestSceneManager : public SceneManager
{
public:
    TestSceneManager(QSharedPointer<IShapeRepository> shapeRepository);

protected:
    void createBuffersFor(Shape* shape) override;
};

class SceneManagerShould : public QObject
{
    Q_OBJECT

public:
    SceneManagerShould();
    ~SceneManagerShould();

private slots:
    void cannotCreateCubeWithSameId();
    void notPickingShapesOnEmptyScene();
    void shapeIsSelectedByPicking();
    void pickClosestShape();
    void notPickingShapeWhenRayDontIntersects();
};

#endif // TST_SCENEMANAGER_H

