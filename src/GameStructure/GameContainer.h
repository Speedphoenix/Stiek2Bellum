#ifndef GAMECONTAINER_H
#define GAMECONTAINER_H

#include <list>
#include <vector>

#include "GameObject.h"
#include "GameMap.h"
#include "allegroImplem.h"

class GameContainer
{
    //statics
    protected:
        static GameContainer * m_instance;
    public:
        static GameContainer * instance() { return m_instance; }

    //non-static member variables
    protected:

        ALLEGRO_EVENT_QUEUE *m_eventsDisplay;
        ALLEGRO_EVENT_QUEUE *m_eventsKeyboard;
        ALLEGRO_EVENT_QUEUE *m_eventsMouse;

        std::list<GameObject *> m_objects;

        GameMap m_map;

        bool m_finished;


    //non-static methods
    protected:
        void eventCatch();
        void playerUpdate();
        void autoUpdate(double factor);

    public:
        GameContainer(long _width, long _height);
        virtual ~GameContainer();

        //no copy ctor or assignment
        GameContainer(const GameContainer& that) = delete;

        virtual void update(double factor);

        virtual void draw();

        virtual bool stop() const { return m_finished; }

        void addObject(GameObject* what) { if (what) m_objects.push_back(what); }

        void setMap(const GameMap& val) { m_map = val; }

        long width() const { return m_map.width(); }
        long height() const { return m_map.height(); }
};


#endif // GAMECONTAINER_H
