#ifndef OSGWIDGET_H
#define OSGWIDGET_H

#include <QtGui>
#include <QGLWidget>
#include <stdio.h>
#include <string.h>

#include <osg/Camera>
#include <osgQt/GraphicsWindowQt>
#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>

namespace kee
{

// Thread that runs the viewer's frame loop as we can't run Qt in the background...
class ViewerFrameThread : public OpenThreads::Thread
{
public:

    ViewerFrameThread(osgViewer::ViewerBase* viewerBase, bool doQApplicationExit=false):
        _viewerBase(viewerBase),
        _doQApplicationExit(doQApplicationExit) {}

    ~ViewerFrameThread()
    {
        cancel();
        while(isRunning())
        {
            OpenThreads::Thread::YieldCurrentThread();
        }
    }

    int cancel()
    {
        _viewerBase->setDone(true);
        return 0;
    }

    void run()
    {
        int result = _viewerBase->run();

        if (_doQApplicationExit) QApplication::exit(result);
    }

    osg::ref_ptr<osgViewer::ViewerBase> _viewerBase;
    bool _doQApplicationExit;
};

/**
  * osgViewer wrap
  **/
class ViewWidget:public QWidget
{
public:
    ViewWidget( QWidget* parent=0);

    inline osgViewer::Viewer* getView(){return m_viewer.release();}
    inline osg::Group * getRoot() {return m_root.release();}

    void readNodeFromFile(std::string osgFile);

protected:
    void paintEvent(QPaintEvent *);
    void paintGL();

    //    void resizeEvent(QResizeEvent *);

    //    void keyPressEvent(QKeyEvent *event);
    //    void keyReleaseEvent(QKeyEvent *event);
    //    void mousePressEvent(QMouseEvent *event);
    //    void mouseReleaseEvent(QMouseEvent *event);
    //    void mouseMoveEvent(QMouseEvent *event);
    //    void wheelEvent(QWheelEvent *event);

private:

    osg::ref_ptr<osg::Camera> m_camera;
    osg::ref_ptr<osg::Group> m_root;

    osg::ref_ptr<osgViewer::Viewer> m_viewer;
    osg::ref_ptr<osgQt::GraphicsWindowQt> m_gwQt;
    QTimer m_updateTimer;
    ViewerFrameThread* m_frameThread;
};
}

#endif // OSGWIDGET_H
