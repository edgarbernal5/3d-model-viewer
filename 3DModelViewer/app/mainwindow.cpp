#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionCube, SIGNAL(triggered()), this, SLOT(on_createCube()));

    m_opengl = ui->widget;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createCube()
{
    QString cubeId("cube");
    cubeId.append(QString::number(lastId));
    ++lastId;

    m_opengl->createCube(cubeId);
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

