#include <QtGui/QApplication>
#include "mainwindow.h"

//#include "kee/Math.h"

#include <osgDB/ReadFile>
#include <osgUtil/Optimizer>
#include <osgViewer/Viewer>
#include <iostream>

int main( int argc, char **argv )
{

    QApplication app(argc,argv);

    MainWindow m;
    m.showMaximized();

    return app.exec();
}
