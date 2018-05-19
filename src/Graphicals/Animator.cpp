#include "Animator.h"

using namespace std;

Animator::Animator(State startState, Direc::Direction startDirection)
    :m_currFrame(0), m_currAnimation(startState)
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



//to not rewrite it everytime....
#define CHECK(x) if (theMap.count(x)) return x;

//check dans l'ordre
#define CHECKORDER(_1, _2, _3, _4, _5, _6)  \
CHECK(_1)                                   \
else CHECK(_2)                              \
else CHECK(_3)                              \
else CHECK(_4)                              \
else CHECK(_5)                              \
else CHECK(_6)                              \
else return none;

//returns the best direction
State Animator::getBestState(std::map<State, Animation*>& theMap, State depending)
{
    if (theMap.empty())
        return none;

    CHECK(depending) //usually stops here

    switch (depending)
    {
        case Walking:
        CHECKORDER(Crouching, TipToes, Attacking, Burning, Dying, Swimming)
    break;

        case Crouching:
        CHECKORDER(Walking, TipToes, Attacking, Burning, Dying, Swimming)
    break;

        case TipToes:
        CHECKORDER(Walking, Crouching, Attacking, Burning, Dying, Swimming)
    break;

        case Attacking:
        CHECKORDER(Burning, Walking, Crouching, TipToes, Dying, Swimming)
    break;

        case Swimming:
        CHECKORDER(Crouching, Attacking, Walking, TipToes, Dying, Burning)
    break;

        case Dying:
        CHECKORDER(Burning, Crouching, Swimming, Walking, TipToes, Attacking)
    break;

        case Burning:
        CHECKORDER(Dying, Crouching, Walking, Attacking, TipToes, Swimming)
    break;

        default:
        case none:
        return getBestState(theMap, Walking);
    break;
    }
}

#undef CHECK
#undef CHECKORDER

