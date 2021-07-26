#include "OpenGLWidget.h"

#include "SceneManager.h"
#include "ShapeRepository.h"
#include "Shape.h"
#include "Material.h"
#include <QMouseEvent>
#include <QQuaternion>

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setMouseTracking(true);

    m_camera.setFarPlane(100.0f);
    m_camera.setNearPlane(1.0f);
    m_camera.setFieldOfView(45.0f);

    m_camera.setPosition(QVector3D(0,5,5));
    m_camera.setTarget(QVector3D(0,0,0));
    m_camera.setUp(QVector3D(0,1,0));

    m_camera.init();
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    auto shapeRepository = QSharedPointer<IShapeRepository> (new ShapeRepository());
    m_sceneManager.reset(new SceneManager(shapeRepository, &m_camera));

    QString cubeType("Cube");
    QString cubeId("cube1");

    Shape* shape = m_sceneManager->createShape(cubeType, cubeId);

    Material* material = new Material();
    material->setBaseColor(QVector3D(0.5f, 1,1));
    shape->setMaterial(material);

    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);

    m_timer.start(12, this);
}

void OpenGLWidget::timerEvent(QTimerEvent *)
{
    update();
}

void OpenGLWidget::mousePressEvent(QMouseEvent *e)
{
    m_mouseDown=true;
    m_mousePressPosition = QVector2D(e->localPos());
}

void OpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_mouseDown){
        QVector2D currentPosition = QVector2D(event->localPos());
        m_camera.rotate(currentPosition,m_mousePressPosition);
        m_mousePressPosition= currentPosition;
    }
}

void OpenGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_mouseDown=false;
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.39f, 0.58f, 0.92f, 1.0f);


    m_sceneManager->renderAll();
/*
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0,0,0);
    glVertex3f(6,0,0);
    glEnd();*/
}

void OpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    m_camera.setAspectRatio((float)w / h);
}
