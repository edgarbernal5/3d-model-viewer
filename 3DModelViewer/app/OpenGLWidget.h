#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QVector2D>
#include <QBasicTimer>
#include <QMouseEvent>
#include <QLabel>

#include "Camera.h"

class SceneManager;

class OpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGLWidget(QWidget *parent = nullptr);

    void createCube(QString& cubeId);
    void setLabel(QLabel* label);
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

    void wheelEvent(QWheelEvent *event) override;

    void timerEvent(QTimerEvent *e) override;

    QBasicTimer m_timer;
    QVector2D m_mousePressPosition;
    Camera m_camera;
    QScopedPointer<SceneManager> m_sceneManager;

    Qt::MouseButton m_mouseButtonDown = Qt::NoButton;
    QLabel* m_lblStatus;

private:
    float getRandomNumber(float min, float max);
};

#endif // OPENGLWIDGET_H
