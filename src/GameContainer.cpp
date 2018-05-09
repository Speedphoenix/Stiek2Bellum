#include "GameContainer.h"

GameContainer * GameContainer::m_instance = nullptr;

using namespace std;

GameContainer::GameContainer(long _width, long _height)
    :m_map(_width, _height)
{
    if (m_instance!=nullptr)
        throw "A game container already exists";

    m_instance = this;

    m_finished = false;

    al_register_event_source(m_eventsDisplay, al_get_display_event_source(currentDisplay));
    al_register_event_source(m_eventsKeyboard, al_get_keyboard_event_source());
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


void GameContainer::update(double factor)
{
    eventCatch();

    playerUpdate();

    autoUpdate(factor);
}


void GameContainer::draw()
{
    for (auto & elem : m_objects)
    {
        elem->draw();
    }
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
        }
    }
}


void GameContainer::playerUpdate()
{

}

void GameContainer::autoUpdate(double factor)
{
    list<list<GameObject*>::iterator> toErase;

    auto it = m_objects.begin();
    while (it!=m_objects.end())
    {
        GameObject *current = *it;
        current->update(factor);

        if (current->toRemove())
        {
            toErase.push_back(it);
        }

        it++;
    }

    auto it2 = toErase.begin(); //it2 is an iterator to an iterator...
    while (it2!=toErase.end())
    {
        delete *(*it2);
        m_objects.erase(*it2);

        it2++;
    }
}

