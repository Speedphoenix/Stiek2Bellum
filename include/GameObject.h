#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Transform.h"

class GameObject
{
    protected:
        bool m_toRemove;
        bool m_dead;

        Transform m_transform;

    public:
        GameObject();
        GameObject(double _x, double _y, double _speed = 0);
        virtual ~GameObject();

        virtual void start() { }
        virtual void draw() { }
        virtual void update() { }

        virtual Transform& getTransform() { return m_transform; }
        virtual void setTransform(const Transform& val) { m_transform = val; }

        virtual void setToRemove() { m_dead = true; m_toRemove = true; }
        virtual bool toRemove() { return m_toRemove; }

        virtual void setDead(bool _dead = true) { m_dead = _dead; }
        virtual bool dead() { return m_dead; }
};

#endif // GAMEOBJECT_H
