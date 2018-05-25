#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <list>

///drawable interface
class Drawable
{
    private:
        std::list<Drawable *>::iterator m_containerIterator;

    public:
        Drawable();
        virtual ~Drawable();

        virtual void draw() = 0;
};

#endif // DRAWABLE_H
