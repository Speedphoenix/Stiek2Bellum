#include "GameContainer.h"

#include "GameObject.h"
#include "Behaviour.h"
#include "Drawable.h"

GameContainer * GameContainer::m_instance = nullptr;

using namespace std;

GameContainer::GameContainer(long _width, long _height)
    :m_map(_width, _height), m_finished(false)
{

    if (m_instance!=nullptr)
        throw "A game container already exists";

    m_instance = this;

    m_eventsDisplay = al_create_event_queue();
    al_register_event_source(m_eventsDisplay, al_get_display_event_source(currentDisplay));

    m_eventsKeyboard = al_create_event_queue();
    al_register_event_source(m_eventsKeyboard, al_get_keyboard_event_source());

    m_eventsMouse = al_create_event_queue();
    al_register_event_source(m_eventsMouse, al_get_mouse_event_source());
}

GameContainer::~GameContainer()
{
    al_destroy_event_queue(m_eventsDisplay);
    al_destroy_event_queue(m_eventsKeyboard);
    al_destroy_event_queue(m_eventsMouse);

    for (auto& elem : m_objects)
    {
        delete elem;
    }

    m_instance = nullptr;
}

///MAKE A STRUCT/CLASS FOR ACTIONS (DIFFERENT EVENTS CAN TRIGGER THE SAME ACTION), AND USE THAT.
///to make it easier to eventually have multiple players (online? AI? split screen?)
//for events:
//https://allegro.developpez.com/5/livre/?page=page_6
void GameContainer::eventCatch()
{
    ALLEGRO_EVENT event = {0};

    while (al_get_next_event(m_eventsDisplay, &event))
    {
        switch (event.type)
        {
            case ALLEGRO_EVENT_DISPLAY_EXPOSE:
            case ALLEGRO_EVENT_DISPLAY_RESIZE:
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
            case ALLEGRO_EVENT_DISPLAY_LOST:
            case ALLEGRO_EVENT_DISPLAY_FOUND:
            case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
            case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
            case ALLEGRO_EVENT_DISPLAY_ORIENTATION:

        break;

            default:
        break;
        }
    }

    while (al_get_next_event(m_eventsKeyboard, &event))
    {
        switch (event.type)
        {
            case ALLEGRO_EVENT_KEY_DOWN:
            case ALLEGRO_EVENT_KEY_CHAR:
            case ALLEGRO_EVENT_KEY_UP:

        break;

            default:
        break;
        }
    }

    while (al_get_next_event(m_eventsMouse, &event))
    {
        switch (event.type)
        {
            case ALLEGRO_EVENT_MOUSE_AXES:
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
            case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
            case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
            case ALLEGRO_EVENT_MOUSE_WARPED:

        break;

            default:
        break;
        }
    }
}


void GameContainer::update(double factor)
{
    eventCatch();

    preUpdate();

    playerUpdate();

    autoUpdate(factor);

    postUpdate();

    autoRemove();

    draw();
}


void GameContainer::draw()
{
    for (auto & elem : m_drawables)
    {
        elem->draw();
    }
}


void GameContainer::playerUpdate()
{

}

void GameContainer::preUpdate()
{
    for (const auto& it : m_objects)
        it->preUpdate();

    for (auto it : m_behaviours)
        it->preUpdate();
}

void GameContainer::autoUpdate(double factor)
{
    for (const auto& it : m_objects)
        it->update(factor);

    for (auto it : m_behaviours)
        it->update(factor);
}

void GameContainer::postUpdate()
{
    for (const auto& it : m_objects)
        it->postUpdate();

    for (auto it : m_behaviours)
        it->postUpdate();
}

void GameContainer::autoRemove()
{
    //ALWAYS start by removing removing the objects (and delete them)
    //thisq will also call the destructors to the other stuff
    //and thus add them to the other remove lists
    for (const auto& it : m_remObjects)
    {
        delete *it;
        m_objects.erase(it);
    }

    for (const auto& it : m_remBehaviours)
    {
        m_behaviours.erase(it);
    }

    for (const auto& it : m_remDrawables)
    {
        m_drawables.erase(it);
    }
}


//these will be called by their respective constructors
std::list<GameObject*>::iterator GameContainer::addObject(GameObject* what)
{
    if (what)
    {
        m_objects.push_front(what);
        return m_objects.begin();
    }
    else
        throw "tried adding null as an object pointer";
}

std::list<Behaviour*>::iterator GameContainer::addBehaviour(Behaviour* what)
{
    if (what)
    {
        m_behaviours.push_front(what);
        return m_behaviours.begin();
    }
    else
        throw "tried adding null as a behaviour pointer";
}

std::list<Drawable*>::iterator GameContainer::addDrawable(Drawable* what)
{
    if (what)
    {
        m_drawables.push_front(what);
        return m_drawables.begin();
    }
    else
        throw "tried adding null as a drawable pointer";
}



///sets the iterator to be removed at the end of the turn
void GameContainer::removeObject(std::list<GameObject*>::iterator what)
{
    m_remObjects.push_back(what);
}

///sets the iterator to be removed at the end of the turn
void GameContainer::removeBehaviour(std::list<Behaviour*>::iterator what)
{
    m_remBehaviours.push_back(what);
}

///sets the iterator to be removed at the end of the turn
void GameContainer::removeDrawable(std::list<Drawable*>::iterator what)
{
    m_remDrawables.push_back(what);
}



