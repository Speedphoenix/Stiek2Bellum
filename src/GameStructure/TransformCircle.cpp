#include "TransformCircle.h"

#include "GameContainer.h"

TransformCircle::TransformCircle(double _x, double _y, double _radius, bool _moving, double _speed, double _orientation)
    :TransformBase(_x, _y, _speed, _orientation, _moving), m_radius(_radius)
{
    // calcCompos() is called in the parent (TransformBase) class
}

TransformCircle::TransformCircle(double _x, double _y, double _radius, double _dx, double _dy, bool _moving)
    :TransformBase(_x, _y, _dx, _dy, _moving), m_radius(_radius)
{
    // calcOrientation() is called in the parent (TransformBase) class
}


TransformCircle::TransformCircle(TransformBase *_parent, double _x, double _y, double _radius)
    :TransformBase(_parent, _x, _y), m_radius(_radius)
{

}

TransformCircle::~TransformCircle()
{

}


void TransformCircle::blockBorder()
{
    GameContainer& container = *GameContainer::instance();

    if (absX() < 0)
        setAbsX(0);
    else if ((absX() + 2*m_radius) > container.width())
        setAbsX(container.width() - 2*m_radius);

    if (absY() < 0)
        setAbsY(0);
    else if ((absY() + 2*m_radius) > container.height())
        setAbsY(container.height() - 2*m_radius);
}
