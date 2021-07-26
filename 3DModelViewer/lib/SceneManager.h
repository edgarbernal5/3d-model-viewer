#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QString>
#include <QOpenGLShaderProgram>
#include <QSharedPointer>
#include "SceneRenderer.h"

class Shape;
class IShapeRepository;
class Camera;

class SceneManager : public SceneRenderer
{
public:
    SceneManager(QSharedPointer<IShapeRepository> shapeRepository, Camera* camera);

    void renderAll() override;
    Shape *pickShape(int x, int y); // x, y - screen mouse coords

    Shape* getShape(const QString &id);
    Shape* createShape(const QString &type, QString &id);
    void removeShape(const QString &id);

private:
    QSharedPointer<IShapeRepository> m_shapeRepository;
    Camera* m_camera;

    QOpenGLShaderProgram* m_program;
};

#endif // SCENEMANAGER_H
