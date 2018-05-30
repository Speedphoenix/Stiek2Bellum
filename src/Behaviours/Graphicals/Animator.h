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

// unsigned to make sure when comparing, or when making an array (of size State::none)
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
    ///The type of an animation
    enum AnimType : int{
        Idle,
        Active,
        Transition  // these will be played once during the transition from one state to another
                    // (only if the transition animation is available)
    };
}

//might wanna rename this struct...
struct Transition{
    State from;
    //bool fromIdle;

    State to;
    //bool toIdle;

    //idle, transition, active. might wanna make this unique to from state and to state...
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

        //timer and event queue to increment frame number at the right intervals
        ALLEGRO_TIMER* m_timer;
        ALLEGRO_EVENT_QUEUE* m_queue;

        //current frame number
        unsigned m_currFrame;

        //current state/transition
        Transition m_currState;

        ///ADD A STATE FOR ASKED STATE (even if it doesn't exist, to go from Idle <-> Active)

        //should replace all of these by one big map<Transition, Animation *>
        std::map<Transition, Animation*> m_animations;

        //the asked direction (because the actual shown dir can be different based on availability
        double m_askedDir;

        //might wanna remove this, since there should already be a pointer in the animation class
        //std::map<State, Shadow*> m_shadows;


    public:
        Animator(GameObject* attachTo, State startState = Walking, double startDirection = 0);
        virtual ~Animator();

//        Animator(const Animator& other);
//        Animator& operator=(const Animator& other);


        /// draws at destx, desty on the current target bitmap
        virtual void draw(double destx, double desty);

        /// starts the animation
        virtual void launch();   //can be used to un-pause too
        ///stops thee animation
        virtual void stop();    //can be used to pause too
        ///will update stuff like the frame counter if need be
        virtual void update();

        ///returns the current image. Use the draw function instead
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


