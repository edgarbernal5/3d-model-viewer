#include "OpenGLWidget.h"

#include "SceneManager.h"
#include "ShapeRepository.h"
#include "Shape.h"
#include "Material.h"
#include <QQuaternion>
#include <ctime>

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setMouseTracking(true);
    srand (static_cast <unsigned> (time(0)));

    m_camera.setFarPlane(100.0f);
    m_camera.setNearPlane(1.0f);
    m_camera.setFieldOfView(45.0f);

    m_camera.setPosition(QVector3D(12,12,12));
    m_camera.setTarget(QVector3D(0,0,0));
    m_camera.setUp(QVector3D(0,1,0));

    m_camera.init();
}

void OpenGLWidget::createCube(QString& cubeId)
{
    makeCurrent ();
    QString cubeType("Cube");

    Shape* shape = m_sceneManager->createShape(cubeType, cubeId);

    QVector3D randomPosition(getRandomNumber(-10.0f, 10.0f), getRandomNumber(-10.0f, 10.0f), getRandomNumber(-10.0f, 10.0f));
    shape->setPosition(randomPosition);

    Material* material = new Material();
    material->setBaseColor(QVector3D(0.5f, 1,1));
    shape->setMaterial(material);

    doneCurrent();
    update();
}

float OpenGLWidget::getRandomNumber(float min, float max)
{
    float number = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    return min + number * (max - min);
}

void OpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    auto shapeRepository = QSharedPointer<IShapeRepository> (new ShapeRepository());
    m_sceneManager.reset(new SceneManager(shapeRepository, &m_camera));

    glEnable(GL_DEPTH_TEST);

    m_timer.start(16, this);
}

void OpenGLWidget::timerEvent(QTimerEvent *)
{
    update();
}

void OpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    m_mousePressPosition = QVector2D(event->localPos());

    m_mouseButtonDown = event->button();
}

void OpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    QVector2D currentPosition = QVector2D(event->localPos());
    if (m_mouseButtonDown == Qt::RightButton){
        m_camera.rotate(currentPosition, m_mousePressPosition);
    }
    if (m_mouseButtonDown == Qt::MidButton){
        m_camera.pan(currentPosition, m_mousePressPosition);
    }
    m_mousePressPosition = currentPosition;
}

void OpenGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    QVector2D currentPosition = QVector2D(event->localPos());
    if (m_mouseButtonDown == Qt::LeftButton){
        Shape* shape = m_sceneManager->pickShape(currentPosition.x(), currentPosition.y(), width(), height());
        if (shape == nullptr){
            //m_lblStatus->setText("Nothing is selected");
            qDebug() << "Nothing is selected";
        } else{
            QString status(shape->getId());
            status.append(QString(" is selected"));
            qDebug() << status;
            //m_lblStatus->setText(status);
        }
    }
    m_mouseButtonDown = Qt::NoButton;
}

void OpenGLWidget::wheelEvent(QWheelEvent *event){
    m_camera.zoom(event->delta());
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.39f, 0.58f, 0.92f, 1.0f);

    m_sceneManager->renderAll();
    m_sceneManager->drawAxis();
}

void OpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    m_camera.setAspectRatio((float)w / h);
}
