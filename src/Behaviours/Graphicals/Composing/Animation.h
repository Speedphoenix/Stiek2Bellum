#ifndef ANIMATION_H
#define ANIMATION_H

#include <map>
#include <vector>

const double defaultLapse = 0.4; //seconds

//to scope the Directions (that have short names) without using an enum class
namespace Direc {

    //make it unsigned to make sure when comparing, or when making an array (of size State::none)
    enum Direction : unsigned{
        E,  // East, to the right
        NE, // North East
        N,  // North, towards the top
        NW, // North West
        W,  // West, to the left
        SW, // South West
        S,  // South, towards the bottom
        SE, // South East

        none //for when none of the directions are available
    };
}

class Shadow;
class Frame;
struct ALLEGRO_BITMAP;

class Animation
{
    friend class Shadow;

    ///FOR TESTING PURPOSES
    public:
        void maketest(int type = 0);

    protected:
        //all the frames of all animations
        std::map<Direc::Direction, std::vector<Frame*>> m_frames;

        //pointer to the shadow of this animation, if there is one
        Shadow* m_shadow;

        //the corrent direction of the animations
        Direc::Direction m_currDirection;

        //the lapse of time to wait between each frame
        //might wanna make this unique to each direction...
        double m_lapse;

        ///Returns the available direction closest to the input direction 'depending'
        Direc::Direction getBestDirection(Direc::Direction depending = Direc::E);

    public:
        Animation();
        virtual ~Animation();

        ///loads every frame of the anymation & others from the stream
        void getFromStream(std::istream& theStream);

        ///the number of frames of the animation for the current direction
        unsigned nbFrames();


        //just draws at x, y on the current target bitmap
        virtual void draw(double destx, double desty, unsigned frameNumber);

        ///the current sprite to render
        Frame* getFrame(unsigned frameNumber);


        Direc::Direction currDirection() const { return m_currDirection; }

        ///set the direction. Will chose the closest available if there are no frames for val direction
        void setDirection(Direc::Direction val);
        void setDirection(double orientation);

        Shadow* shadow() { return m_shadow; }
        void setShadow(Shadow* val) { m_shadow = val; }


        //make this return the lapse for the current direction if you separate them
        ///the lapse of time to wait between every frame
        double lapse() const { return m_lapse; }
        void setLapse(double val) { if (val>0) m_lapse = val;}
};

inline std::istream& operator>>(std::istream& theStream, Animation& recept)
{
    recept.getFromStream(theStream);
    return theStream;
}

#endif // ANIMATION_H
