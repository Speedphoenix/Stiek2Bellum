#include "Animator.h"

using namespace std;

Animator::Animator(State startState, Direc::Direction startDirection)
    :m_currFrame(0), m_currAnimation(startState), m_currDirection(startDirection)
{
    //ctor
}

Animator::~Animator()
{
    //dtor
}


//Animator::Animator(const Animator& other)
//{
//    //copy ctor
//}
//
//Animator& Animator::operator=(const Animator& rhs)
//{
//    if (this == &rhs) return *this; // handle self assignment
//
//
//    //assignment operator
//    return *this;
//}

