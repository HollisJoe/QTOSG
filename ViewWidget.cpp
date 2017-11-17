#include "ViewWidget.h"
#include <iostream>
#include <QtGui>

#include <osgDB/ReaderWriter>
#include <osgDB/ReadFile>

using namespace kee;

//================= common method ======================================
osg::Camera* createCamera( int x, int y, int w, int h, bool windowDecoration)
{
    osg::DisplaySettings* ds = osg::DisplaySettings::instance().get();
    osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
    traits->windowName = "";
    traits->windowDecoration = windowDecoration;
    traits->x = x;
    traits->y = y;
    traits->width = w;
    traits->height = h;
    traits->doubleBuffer = true;
    traits->alpha = ds->getMinimumNumAlphaBits();
    traits->stencil = ds->getMinimumNumStencilBits();
    traits->sampleBuffers = ds->getMultiSamples();
    traits->samples = ds->getNumMultiSamples();

    osg::ref_ptr<osg::Camera> camera = new osg::Camera;
    camera->setGraphicsContext( new osgQt::GraphicsWindowQt(traits.get()) );
    camera->setClearColor( osg::Vec4(0.0, 0.0, 0.0, 1.0) );
    camera->setViewport( new osg::Viewport(0, 0, traits->width, traits->height) );
    camera->setProjectionMatrixAsPerspective(
                30.0f, static_cast<double>(traits->width)/static_cast<double>(traits->height), 0.1f, 10000.0f );
    return camera.release();
}
//================= common method ======================================

ViewWidget::ViewWidget( QWidget* parent)
    :QWidget(parent)
{
    m_viewer=new osgViewer::Viewer;
    m_viewer->setThreadingModel(osgViewer::ViewerBase::CullDrawThreadPerContext);
    m_camera=createCamera(this->x(),this->y(),this->width(),this->height(),false);
    m_viewer->setCamera(m_camera);
    m_viewer->setCameraManipulator(new osgGA::TrackballManipulator);

    m_root=new osg::Group;
    m_viewer->setSceneData(m_root);

    QHBoxLayout* layout=new QHBoxLayout;
    m_gwQt = dynamic_cast<osgQt::GraphicsWindowQt*>( m_camera->getGraphicsContext() );
    layout->addWidget(m_gwQt->getGLWidget());
    this->setLayout(layout);

    connect(&m_updateTimer,SIGNAL(timeout()),this,SLOT(update()));
    m_updateTimer.start(20);
}

void ViewWidget::paintEvent(QPaintEvent *e)
{
    m_viewer->frame();
}

void ViewWidget::paintGL()
{

}

void ViewWidget::readNodeFromFile(std::string osgFile)
{
    osg::Node* node= osgDB::readNodeFile(osgFile);
    if(node)
    {
        m_root->addChild(node);

    }
}

