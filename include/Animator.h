#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "Animation.h"

enum State{
    Idle,
    Dead,
    Crouching,
    TipToes,
    Walking,
    Attacking,
    Swimming,
    Dying,
    Burning,
    Burnt
};

///make a function to get the direction/state depending on the available ones

class Animator
{
    protected:
        int m_currFrame;
        State m_currAnimation;
        Direc::Direction m_currDirection;

        std::map<State, Animation*> m_animations;
        std::map<State, Shadow*> m_shadows;

    public:
        Animator(State startState = Idle, Direc::Direction startDirection = Direc::S);
        virtual ~Animator();

//        Animator(const Animator& other);
//        Animator& operator=(const Animator& other);

        int currFrame() const { return m_currFrame; }
        void setCurrFrame(int val) { m_currFrame = val; }
        State currAnimation() const { return m_currAnimation; }
        void setCurrAnimation(State val) { m_currAnimation = val; }
        Direc::Direction currDirection() const { return m_currDirection; }
        void setCurrDirection(Direc::Direction val) { m_currDirection = val; }
};

#endif // ANIMATOR_H


