#ifndef TRANSFORMBASE_H
#define TRANSFORMBASE_H

#include <cmath>

inline double SQ(double x)
{
    return x*x;
}

inline int SQ(int x)
{
    return x*x;
}

class GameContainer;
class Transform;
class TransformCircle;

/// a virtual class to make transforms (circular or rect)
class TransformBase
{
    //statics
    public:
        static bool isInside(const Transform& contained, const Transform& container);               //two rects
        static bool isInside(const TransformCircle& contained, const TransformCircle& container);   //two circles
        static bool isInside(const Transform& contained, const TransformCircle& container);         //rect in circle
        static bool isInside(const TransformCircle& contained, const Transform& container);         //circle in rect

        static bool touches(const Transform& first, const Transform& second);               //two rects
        static bool touches(const TransformCircle& first, const TransformCircle& second);   //two circles
        static bool touches(const Transform& first, const TransformCircle& second);         //one rect and one circle
        static bool touches(const TransformCircle& first, const Transform& second) { return touches(second, first); } //to call it both ways


    //non-statics
    protected:
        double m_x; //!< x coordinates
        double m_y; //!< y coordinates

        double m_speed; //!< the speed
        double m_orientation; //!< orientation
        double m_dx; //!< speed along x
        double m_dy; //!< speed along y

        bool m_moving;

        TransformBase *m_parent = nullptr;


    //methods
    protected:
        virtual void calcCompos();
        virtual void calcOrientation();
        //stops from going out-of bounds
        virtual void blockBorder();

    public:
        TransformBase(double _x = 0, double _y = 0, bool _moving = false, double _speed = 0, double _orientation = 0);
        TransformBase(double _x, double _y, double _dx, double _dy, bool _moving = false);
        TransformBase(TransformBase *_parent, double _x = 0, double _y = 0);

        virtual ~TransformBase();


        virtual void translate(double factor);

        virtual bool isInside(const Transform& container);
        virtual bool isInside(const TransformCircle& container);
        virtual bool touches(const Transform& other);
        virtual bool touches(const TransformCircle& other);

        virtual double getSQDist(double x2, double y2) const;
        virtual double getSQDist(const TransformBase& other) const;
        static double getSQDist(const TransformBase& first, const TransformBase& second);
        static double getSQDist(double x1, double y1, double x2, double y2);

        virtual double getDist(double x2, double y2) const;
        virtual double getDist(const TransformBase& other) const;
        static double getDist(const TransformBase& first, const TransformBase& second);
        static double getDist(double x1, double y1, double x2, double y2);


        TransformBase *parent() const { return m_parent; }
        void setParent(TransformBase *val); //!< while keeping the same absolute position

        bool moving() const { return m_moving; }
        void setMoving(bool val = true) { m_moving = val; }

        virtual double x() const { return m_x; }
        virtual void setX(double val) { m_x = val; }
        virtual double y() const { return m_y; }
        virtual void setY(double val) { m_y = val; }
        virtual void setPos(double _x, double _y) { m_x = _x; m_y = _y; }

        virtual double absX() const { return m_x + (m_parent?m_parent->centerAbsX():0); }
        virtual double absY() const { return m_y + (m_parent?m_parent->centerAbsY():0); }
        virtual void setAbsX(double val) { m_x = val - (m_parent?m_parent->centerAbsX():0); }
        virtual void setAbsY(double val) { m_y = val - (m_parent?m_parent->centerAbsY():0); }

        // MAKE SURE TO OVERRIDE THESE IF THE TRANSFORM ISN'T PUNCTUAL
        virtual double centerX() const { return x(); }
        virtual double centerY() const { return y(); }
        virtual void setCenterX(double val) { setX(val); }
        virtual void setCenterY(double val) { setY(val); }

        virtual double centerAbsX() const { return centerX() + (m_parent?m_parent->centerAbsX():0); }
        virtual double centerAbsY() const { return centerY() + (m_parent?m_parent->centerAbsY():0); }
        virtual void setCenterAbsX(double val) { setCenterX(val - (m_parent?m_parent->centerAbsX():0)); }
        virtual void setCenterAbsY(double val) { setCenterY(val - (m_parent?m_parent->centerAbsY():0)); }

        double dx() const { return m_dx; }
        void setDx(double val) { m_dx = val; calcOrientation(); }
        double dy() const { return m_dy; }
        void setDy(double val) { m_dy = val; calcOrientation(); }
        void setDiff(double _dx, double _dy) { m_dx = _dx; m_dy = _dy; calcOrientation(); }

        double speed() const { return m_speed; }
        void setSpeed(double val) { m_speed = val; calcCompos(); }

        double orientation() const { return m_orientation; }
        void setOrientation(double val) { m_orientation = val; calcCompos(); }
};

#endif // TRANSFORMBASE_H
