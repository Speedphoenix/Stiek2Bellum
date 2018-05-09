#include "Transform.h"

#include "GameContainer.h"

using namespace std;

double SQ(double x)
{
    return x*x;
}


Transform::Transform(double _x, double _y, double _w, double _h, bool _moving, double _speed, double _orientation)
    :m_x(_x), m_y(_y), m_w(_w), m_h(_h), m_speed(_speed), m_orientation(_orientation), m_moving(_moving)
{
    calcCompos();
}

Transform::Transform(double _x, double _y, double _w, double _h, double _dx, double _dy, bool _moving)
    :m_x(_x), m_y(_y), m_w(_w), m_h(_h), m_dx(_dx), m_dy(_dy), m_moving(_moving)
{
    calcOrientation();
}


Transform::Transform(Transform *_parent, double _x, double _y, double _w, double _h)
    :Transform(_x, _y, _w, _h, false)
{
    m_parent = _parent;
}

Transform::~Transform()
{
    //dtor
}

void Transform::translate(double factor)
{
    m_x += m_dx*factor;
    m_y += m_dy*factor;

    blockBorder();
}



bool Transform::isInside(const Transform& container) const
{
    if (absX() >= container.absX() &&
        endAbsX() <= container.endAbsX() &&
        absY() >= container.absY() &&
        endAbsY() <= container.endAbsY())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Transform::touches(const Transform& container) const
{
    if ( ( (absX() > container.absX() && absX() < container.endAbsX()) ||
            (endAbsX() > container.absX() && endAbsX() < container.endAbsX()) ) &&
        ( (absY() > container.absY() && absY() < container.endAbsY()) ||
            (endAbsY() > container.absY() && endAbsY() < container.endAbsY()) ) )
    {
        return true;
    }
    else
        return container.isInside(*this);
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

void Transform::blockBorder()
{
    GameContainer& container = *GameContainer::instance();

    if (absX() < 0)
        setAbsX(0);
    else if (endAbsX() > container.width())
        setAbsX(container.width() - m_w);

    if (absY() < 0)
        setAbsY(0);
    else if (endAbsY() > container.height())
        setAbsY(container.height() - m_h);
}

double Transform::getSQDist(double x2, double y2) const
{
    return ( SQ(this->centerAbsX() - x2) + SQ(this->centerAbsY() - y2) );
}

double Transform::getSQDist(const Transform& other) const
{
    return getSQDist(other.centerAbsX(), other.centerAbsY());
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

void Transform::setParent(Transform *val)
{
    double _x = absX();
    double _y = absY();

    m_parent = val;

    setAbsX(_x);
    setAbsY(_y);
}


