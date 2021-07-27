#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "OpenGLWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_createCube();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    OpenGLWidget* m_opengl;

    int lastId = 0;
};
#endif // MAINWINDOW_H
