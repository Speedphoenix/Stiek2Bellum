#ifndef GAMECONTAINER_H
#define GAMECONTAINER_H

#include "GameMap.h"
#include "Camera.h"

#include <list>


class Drawable;
class GameObject;
class Behaviour;
struct ALLEGRO_EVENT_QUEUE;


class GameContainer
{
    ///FOR TESTING PURPOSES
    public:
        void maketest();


    //statics
    protected:
        static GameContainer * m_instance;
    public:
        static GameContainer * instance() { return m_instance; }

        ///the time elapsed since the last game loop. Use this as a factor to move...
        static double deltaTime() { return m_instance->m_deltaTime; }

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


        double m_deltaTime;

    protected:

        ALLEGRO_EVENT_QUEUE *m_eventsDisplay;
        ALLEGRO_EVENT_QUEUE *m_eventsKeyboard;
        ALLEGRO_EVENT_QUEUE *m_eventsMouse;

        GameMap m_map;
        Camera m_camera;

        bool m_finished;


    //non-static methods
    protected:
        //call every turn
        //the individual updates are called for each object, behaviour...
        void eventCatch();      //!< takes in all events that happened since the last game loop
        void preUpdate();       //!< comes first
        void playerUpdate();    //!< does everything related to player/ia input
        void autoUpdate();      //!< the main update
        void postUpdate();      //!< comes last
        void autoRemove();      //!< remove anything that needs to be removed during this game loop

    public:
        GameContainer(long _width, long _height);
        virtual ~GameContainer();

        //no copy ctor or assignment
        GameContainer(const GameContainer&) = delete;
        GameContainer& operator=(const GameContainer&) = delete;

        ///called at the start of the game
        virtual void start();

        ///called at every game loop, calls every other update function and draw()
        virtual void update(double factor);

        ///draws the drawables
        virtual void draw();

        ///returns if the game should stop (is finished) - might wanna rename this ons
        virtual bool shouldStop() const { return m_finished; }

        void setMap(const GameMap& val) { m_map = val; }

        long mapWidth() const { return m_map.width(); }
        long mapHeight() const { return m_map.height(); }

        long mapTileWidth() const { return m_map.tileWidth(); }
        long mapTileHeight() const { return m_map.tileHeight(); }

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
