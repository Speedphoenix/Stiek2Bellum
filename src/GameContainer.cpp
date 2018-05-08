#include "GameContainer.h"

GameContainer * GameContainer::m_instance = nullptr;

using namespace std;

GameContainer::GameContainer(long _width, long _height)
    :m_carte(_width, _height)
{
    if (m_instance!=nullptr)
        throw "A game container already exists";

    m_instance = this;
}

GameContainer::~GameContainer()
{
    m_instance = nullptr;
}



void GameContainer::update()
{
    list<list<GameObject*>::iterator> toErase;

    auto it = m_objects.begin();
    while (it!=m_objects.end())
    {
        GameObject *current = *it;
        current->update();


        if (current->toRemove())
        {
            toErase.push_back(it);
        }

        it++;
    }

    auto it2 = toErase.begin(); //it2 is an iterator to an iterator...
    while (it2!=toErase.begin())
    {
        delete *(*it2);
        m_objects.erase(*it2);

        it2++;
    }
}


void GameContainer::draw()
{
    for (auto & elem : m_objects)
    {
        elem->draw();
    }
}

