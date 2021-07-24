#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QString>

class Shape;

class SceneManager
{
public:
    SceneManager();

    void renderAll();
    Shape *pickShape(int x, int y); // x, y - screen mouse coords

    Shape* getShape(const QString &id);
    Shape* createShape(const QString &type, QString &id);
    void removeShape(const QString &id);
};

#endif // SCENEMANAGER_H
