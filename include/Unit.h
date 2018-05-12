#ifndef UNIT_H
#define UNIT_H

#include <GameObject.h>

#include "GameMap.h"

const int NEUTRAL = 0;

class Unit : public GameObject
{
    protected:
        int m_owner;

    public:
        Unit(const Transform& source, int _owner = NEUTRAL);
        Unit(double _x, double _y, int _owner = NEUTRAL, double _w = tileSide, double _h = tileSide);
        virtual ~Unit();

        int owner() { return m_owner; }
        void setOwner(int val) { m_owner = val; }
};

#endif // UNIT_H
