#include "Transform.h"

#include "GameContainer.h"

using namespace std;

double SQ(double x)
{
    return x*x;
}

Transform::Transform()
    :m_x(0), m_y(0), m_speed(0), m_orientation(0), m_dx(0), m_dy(0), m_moving(false)
{
    //ctor
}

Transform::Transform(double _x, double _y, bool _moving, double _speed, double _orientation)
    :m_x(_x), m_y(_y), m_speed(_speed), m_orientation(_orientation), m_moving(_moving)
{
    calcCompos();
}

Transform::Transform(double _x, double _y, double _dx, double _dy, bool _moving)
    :m_x(_x), m_y(_y), m_dx(_dx), m_dy(_dy), m_moving(_moving)
{
    calcOrientation();
}

Transform::~Transform()
{
    //dtor
}

void Transform::translate(double factor, const GameContainer& container)
{
    container.width();

    m_x += m_dx*factor;
    m_y += m_dy*factor;

    if (m_x<0)
        m_x = 0;
    else if (m_x>container.width())
        m_x = container.width();

    if (m_y<0)
        m_y = 0;
    else if (m_y>container.height())
        m_y = container.height();
}

void Transform::calcCompos()
{
    m_dx = m_speed * cos(m_orientation);
    m_dy = m_speed * sin(m_orientation);
}

void Transform::calcOrientation()
{
    m_speed = getDist(m_dx, m_dy, 0, 0);

    m_orientation = acos(m_dx/m_speed);
}


double Transform::getSQDist(double x2, double y2) const
{
    return ( SQ(this->x() - x2) + SQ(this->y() - y2) );
}

double Transform::getSQDist(const Transform& other) const
{
    return getSQDist(other.x(), other.y());
}

double Transform::getSQDist(const Transform& first, const Transform& second)
{
    return first.getSQDist(second);
}

double Transform::getSQDist(double x1, double y1, double x2, double y2)
{
    return ( SQ(x1 - x2) + SQ(y1 - y2) );
}


double Transform::getDist(double x2, double y2) const
{
    return sqrt(getSQDist(x2, y2));
}

double Transform::getDist(const Transform& other) const
{
    return sqrt(getSQDist(other));
}

double Transform::getDist(const Transform& first, const Transform& second)
{
    return first.getDist(second);
}

double Transform::getDist(double x1, double y1, double x2, double y2)
{
    return getSQDist(x1, y1, x2, y2);
}

