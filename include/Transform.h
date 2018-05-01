#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <cmath>

class GameContainer;

class Transform
{
    protected:
        double m_x; //!< x coordinates
        double m_y; //!< y coordinates
        double m_speed; //!< the speed
        double m_orientation; //!< orientation
        double m_dx; //!< speed along x
        double m_dy; //!< speed along y

        bool m_moving;

        void calcCompos();
        void calcOrientation();

    public:

        Transform();
        Transform(double _x, double _y, bool _moving = false, double _speed = 0, double _orientation = 0);
        Transform(double _x, double _y, double _dx, double _dy, bool _moving = false);

        virtual ~Transform();


        void translate(double factor, const GameContainer& container);


        virtual double getSQDist(double x2, double y2) const;
        virtual double getSQDist(const Transform& other) const;
        static double getSQDist(const Transform& first, const Transform& second);
        static double getSQDist(double x1, double y1, double x2, double y2);

        virtual double getDist(double x2, double y2) const;
        virtual double getDist(const Transform& other) const;
        static double getDist(const Transform& first, const Transform& second);
        static double getDist(double x1, double y1, double x2, double y2);


        bool moving() const { return m_moving; }
        void setMoving(bool val = true) { m_moving = val; }

        double x() const { return m_x; }
        void setX(double val) { m_x = val; }
        double y() const { return m_y; }
        void setY(double val) { m_y = val; }
        void setPos(double _x, double _y) { m_x = _x; m_y = _y; }

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

#endif // TRANSFORM_H
