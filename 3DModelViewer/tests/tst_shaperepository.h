#ifndef TST_SHAPEREPOSITORY_H
#define TST_SHAPEREPOSITORY_H

#include <QtTest>



class ShapeRepositoryShould : public QObject
{
    Q_OBJECT

public:
    ShapeRepositoryShould();
    ~ShapeRepositoryShould();

private slots:
    void createCubeShape();
    void getShapeGivenId();
    void returnEmptyOnInexistentShape();
    void removeShapeGivenId();
    void cannotCreateUnsupportedShape();
};


#endif // TST_SHAPEREPOSITORY_H
