#ifndef SCENEMANGE_H
#define SCENEMANGE_H

#include <osg/Group>
#include <osg/Switch>

namespace kee
{
    class SceneMange
    {
    public:
        SceneMange();

        static osg::ref_ptr<osg::Switch> s_swith;
        static osg::ref_ptr<osg::Group> s_root;
    };
}

#endif // SCENEMANGE_H
