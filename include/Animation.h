#ifndef ANIMATION_H
#define ANIMATION_H

#include <map>
#include <vector>
#include "allegroImplem.h"

//to scope the Directions (that have short names) without using an enum class
namespace Direc {

    //make it unsigned to make sure when comparing, or when making an array (of size State::none)
    enum Direction : unsigned{
        N,  // North, towards the top
        S,  // South, towards the bottom
        E,  // East, to the right
        W,  // West, to the left
        NE, // North East
        NW, // North West
        SE, // South East
        SW, // South West

        none //for when none of the directions are available
    };
};

class Shadow;

class Animation
{
    friend class Shadow;

    protected:
        std::map<Direc::Direction, std::vector<ALLEGRO_BITMAP*>> m_frames;
        Shadow* m_shadow;

        Direc::Direction m_currDirection;


        Direc::Direction getBestDirection(Direc::Direction depending = Direc::E);

    public:
        Animation();
        virtual ~Animation();

        unsigned nbFrames();

        ALLEGRO_BITMAP* getFrame(unsigned frameNumber);

        void setDirection(Direc::Direction val);

        Shadow* shadow() { return m_shadow; }
        void setShadow(Shadow* val) { m_shadow = val; }


        Direc::Direction currDirection() const { return m_currDirection; }
        void setCurrDirection(Direc::Direction val) { m_currDirection = val; }
};

#endif // ANIMATION_H
