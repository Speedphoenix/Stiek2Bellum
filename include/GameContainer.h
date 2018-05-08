#ifndef GAMECONTAINER_H
#define GAMECONTAINER_H

#include <list>
#include <vector>

#include "GameObject.h"
#include "GameMap.h"

class GameContainer
{
    //statics
    protected:
        static GameContainer * m_instance;
    public:
        static GameContainer * instance() { return m_instance; }

    //non-statics
    protected:

        std::list<GameObject *> m_objects;

        GameMap m_carte;

    public:
        GameContainer(long _width, long _height);
        virtual ~GameContainer();

        //no copy ctor or assignment
        GameContainer(const GameContainer& that) = delete;

        virtual void update();

        virtual void draw();

        long width() const { return m_carte.width(); }
        long height() const { return m_carte.height(); }
};


#endif // GAMECONTAINER_H
