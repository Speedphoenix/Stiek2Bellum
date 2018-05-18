#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <algorithm>

#include "allegroImplem.h"

#include "Transform.h"

class GameObject
{
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

        virtual void start() { }
        virtual void draw() { }
        virtual void update(double factor);

        virtual GameObject *parent() {return m_parent; }
        virtual void setParent(GameObject *val);
        virtual void removeParent() { setParent(nullptr); } ///if the object cannot live without the parent kill it inside here

        virtual void addChild(GameObject *child);
        virtual bool removeChild(GameObject *what);

        virtual Transform& getTransform() { return m_transform; }
        virtual void setTransform(const Transform& val) { m_transform = val; }

        virtual void setToRemove() { m_toRemove = true; }
        virtual bool toRemove() { return m_toRemove; }
};

#endif // GAMEOBJECT_H
