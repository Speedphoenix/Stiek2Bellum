#include "GameObjects/Unit.h"

#include "Camera.h"
#include "debugNerrors.h"

///FOR TESTING PURPOSES
void Unit::maketest()
{
    m_animator.maketest();
}

Unit::Unit(const Transform& source, int _owner)
    :GameObject(source), m_animator(this), m_destination(source), m_speed(defaultUnitSpeed), m_owner(_owner), m_dead(false)
{
    m_destination.setMoving(false);
}

Unit::Unit(double _x, double _y, int _owner, double _w, double _h)
    :GameObject(_x, _y, _w, _h), m_animator(this), m_destination(_x + _w/2, _y + _h/2, 0, 0, false), m_speed(defaultUnitSpeed), m_owner(_owner), m_dead(false)
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

void Unit::update()
{
    if (!m_transform.hasSamePos(m_destination))
    {
        m_transform.headTowards(m_destination, m_speed);

        m_transform.setMoving(true);

        m_animator.makeActive(false);
    }
    else
    {
        m_transform.setMoving(false);

        m_animator.makeIdle();
    }

    GameObject::update();
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

