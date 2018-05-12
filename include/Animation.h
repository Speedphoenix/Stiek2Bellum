#ifndef ANIMATION_H
#define ANIMATION_H

#include <map>
#include <vector>
#include "allegroImplem.h"

//to scope the Directions (that have short names) without using an enum class
namespace Direc {

    enum Direction{
        N,  // North, towards the top
        S,  // South, towards the bottom
        E,  // East, to the right
        W,  // West, to the left
        NE, // North East
        NW, // North West
        SE, // South East
        SW  // South West
    };
};

class Shadow;

class Animation
{
    friend class Shadow;

    protected:
        std::map<Direc::Direction, vector<ALLEGRO_BITMAP*>> m_frames;
        Shadow* m_shadow;

    public:
        Animation();
        virtual ~Animation();

        int nbFrames(Direc::Direction direction); ///check for the right direction that exists etc...

        int getFrame(Direc::Direction direction, int frameNumber); ///check for the right direction that exists etc...

        Shadow* shadow() { return m_shadow; }
        void setShadow(Shadow* val) { m_shadow = val; }
};

#endif // ANIMATION_H
