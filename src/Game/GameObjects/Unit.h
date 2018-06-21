#ifndef UNIT_H
#define UNIT_H

#include <GameObject.h>
#include <Drawable.h>

//even if it's already included in GameObject...
#include "TransformBase.h"

#include "Animator.h"

extern const int tileSide;
const int NEUTRAL = 0;

class Unit : public GameObject, Drawable
{
    ///FOR TESTING PURPOSES
    public:
        void maketest();

    protected:
        Animator m_animator;

        TransformBase m_destination;

        double m_speed;

        //will change the type to a proper enum or pointer in time
        //the player it is affiliated
        int m_owner;

        //a Unit being dead does not mean it will be removed (bu cadavers usually don't do much)
        bool m_dead;

    public:
        Unit(const Transform& source, int _owner = NEUTRAL);
        Unit(double _x, double _y, int _owner = NEUTRAL, double _w = tileSide, double _h = tileSide);
        virtual ~Unit();

        //override update functions etc from GameObject

        //overriden from the GameObject abstract class
        virtual void start();
        virtual void update(); //make sure to call GameObject::update()

        //overriden from the drawable interface
        virtual void draw();


        int owner() { return m_owner; }
        void setOwner(int val) { m_owner = val; }

        //override this setter to set m_dead false at the same time
        virtual void setToRemove() { setDead(true); m_toRemove = true; }

        virtual void setDest(int _x, int _y) { m_destination.setAbsPos(_x, _y); }

        virtual void setDead(bool _dead = true) { m_dead = _dead; }
        virtual bool dead() { return m_dead; }
};

#endif // UNIT_H
