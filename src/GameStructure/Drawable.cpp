#include "Drawable.h"

#include "GameContainer.h"

Drawable::Drawable()
{
    GameContainer* instance = GameContainer::instance();

    if (!instance)
        throw "No instance of GameContainer";

    instance->addDrawable(this);
}

Drawable::~Drawable()
{
    GameContainer* instance = GameContainer::instance();

    if (instance)
    {
        instance->removeDrawable(m_containerIterator);
    }
}


