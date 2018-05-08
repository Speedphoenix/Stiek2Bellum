#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Transform.h"

class GameObject
{
    protected:
        bool m_toRemove;
        bool m_dead;

        Transform m_transform;

        GameObject *m_parent = nullptr;

    public:
        GameObject(const Transform& source);
        GameObject(double _x = 0, double _y = 0, double _w = 0, double _h = 0, double _speed = 0);
        GameObject(GameObject *_parent, double _x = 0, double _y = 0, double _w = 0, double _h = 0);
        virtual ~GameObject();

        virtual void start() { }
        virtual void draw() { }
        virtual void update() { }

        virtual GameObject *parent() {return m_parent; }
        virtual void setParent(GameObject *val);

        virtual Transform& getTransform() { return m_transform; }
        virtual void setTransform(const Transform& val) { m_transform = val; }

        virtual void setToRemove() { m_dead = true; m_toRemove = true; }
        virtual bool toRemove() { return m_toRemove; }

        virtual void setDead(bool _dead = true) { m_dead = _dead; }
        virtual bool dead() { return m_dead; }
};

#endif // GAMEOBJECT_H
