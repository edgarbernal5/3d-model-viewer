#include "SceneManager.h"

#include "Cube.h"
#include "UnsupportedShapeException.h"

SceneManager::SceneManager()
{
}

void SceneManager::renderAll()
{

}

Shape* SceneManager::pickShape(int x, int y)
{
    return nullptr;
}

Shape* SceneManager::getShape(const QString &id)
{
    return nullptr;
}

Shape* SceneManager::createShape(const QString &type, QString &id)
{
    if (type == "Cube"){
        return new Cube(id, 1.0f);
    }
    return nullptr;
}

void SceneManager::removeShape(const QString &id)
{

}
