#include "Animation.h"

#include "colors.h"
#include "allegroImplem.h"
#include "debugNerrors.h"

#include <math.h>

using namespace std;

///FOR TESTING PURPOSES
void Animation::maketest()
{
    ALLEGRO_BITMAP* btm;

    //the default flag, never know
    al_set_new_bitmap_flags(ALLEGRO_CONVERT_BITMAP);

    btm = al_create_bitmap(75, 75);

    al_set_target_bitmap(btm);
    al_clear_to_color(col::olds::GRASS);
    al_draw_filled_rectangle(20, 20, 55, 55, col::olds::UI_ACC);

    m_frames[Direc::E].push_back(btm);
}


//only default, will need to use a real one later
Animation::Animation()
    :m_shadow(nullptr), m_currDirection(Direc::E), m_lapse(defaultLapse)
{
    //ctor
}

Animation::~Animation()
{
    //dtor
}

void Animation::getFromStream(std::istream& theStream)
{

}

unsigned Animation::nbFrames()
{
    if (m_frames.count(m_currDirection))
        return m_frames.at(m_currDirection).size();
    else
        return 0;
}

//we can later make it so that instead of separate bitmaps, we take part of one bigger bitmap, for performance
void Animation::draw(double destx, double desty, unsigned frameNumber)
{
    al_draw_bitmap(this->getFrame(frameNumber), destx, desty, 0);
}

ALLEGRO_BITMAP* Animation::getFrame(unsigned frameNumber)
{

    vector<ALLEGRO_BITMAP*>& inter = m_frames.at(m_currDirection);

    if (frameNumber < inter.size())
        return inter.at(m_currDirection);
    else if (inter.size()!=0)
        return inter.at(inter.size() - 1);  //replace this by inter.at(0); to take the first frame instead
    else
        return nullptr;
}

void Animation::setDirection(Direc::Direction val)
{
    m_currDirection = getBestDirection(val);
}

void Animation::setDirection(double orientation)
{
    //M_2_PI is 2/PI, defined in math.h
    //offset the orientation by 1/2 to have good intervals
    int lookAt = (int) ((orientation * 2 * M_2_PI) + 1/2); // (orientation * 8 / (2*PI)) + 1/2

    //the interval 8-8.5 belongs in 0
    //also to take care of bugs...
    if (lookAt >= 8 || lookAt < 0)
        lookAt = 0;


    setDirection((Direc::Direction) lookAt); // cast into the enum
}


//below this is to choose a direction depending on the available ones


using namespace Direc;

//to not rewrite it everytime....
#define CHECK(x) if (m_frames.count(x)) return x;

//check dans l'ordre
#define CHECKORDER(_1, _2, _3, _4, _5, _6, _7)  \
CHECK(_1)                                       \
else CHECK(_2)                                  \
else CHECK(_3)                                  \
else CHECK(_4)                                  \
else CHECK(_5)                                  \
else CHECK(_6)                                  \
else CHECK(_7)                                  \
else return none;

//returns the best direction
Direction Animation::getBestDirection(Direction depending)
{
    if (m_frames.empty())
        return none;

    CHECK(depending) //usually stops here

    switch (depending)
    {
        case N:
        CHECKORDER(NE, NW, E, W, S, SE, SW)
    break;

        case S:
        CHECKORDER(SE, SW, E, W, NE, NW, N)
    break;

        case E:
        CHECKORDER(SE, NE, S, N, SW, NW, W)
    break;

        case W:
        CHECKORDER(SW, NW, N, S, NE, SE, E)
    break;

        case NE:
        CHECKORDER(E, SE, N, S, NW, W, SW)
    break;

        case NW:
        CHECKORDER(W, SW, N, S, NE, E, SE)
    break;

        case SE:
        CHECKORDER(E, NE, S, N, SW, W, NW)
    break;

        case SW:
        CHECKORDER(W, NW, S, N, SE, E, NE)
    break;

        default:
        case none:
        CHECK(E)
        else CHECKORDER(W, S, N, SE, SW, NE, NW)
    break;
    }
}

#undef CHECK
#undef CHECKORDER

