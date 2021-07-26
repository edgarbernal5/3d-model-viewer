#include "SceneManager.h"

#include "Cube.h"
#include "DuplicateIdException.h"

#include "IShapeRepository.h"
#include "Camera.h"
#include <QColor>

SceneManager::SceneManager(QSharedPointer<IShapeRepository> shapeRepository, Camera* camera)
    : m_shapeRepository(shapeRepository), m_camera(camera)
{
    m_program = new QOpenGLShaderProgram();

    if (!m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/vertexShader.vert"))
    {
        qDebug() << "Failed to add vertex shader" << endl;
    }

    if (!m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragShader.frag")){

        qDebug() << "Failed to add fragment shader" << endl;
    }

    if (!m_program->link()){
        qDebug() << "There was an issue linking shaders" << endl;
    }
    if (!m_program->bind())
    {
        qDebug() << "There was an issue binding shaders" << endl;
    }
}

void SceneManager::renderAll()
{
    m_program->bind();

    QVector3D lightColor(0.8f,0.8f, 0.4f);
    m_program->setUniformValue("vLightColor", lightColor);

    QVector3D lightPosition(6.8f,6.8f, 6.4f);
    m_program->setUniformValue("vLightPos", lightPosition);

    m_program->setUniformValue("vViewPos", m_camera->getPosition());

    auto shapes = m_shapeRepository->getAll();
    for(int i = 0; i < shapes.size(); ++i){
        QMatrix4x4 model;
        model.setToIdentity();

        auto mvp = m_camera->getProjection() * m_camera->getView() * model;

        m_program->setUniformValue("mvp", mvp);
        m_program->setUniformValue("model", model);
        shapes[i]->render(m_program);
    }

    m_program->release();
}

Shape* SceneManager::pickShape(int x, int y)
{
    return nullptr;
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
