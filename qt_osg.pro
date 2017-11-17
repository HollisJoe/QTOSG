#-------------------------------------------------
#
# Project created by QtCreator 2013-08-29T19:10:41
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = qt_osg
TEMPLATE = app

DESTDIR=./bin
OBJECTS_DIR=.obj
MOC_DIR=.obj

SOURCES += \
    config.cpp \
    ViewWidget.cpp \
    SceneMange.cpp \
    mainwindow.cpp \
    main.cpp

HEADERS  += \
    config.h \
    ViewWidget.h \
    SceneMange.h \
    mainwindow.h

FORMS    += \
    mainwindow.ui

INCLUDEPATH+=./

OSGDIR = $$quote(D:/Environment/OpenSceneGraph)


INCLUDEPATH += $${OSGDIR}/include


CONFIG(debug, debug|release) {
LIBS += $${OSGDIR}/lib/osgd.lib \
       $${OSGDIR}/lib/osgUtild.lib \
       $${OSGDIR}/lib/osgGAd.lib\
       $${OSGDIR}/lib/osgDBd.lib\
       $${OSGDIR}/lib/osgTextd.lib\
       $${OSGDIR}/lib/osgViewerd.lib\
       $${OSGDIR}/lib/osgShadowd.lib\
       $${OSGDIR}/lib/osgSimd.lib\
       $${OSGDIR}/lib/OpenThreadsd.lib\
       $${OSGDIR}/lib/osgQtd.lib
}
else {
LIBS += $${OSGDIR}/lib/osg.lib \
       $${OSGDIR}/lib/osgUtil.lib \
       $${OSGDIR}/lib/osgGA.lib\
       $${OSGDIR}/lib/osgDB.lib\
       $${OSGDIR}/lib/osgText.lib\
       $${OSGDIR}/lib/osgViewer.lib\
       $${OSGDIR}/lib/osgShadow.lib\
       $${OSGDIR}/lib/osgSim.lib\
       $${OSGDIR}/lib/OpenThreads.lib\
       $${OSGDIR}/lib/osgQt.lib
}

