#include "GameObject.h"

using namespace std;

GameObject::GameObject(const Transform& source)
    :m_transform(source)
{

}


GameObject::GameObject(double _x, double _y, double _w, double _h, double _speed)
    :m_transform(_x, _y, _w, _h, false, _speed)
{

}

GameObject::GameObject(GameObject *_parent, double _x, double _y, double _w, double _h)
    :m_transform(&_parent->getTransform(), _x, _y, _w, _h)
{
    m_parent = _parent;
}


GameObject::~GameObject()
{
    //dtor
}

void GameObject::setParent(GameObject *val)
{
    m_parent = val;

    m_transform.setParent(&val->getTransform());
}


