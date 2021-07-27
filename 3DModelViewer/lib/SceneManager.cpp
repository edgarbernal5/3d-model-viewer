#include "SceneManager.h"

#include "Cube.h"
#include "DuplicateIdException.h"

#include <QOpenGLExtraFunctions>
#include "IShapeRepository.h"
#include "Camera.h"
#include <QColor>
#include "Axis.h"
#include "Ray.h"

SceneManager::SceneManager(QSharedPointer<IShapeRepository> shapeRepository, Camera* camera)
    : m_shapeRepository(shapeRepository), m_camera(camera)
{
    createShaders();

    m_axis=new Axis();
}

void SceneManager::createShaders(){
    m_phongProgram = new QOpenGLShaderProgram();

    if (!m_phongProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/phong.vert"))
    {
        qDebug() << "Failed to add vertex shader" << endl;
    }

    if (!m_phongProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/phong.frag")){

        qDebug() << "Failed to add fragment shader" << endl;
    }

    if (!m_phongProgram->link()){
        qDebug() << "There was an issue linking shaders" << endl;
    }

    if (!m_phongProgram->bind())
    {
        qDebug() << "There was an issue binding shaders" << endl;
    }

    m_axisProgram = new QOpenGLShaderProgram();

    if (!m_axisProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/axis.vert"))
    {
        qDebug() << "Failed to add vertex shader" << endl;
    }

    if (!m_axisProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/axis.frag")){

        qDebug() << "Failed to add fragment shader" << endl;
    }

    if (!m_axisProgram->link()){
        qDebug() << "There was an issue linking shaders" << endl;
    }

    if (!m_axisProgram->bind())
    {
        qDebug() << "There was an issue binding shaders" << endl;
    }
}

void SceneManager::renderAll()
{
    m_phongProgram->bind();

    QVector3D lightColor(0.8f,0.8f, 0.4f);
    m_phongProgram->setUniformValue("vLightColor", lightColor);

    QVector3D lightPosition(6.8f,6.8f, 6.4f);
    m_phongProgram->setUniformValue("vLightPos", lightPosition);

    m_phongProgram->setUniformValue("vViewPos", m_camera->getPosition());

    auto shapes = m_shapeRepository->getAll();
    for(int i = 0; i < shapes.size(); ++i){
        QMatrix4x4 modelTransformation = shapes[i]->getTransformation();

        auto mvp = m_camera->getProjection() * m_camera->getView() * modelTransformation;

        m_phongProgram->setUniformValue("mvp", mvp);
        m_phongProgram->setUniformValue("model", modelTransformation);
        shapes[i]->render(m_phongProgram);
    }

    m_phongProgram->release();
}

Shape* SceneManager::pickShape(int x, int y, int width, int height)
{
    float dx = 2.0f * (float)x / (float)width - 1.0f;
    float dy = 2.0f * (float)y / (float)height - 1.0f;

    QVector4D screenPos(dx, -dy, -1, 1);
    QMatrix4x4 ProjectView =  m_camera->getProjection() * m_camera->getView();
    QMatrix4x4 viewProjectionInverse = ProjectView.inverted();
    QVector4D worldPos = viewProjectionInverse * screenPos;
    worldPos.setW(1.0f / worldPos.w());
    worldPos.setX(worldPos.x() * worldPos.w());
    worldPos.setY(worldPos.y() * worldPos.w());
    worldPos.setZ(worldPos.z() * worldPos.w());

    QVector4D screenPos2(dx, -dy, 1, 1);
    QVector4D worldPos2 = viewProjectionInverse * screenPos2;
    worldPos2.setW(1.0f / worldPos2.w());
    worldPos2.setX(worldPos2.x() * worldPos2.w());
    worldPos2.setY(worldPos2.y() * worldPos2.w());
    worldPos2.setZ(worldPos2.z() * worldPos2.w());

    QVector4D direction2 = worldPos2 - worldPos;

    QVector3D nearPoint(x, -y, -1);
    nearPoint.unproject(m_camera->getView(), m_camera->getProjection(), QRect(0,0,width,height));

    QVector3D farPoint(x, -y, 1);
    farPoint.unproject(m_camera->getView(), m_camera->getProjection(), QRect(0,0,width,height));

    QVector3D direction = farPoint - nearPoint;
    direction.normalize();

    QVector3D newDir = direction2.toVector3D();
    newDir.normalize();

    Ray ray;
    ray.m_direction = newDir;
    ray.m_origin = worldPos.toVector3D();

    auto shapes = m_shapeRepository->getAll();
    float closestBox = FLT_MAX;

    Shape* selectedShape=nullptr;
    for(int i = 0; i < shapes.size(); ++i){
        auto shape = shapes[i];
        if (ray.intersects(shape->getBoundingBox())){
            if (m_camera->getPosition().distanceToPoint(shape->getPosition()) < closestBox){
                selectedShape = shape.get();
                closestBox=m_camera->getPosition().distanceToPoint(shape->getPosition());
            }
        }
    }
    return selectedShape;
}

Shape* SceneManager::getShape(const QString &id)
{
    return m_shapeRepository->get(id).get();
}

Shape* SceneManager::createShape(const QString &type, QString &id)
{
    if (m_shapeRepository->exists(id))
        throw DuplicateIdException();

    auto shape = m_shapeRepository->create(type, id);
    shape->createBuffers(shape->getMesh());
    return shape.get();
}

void SceneManager::removeShape(const QString &id)
{
    m_shapeRepository->remove(id);
}

void SceneManager::drawAxis(){

    m_axisProgram->bind();

    auto mvp = m_camera->getProjection() * m_camera->getView();
    m_axisProgram->setUniformValue("mvp", mvp);

    m_axis->render(m_axisProgram);

    m_axisProgram->release();
}
