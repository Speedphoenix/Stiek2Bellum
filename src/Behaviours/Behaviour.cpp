#include "Behaviour.h"
#include "GameContainer.h"

Behaviour::Behaviour()
{
    GameContainer::instance()->addBehaviour(this);
}

Behaviour::~Behaviour()
{
    GameContainer::instance()->removeBehaviour(m_containerIterator);
}

