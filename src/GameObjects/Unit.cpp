#include "Unit.h"

#include "Camera.h"
#include "debugNerrors.h"

///FOR TESTING PURPOSES
void Unit::maketest()
{
    m_animator.maketest();
}

Unit::Unit(const Transform& source, int _owner)
    :GameObject(source), m_animator(this), m_owner(_owner), m_dead(false)
{

}

Unit::Unit(double _x, double _y, int _owner, double _w, double _h)
    :GameObject(_x, _y, _w, _h), m_animator(this), m_owner(_owner), m_dead(false)
{
    //ctor
}

Unit::~Unit()
{
    //dtor
}

void Unit::start()
{
    m_animator.launch();
}

void Unit::draw()
{
    const Transform& camera = Camera::getCurrentView();

    if (m_transform.touches(camera))
    {
        double relx = 0, rely = 0;
        m_transform.getRelativeCoords(camera, relx, rely);


        m_animator.draw(relx, rely);
    }
    //m_animator.getImg();
}

