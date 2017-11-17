#include "SceneMange.h"

using namespace kee;

osg::ref_ptr<osg::Switch> SceneMange::s_swith=new osg::Switch;
osg::ref_ptr<osg::Group> SceneMange::s_root=new osg::Group;


SceneMange::SceneMange()
{

}
