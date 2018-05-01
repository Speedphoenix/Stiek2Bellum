#ifndef GAMECONTAINER_H
#define GAMECONTAINER_H

#include <list>
#include <vector>

#include "GameObject.h"

class GameContainer
{
    //statics

    public:
        static GameContainer * m_instance;
        static GameContainer * instance() { return m_instance; }

    //non-statics
    protected:


        std::list<GameObject *> m_objects;

        //will be replaced by a good map in time
        long m_width, m_height;

    public:
        GameContainer(long _width, long _height);
        virtual ~GameContainer();

        //no copy ctor or assignment
        GameContainer(const GameContainer& that) = delete;

        virtual void update();

        virtual void draw();

        long width() const { return m_width; }
        long height() const { return m_height; }
};


#endif // GAMECONTAINER_H
