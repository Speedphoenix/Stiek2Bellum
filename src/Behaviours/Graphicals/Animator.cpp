#include "Animator.h"

#include "TransformBase.h"
#include "allegroImplem.h"
#include "colors.h"
#include "debugNerrors.h"

#include <math.h>


using namespace std;

///FOR TESTING PURPOSES
void Animator::maketest()
{
    Animation* newAnim = new Animation();
    newAnim->maketest();

    m_currState = Transition(Walking, Anim::Idle, false);

    m_animations[m_currState] = newAnim;
}



Animator::Animator(GameObject* attachTo, State startState, double startDirection)
    :Behaviour(attachTo), m_currFrame(0), m_currState(startState, Anim::Idle, false), m_askedDir(startDirection)
{
    m_timer = al_create_timer(defaultLapse);

    m_queue = al_create_event_queue();

    //THE TIMER IS NOT STARTED YET
    al_register_event_source(m_queue, al_get_timer_event_source(m_timer));
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

//change these two functions if you really want to add a transition between Active and Idle
void Animator::makeActive(bool playOnce)
{
    //if it changed
    if (m_currState.animType!=Anim::Active && m_currState.animType!=Anim::Transition)
    {
        m_currState.animType = Anim::Active;
        m_currFrame = 0;

        //there might be an Idle, but not an Active, or the other way 'round
        State inter = getBestState(m_animations, Anim::Active, m_currState.to);
        m_currState.from = inter;
        m_currState.to = inter;
    }

    m_currState.playOnce = playOnce;
}

void Animator::makeIdle()
{
    //if it changed
    if (m_currState.animType!=Anim::Idle && m_currState.animType!=Anim::Transition)
    {
        m_currState.animType = Anim::Idle;
        m_currFrame = 0;

        //there might be an Idle, but not an Active, or the other way 'round
        State inter = getBestState(m_animations, Anim::Idle, m_currState.to);
        m_currState.from = inter;
        m_currState.to = inter;
    }
}

void Animator::setState(State what, bool shouldChangeDirec)
{
    if (what==m_currState.to)
        return;

    //we're starting a transition. The from State should be the old state (even if it was a transition itself)
    m_currState.from = m_currState.to;
    m_currState.to = getBestState(m_animations, Anim::Idle, what);
    m_currState.animType = Anim::Transition;
    m_currState.playOnce = true;

    //if the transition animation doesn't exist
    if (!m_animations.count(m_currState))
    {
        m_currState.from = m_currState.to;

        m_currState.animType = Anim::Idle;
        m_currState.playOnce = false;
    }

    m_currFrame = 0;

    if (shouldChangeDirec)
        m_animations.at(m_currState)->setDirection(m_askedDir);

    double newLapse = m_animations.at(m_currState)->lapse();

    //set the right lapse for the new animation
    //this comparison of floating point is safe since it was only set
    //from a definite value, no operations were made on it.
    if (al_get_timer_speed(m_timer) != newLapse)
        al_set_timer_speed(m_timer, newLapse);
}

void Animator::setState(State what, double direction)
{
    setState(what, false);
    setDirection(direction);
}

void Animator::setState(State what, const TransformBase& direction)
{
    setState(what, false);
    setDirection(direction);
}

void Animator::setDirection(double direction)
{
    if (direction >= 2*M_PI || direction < 0)
        m_askedDir = 0;
    else
        m_askedDir = direction;

    m_animations.at(m_currState)->setDirection(m_askedDir);
}

void Animator::setDirection(const TransformBase& direction)
{
    setDirection(direction.orientation());
}


void Animator::draw(double destx, double desty)
{
    m_animations.at(m_currState)->draw(destx, desty, m_currFrame);
}

void Animator::launch()
{
    al_start_timer(m_timer);
}

void Animator::stop()
{
    al_stop_timer(m_timer);
}

void Animator::update()
{
    ALLEGRO_EVENT retEvent;

    while (al_get_next_event(m_queue, &retEvent))
    {
        m_currFrame++;

        if (m_currFrame >= m_animations.at(m_currState)->nbFrames())
        {
            m_currFrame = 0;
        }
    }
}

ALLEGRO_BITMAP* Animator::getImg()
{
    return m_animations.at(m_currState)->getFrame(m_currFrame);
}

void Animator::setCurrFrame(unsigned val)
{
    if (val >= m_animations.at(m_currState)->nbFrames())
        m_currFrame = 0;
    else
        m_currFrame = val;
}



//below this is to choose the right state depending on available ones


//to not rewrite it everytime....
#define CHECK(x)                    \
keyIdx.from = x;                    \
keyIdx.to = x;                      \
if (theMap.count(keyIdx)) return x;

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
State Animator::getBestState(const std::map<Transition, Animation*>& theMap, Anim::AnimType animType, State depending)
{
    if (theMap.empty())
        return none;

    Transition keyIdx;
    keyIdx.animType = animType;

    CHECK(depending) //should usually stop here

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
        return getBestState(theMap, animType, Walking);
    break;
    }
}

#undef CHECK
#undef CHECKORDER

