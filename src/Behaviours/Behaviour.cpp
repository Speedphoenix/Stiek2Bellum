#include "Behaviour.h"
#include "GameContainer.h"

Behaviour::Behaviour()
{
    GameContainer* instance = GameContainer::instance();

    if (!instance)
        throw "No instance of GameContainer";

    instance->addBehaviour(this);
}

Behaviour::~Behaviour()
{
    GameContainer* instance = GameContainer::instance();

    if (instance)
    {
        instance->removeBehaviour(m_containerIterator);
    }
}

