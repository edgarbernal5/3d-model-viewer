#ifndef TST_SCENEMANAGER_H
#define TST_SCENEMANAGER_H

#include <QtTest>

#include "SceneManager.h"

#include "Shape.h"

class TestSceneManager : public QObject
{
    Q_OBJECT

public:
    TestSceneManager();
    ~TestSceneManager();

private slots:
    void cannotCreateCubeWithSameId();
};

#endif // TST_SCENEMANAGER_H

