#ifndef GAMECONTAINER_H
#define GAMECONTAINER_H

#include "GameMap.h"
#include "Transform.h"

#include "allegroImplem.h"
#include <list>
#include <vector>


class Drawable;
class GameObject;
class Behaviour;

class GameContainer
{
    //statics
    protected:
        static GameContainer * m_instance;
    public:
        static GameContainer * instance() { return m_instance; }

    //non-static member variables
    private:
        //lists of all Objects and instances of most things
        std::list<GameObject *> m_objects;
        std::list<Behaviour *> m_behaviours;
        std::list<Drawable *> m_drawables;

        //list of things that will be be destroyed at the end of current turn (before draw)
        std::list<std::list<GameObject*>::iterator> m_remObjects;
        std::list<std::list<Behaviour*>::iterator> m_remBehaviours;
        std::list<std::list<Drawable*>::iterator> m_remDrawables;

    protected:

        ALLEGRO_EVENT_QUEUE *m_eventsDisplay;
        ALLEGRO_EVENT_QUEUE *m_eventsKeyboard;
        ALLEGRO_EVENT_QUEUE *m_eventsMouse;

        GameMap m_map;
        Transform m_camera;

        bool m_finished;


    //non-static methods
    protected:
//        void resizeCamera();
//        void resizeCamera(ALLEGRO_DISPLAY* display);

        //call every turn
        void eventCatch();
        void playerUpdate();
        void preUpdate();
        void autoUpdate(double factor);
        void postUpdate();
        void autoRemove();

    public:
        GameContainer(long _width, long _height);
        virtual ~GameContainer();

        //no copy ctor or assignment
        GameContainer(const GameContainer& that) = delete;

        virtual void update(double factor);
        virtual void draw();

        ///need to RENAME THIS ONE
        virtual bool stop() const { return m_finished; }

        void setMap(const GameMap& val) { m_map = val; }

        long mapWidth() const { return m_map.width(); }
        long mapHeight() const { return m_map.height(); }

        //these will be called by their respective constructors
        std::list<GameObject*>::iterator addObject(GameObject* what);
        std::list<Behaviour*>::iterator addBehaviour(Behaviour* what);
        std::list<Drawable*>::iterator addDrawable(Drawable* what);

        //these will set the iterator to be removed at the end of the turn
        void removeObject(std::list<GameObject*>::iterator what);
        void removeBehaviour(std::list<Behaviour*>::iterator what);
        void removeDrawable(std::list<Drawable*>::iterator what);
};


#endif // GAMECONTAINER_H
