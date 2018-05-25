#include "Drawable.h"

#include "GameContainer.h"

Drawable::Drawable()
{
    GameContainer::instance()->addDrawable(this);
}

Drawable::~Drawable()
{
    GameContainer::instance()->removeDrawable(m_containerIterator);
}


