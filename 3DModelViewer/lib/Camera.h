#ifndef CAMERA_H
#define CAMERA_H

#include <QMatrix4x4>
#include <QVector3D>
#include <QVector2D>
#include <QQuaternion>

class Camera
{
public:
    Camera();

    void setAspectRatio(float aspectRatio);
    void setFieldOfView(float fov);
    void setNearPlane(float nearPlane);
    void setFarPlane(float farPlane);

    void setPosition(const QVector3D& position);
    void setTarget(const QVector3D& target);
    void setUp(const QVector3D& up);

    QVector3D getPosition();

    const QMatrix4x4& getView();
    const QMatrix4x4& getProjection();

    void init();
    void rotate(QVector2D currentMousePosition, QVector2D prevMousePosition);
    void pan(QVector2D currentMousePosition, QVector2D prevMousePosition);
    void zoom(int deltaZoom);
private:
    QMatrix4x4 m_view;
    QMatrix4x4 m_projection;
    bool m_viewDirty;
    bool m_projectionDirty;

    float m_aspectRatio, m_fov, m_nearPlane, m_farPlane;

    QVector3D m_position;
    QVector3D m_target;
    QVector3D m_up;

    QVector3D m_yawPitchRoll;
};

#endif // CAMERA_H
