#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <list>

//may want to  make a list in the gameobject to contain all behaviours, and add itself automatically or smth
class GameObject;


///a class that will add itself to the current GameContainer, and will remove itself from the gamecontainer
class Behaviour
{
    private:
        //the iterator of the list in the GameContainer
        std::list<Behaviour *>::iterator m_containerIterator;

        //the GameObject to which this behavious is atached
        GameObject* m_attachedObject;

    protected:

    public:
        Behaviour(GameObject* attachTo);
        virtual ~Behaviour();

        virtual void start() { }

        virtual void preUpdate() { }
        virtual void update() = 0;
        virtual void postUpdate() { }

        GameObject* attachedObject() { return m_attachedObject; }
        //make a proper setter if the need arises
};

#endif // BEHAVIOUR_H
