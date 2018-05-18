#ifndef ANIMATOR_H
#define ANIMATOR_H

#include "Animation.h"

//make it unsigned to make sure when comparing, or when making an array (of size State::none)
enum State : unsigned{
    Walking,    //default Idle too
    Crouching,
    TipToes,
    Attacking,
    Swimming,
    Dying,      //Idle dead too
    Burning,    //Idle burnt too

    none
};


struct Transition{
    State from;
    State to;

    //not really necessary
    bool operator==(const Transition& other) const {
        return (other.from == this->from && other.to == this->to);
    }

    //to be used as a key in a map
    bool operator<(const Transition& other) const {
        if (this->from < other.from)    //check from state first
            return true;
        else if (this->from > other.from)
            return false;
        else if (this->to < other.to)   //check to state
            return true;
        else if (this->to > other.to)
            return false;
        else                            //this means the two transitions are the same
            return false;
    }
};




class Animator
{
    //statics
    public:
        static State getBestState(std::map<State, Animation*>& theMap, State depending);


    //non-statics
    protected:
        unsigned m_currFrame;
        State m_currAnimation;

        std::map<State, Animation*> m_idles;
        std::map<State, Animation*> m_animations;
        std::map<Transition, Animation*> m_transitions; // these will be played once during the transition from one state to another
                                                        // (only is the transition animation exists)


                //might wanna remove this, since there should already be a pointer in the animation class
        //std::map<State, Shadow*> m_shadows;


    public:
        Animator(State startState = Walking, Direc::Direction startDirection = Direc::S);
        virtual ~Animator();

//        Animator(const Animator& other);
//        Animator& operator=(const Animator& other);



        unsigned currFrame() const { return m_currFrame; }
        void setCurrFrame(unsigned val) { m_currFrame = val; }
        State currAnimation() const { return m_currAnimation; }
        void setCurrAnimation(State val) { m_currAnimation = val; }
};

#endif // ANIMATOR_H


