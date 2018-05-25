#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "allegroImplem.h"
#include "Transform.h"

#include <vector>
#include <algorithm>
#include <list>


class GameObject
{
    private:
        std::list<GameObject *>::iterator m_containerIterator;

    protected:
        bool m_toRemove;

        Transform m_transform;

        GameObject *m_parent = nullptr;
        std::vector<GameObject*> m_children;

    public:
        GameObject(const Transform& source);
        GameObject(double _x = 0, double _y = 0, double _w = 0, double _h = 0, double _speed = 0);
        GameObject(GameObject *_parent, double _x = 0, double _y = 0, double _w = 0, double _h = 0);
        virtual ~GameObject();

        //important functions
        virtual void start() { }            //called at the start of the game (when all the gameobjects N' stuff are already instantiated)
        virtual void preUpdate() { }        //called at the start of each game loop
        virtual void update(double factor); //called during each game loop
        virtual void postUpdate() { }       //called after update in each loop, before drawing

        virtual GameObject *parent() {return m_parent; }
        virtual void setParent(GameObject *val);
        virtual void removeParent() { setParent(nullptr); } ///if the object cannot live without the parent kill it inside here

        virtual void addChild(GameObject *child);
        virtual bool removeChild(GameObject *what);

        virtual Transform& getTransform() { return m_transform; }
        virtual void setTransform(const Transform& val) { m_transform = val; }

        virtual void setToRemove();
        virtual bool toRemove() { return m_toRemove; }
};

#endif // GAMEOBJECT_H
