#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QString>
#include <QOpenGLShaderProgram>
#include <QSharedPointer>
#include "SceneRenderer.h"

class Shape;
class IShapeRepository;
class Camera;
class Axis;

class SceneManager : public SceneRenderer
{
public:
    SceneManager();
    SceneManager(QSharedPointer<IShapeRepository> shapeRepository, Camera* camera);

    void renderAll() override;
    void drawAxis() override;
    Shape *pickShape(int x, int y, int width, int height);

    Shape* getShape(const QString &id);
    Shape* createShape(const QString &type, QString &id);
    void removeShape(const QString &id);

    void setCamera(Camera* camera);
protected:
    QSharedPointer<IShapeRepository> m_shapeRepository;
    Camera* m_camera;

    QOpenGLShaderProgram* m_phongProgram;
    QOpenGLShaderProgram* m_axisProgram;
    QSharedPointer<Axis> m_axis;

    void createShaders();
    virtual void createBuffersFor(Shape* shape);
};

#endif // SCENEMANAGER_H
