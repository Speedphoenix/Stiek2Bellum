#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <list>

///a class that will add itself to the current GameContainer, and will remove itself from the gamecontainer
class Behaviour
{
    private:
        std::list<Behaviour *>::iterator m_containerIterator;

    public:
        Behaviour();
        virtual ~Behaviour();

        virtual void preUpdate() { }
        virtual void update(double factor) = 0;
        virtual void postUpdate() { }
};

#endif // BEHAVIOUR_H
