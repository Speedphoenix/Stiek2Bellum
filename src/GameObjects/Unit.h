#ifndef UNIT_H
#define UNIT_H

#include <GameObject.h>
#include <Drawable.h>

#include "Animator.h"

extern const int tileSide;
const int NEUTRAL = 0;

class Unit : public GameObject, Drawable
{
    protected:
        //will change the type to a proper enum or pointer in time
        int m_owner;

        bool m_dead;

        Animator m_animator;

    public:
        Unit(const Transform& source, int _owner = NEUTRAL);
        Unit(double _x, double _y, int _owner = NEUTRAL, double _w = tileSide, double _h = tileSide);
        virtual ~Unit();

        //override update functions etc from GaeObject

        virtual void draw();


        int owner() { return m_owner; }
        void setOwner(int val) { m_owner = val; }

        //override this setter to set m_dead false at the same time
        virtual void setToRemove() { setDead(true); m_toRemove = true; }


        virtual void setDead(bool _dead = true) { m_dead = _dead; }
        virtual bool dead() { return m_dead; }
};

#endif // UNIT_H
