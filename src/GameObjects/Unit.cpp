#include "Unit.h"

Unit::Unit(const Transform& source, int _owner)
    :GameObject(source), m_owner(_owner)
{

}

Unit::Unit(double _x, double _y, int _owner, double _w, double _h)
    :GameObject(_x, _y, _w, _h), m_owner(_owner)
{
    //ctor
}

Unit::~Unit()
{
    //dtor
}


