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

    ///FOR TESTING PURPOSES
    public:
        void maketest();

    protected:
        std::map<Direc::Direction, std::vector<ALLEGRO_BITMAP*>> m_frames;
        Shadow* m_shadow;

        Direc::Direction m_currDirection;

        //the lapse of time to wait between each frame
        //might wanna make this unique to each direction...
        double m_lapse;

        Direc::Direction getBestDirection(Direc::Direction depending = Direc::E);

    public:
        Animation();
        virtual ~Animation();

        void getFromStream(std::istream& theStream);

        unsigned nbFrames();

        ALLEGRO_BITMAP* getFrame(unsigned frameNumber);

        void setDirection(Direc::Direction val);

        Shadow* shadow() { return m_shadow; }
        void setShadow(Shadow* val) { m_shadow = val; }


        Direc::Direction currDirection() const { return m_currDirection; }
        void setCurrDirection(Direc::Direction val) { m_currDirection = val; }

        //make this return the lapse for the current direction if you separate them
        double lapse() const { return m_lapse; }
        void setLapse(double val) { if (val>0) m_lapse = val;}
};

inline std::istream& operator>>(std::istream& theStream, Animation& recept)
{
    recept.getFromStream(theStream);
    return theStream;
}

#endif // ANIMATION_H
