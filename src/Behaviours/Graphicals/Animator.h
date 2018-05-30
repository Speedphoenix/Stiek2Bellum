#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <Behaviour.h>

#include "Animation.h"

#include <map>

class GameObject;
class TransformBase;
struct ALLEGRO_BITMAP;
struct ALLEGRO_EVENT_QUEUE;
struct ALLEGRO_TIMER;

//make it unsigned to make sure when comparing, or when making an array (of size State::none)
enum State : unsigned{
    Walking,
    Crouching,
    TipToes,
    Attacking,
    Swimming,
    Dying,
    Burning,

    none
};

namespace Anim {
    enum AnimType : int{
        Idle,
        Active,
        Transition  // these will be played once during the transition from one state to another
                    // (only if the transition animation exists)
    };
}

//might wanna rename this struct...
struct Transition{
    State from;
    //bool fromIdle;

    State to;
    //bool toIdle;

    Anim::AnimType animType;

    bool playOnce;

    Transition()
        :from(Walking), to(Walking), animType(Anim::Idle), playOnce(false) { }

    Transition(State _from, State _to, Anim::AnimType _animType = Anim::Idle, bool _playOnce = false)
        :from(_from), to(_to), animType(_animType), playOnce(_playOnce) { }

    Transition(State _state, Anim::AnimType _animType = Anim::Idle, bool _playOnce = false)
        :from(_state), to(_state), animType(_animType), playOnce(_playOnce) { }

    //not really necessary
    bool operator==(const Transition& other) const {
        return (other.from == this->from && other.to == this->to && this->animType==other.animType);
    }

    //to be used as a key in a map
    bool operator<(const Transition& other) const {
        if (this->animType < other.animType)
            return true;
        else if (this->animType > other.animType)
            return false;
        else if (this->from < other.from)   //check from state
            return true;
        else if (this->from > other.from)
            return false;
        else if (this->to < other.to)       //check to state
            return true;
        else if (this->to > other.to)
            return false;
        else                            //this means the two transitions are the same
            return false;
    }
};



class Animator : public Behaviour
{
    ///FOR TESTING PURPOSES
    public:
        void maketest();

    //statics
    public:
        static State getBestState(const std::map<Transition, Animation*>& theMap, Anim::AnimType animType, State depending);

    //non-statics
    protected:

        ALLEGRO_TIMER* m_timer;
        ALLEGRO_EVENT_QUEUE* m_queue;

        unsigned m_currFrame;

        Transition m_currState;

        ///ADD A STATE FOR ASKED STATE (even if it doesn't exist, to go from Idle <-> Active)

        //should replace all of these by one big map<Transition, Animation *>
        std::map<Transition, Animation*> m_animations;

        double m_askedDir;

        //might wanna remove this, since there should already be a pointer in the animation class
        //std::map<State, Shadow*> m_shadows;


    public:
        Animator(GameObject* attachTo, State startState = Walking, double startDirection = 0);
        virtual ~Animator();

//        Animator(const Animator& other);
//        Animator& operator=(const Animator& other);


        //just draws at x, y on the current target bitmap
        virtual void draw(double destx, double desty);

        virtual void launch();   //can be used to un-pause too
        virtual void stop();    //can be used to pause too
        virtual void update();
        virtual ALLEGRO_BITMAP* getImg();

        ///direction should be in radian
        virtual void setDirection(double direction);
        virtual void setDirection(const TransformBase& direction);

        virtual void setState(State what, bool shouldChangeDirec = true);
        virtual void setState(State what, double direction);
        virtual void setState(State what, const TransformBase& direction);

        virtual void makeActive(bool playOnce = true);
        virtual void makeIdle();

        unsigned currFrame() const { return m_currFrame; }
        void setCurrFrame(unsigned val);
        State currAnimation() const { return m_currState.to; }
};

#endif // ANIMATOR_H


