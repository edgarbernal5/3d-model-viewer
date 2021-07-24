#include <QTest>

#include "tst_scenemanager.h"
#include "tst_shaperepository.h"

int main(int argc, char *argv[])
{
    TestSceneManager test1;
    TestShapeRepository test2;

    int failedTests = 0;
    failedTests += QTest::qExec(&test1, argc, argv);
    failedTests += QTest::qExec(&test2, argc, argv);

    if(failedTests > 0)
    {
        qDebug() << "Total number of failed tests: " << failedTests;
    }
    else
    {
        qDebug() << "All tests passed :)";
    }
    return failedTests;
}
