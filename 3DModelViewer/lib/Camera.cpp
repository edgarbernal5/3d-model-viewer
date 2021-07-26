#include "Camera.h"

Camera::Camera()
{

}

void Camera::setAspectRatio(float aspectRatio){
    m_aspectRatio=aspectRatio;
     m_projectionDirty=true;
}

void Camera::setFieldOfView(float fov)
{
    m_fov=fov;
    m_projectionDirty=true;
}

void Camera::setNearPlane(float nearPlane)
{
    m_nearPlane=nearPlane;
    m_projectionDirty=true;
}

void Camera::setFarPlane(float farPlane)
{
    m_farPlane=farPlane;
    m_projectionDirty=true;
}

void Camera::setPosition(const QVector3D& position)
{
    m_position=position;
    m_viewDirty=true;
}
void Camera::setTarget(const QVector3D& target)
{
    m_target=target;
    m_viewDirty=true;
}

void Camera::setUp(const QVector3D& up)
{
    m_up=up;
    m_viewDirty=true;
}

const QMatrix4x4& Camera::getView()
{
    if (m_viewDirty){
        m_viewDirty=false;
        m_view.setToIdentity();
        m_view.lookAt(m_position, m_target, m_up);
    }
    return m_view;
}

const QMatrix4x4& Camera::getProjection()
{
    if (m_projectionDirty){
        m_projectionDirty=false;
        m_projection.setToIdentity();
        m_projection.perspective(m_fov, m_aspectRatio, m_nearPlane, m_farPlane);
    }
    return m_projection;
}


void Camera::rotate (QVector2D currentMousePosition, QVector2D prevMousePosition)
{
    QVector2D diff = currentMousePosition - prevMousePosition;
    QVector3D angles = QVector3D(diff.y(), diff.x(), 0.0);

    m_yawPitchRoll += angles;
    QQuaternion rotation = QQuaternion::fromEulerAngles(m_yawPitchRoll.x(),m_yawPitchRoll.y(),m_yawPitchRoll.z());

    float distance = (m_position - m_target).length();
    QVector3D translation(0,0,distance);
    translation = rotation * translation;

    m_position= m_target + translation;
    m_up = rotation * QVector3D(0,1,0);
    m_viewDirty = true;
}

void Camera::init(){
    QMatrix4x4 view = getView();
    QQuaternion inverseView = QQuaternion::fromRotationMatrix(view.inverted().normalMatrix());

    m_yawPitchRoll = inverseView.toEulerAngles();

}

QVector3D Camera::getPosition()
{
    return m_position;
}
