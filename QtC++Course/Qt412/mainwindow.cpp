#include "mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //central widget a button
    QPushButton* button = new QPushButton("Hello", this);
    setCentralWidget(button);

    //declare quit action
    QAction* quitAction = new QAction("Quit");
    connect(quitAction, &QAction::triggered, [=](){
        QApplication::quit();
    });

    //menu items at the corner of our mainwindows
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Setting");
    menuBar()->addMenu("About");

    statusBar()->showMessage("Upload file...", 3000); // timeout ms
    //statusBar()->clearMessage();
}

MainWindow::~MainWindow()
{

}

QSize MainWindow::sizeHint() const
{
    return QSize(1024, 768);
}
