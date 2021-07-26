#ifndef MATERIAL_H
#define MATERIAL_H

#include <QVector3D>

class Material
{
public:
    Material();

    QVector3D getDiffuseColor(){
        return m_diffuseColor;
    }
    QVector3D getSpecularColor(){
        return m_specularColor;
    }
    QVector3D getAmbientColor(){
        return m_ambientColor;
    }
    QVector3D getBaseColor(){
        return m_baseColor;
    }

    void setDiffuseColor(QVector3D color){
        m_diffuseColor = color;
    }
    void setSpecularColor(QVector3D color){
        m_specularColor = color;
    }
    void setAmbientColor(QVector3D color){
        m_ambientColor = color;
    }
    void setBaseColor(QVector3D color){
        m_baseColor = color;
    }
private:
    QVector3D m_diffuseColor = QVector3D(1,1,1);
    QVector3D m_specularColor= QVector3D(1,1,1);
    QVector3D m_ambientColor= QVector3D(0.1f,0.1f,0.1f);
    QVector3D m_baseColor= QVector3D(1,1,1);
};

#endif // MATERIAL_H
