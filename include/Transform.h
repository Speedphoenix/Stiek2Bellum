#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <cmath>

class GameContainer;

class Transform
{
    protected:
        double m_x; //!< x coordinates
        double m_y; //!< y coordinates
        double m_w; //!< width
        double m_h; //!< height
        double m_speed; //!< the speed
        double m_orientation; //!< orientation
        double m_dx; //!< speed along x
        double m_dy; //!< speed along y

        bool m_moving;

        Transform *m_parent = nullptr;


    //methods
    protected:
        void calcCompos();
        void calcOrientation();
        void blockBorder();

    public:
        Transform(double _x = 0, double _y = 0, double _w = 0, double _h = 0, bool _moving = false, double _speed = 0, double _orientation = 0);
        Transform(double _x, double _y, double _w, double _h, double _dx, double _dy, bool _moving = false);
        Transform(Transform *_parent, double _x = 0, double _y = 0, double _w = 0, double _h = 0);

        virtual ~Transform();


        virtual void translate(double factor);


        bool isInside(const Transform& container) const;
        bool touches(const Transform& context) const;


        virtual double getSQDist(double x2, double y2) const;
        virtual double getSQDist(const Transform& other) const;
        static double getSQDist(const Transform& first, const Transform& second);
        static double getSQDist(double x1, double y1, double x2, double y2);

        virtual double getDist(double x2, double y2) const;
        virtual double getDist(const Transform& other) const;
        static double getDist(const Transform& first, const Transform& second);
        static double getDist(double x1, double y1, double x2, double y2);


        Transform *parent() const { return m_parent; }
        void setParent(Transform *val); //!< keeps the absolute position

        bool moving() const { return m_moving; }
        void setMoving(bool val = true) { m_moving = val; }

        double x() const { return m_x; }
        void setX(double val) { m_x = val; }
        double y() const { return m_y; }
        void setY(double val) { m_y = val; }
        void setPos(double _x, double _y) { m_x = _x; m_y = _y; }

        double absX() const { return m_x + (m_parent?m_parent->centerAbsX():0); }
        double absY() const { return m_y + (m_parent?m_parent->centerAbsY():0); }
        void setAbsX(double val) { m_x = val - (m_parent?m_parent->centerAbsX():0); }
        void setAbsY(double val) { m_y = val - (m_parent?m_parent->centerAbsY():0); }

        double centerX() const { return m_x + m_w/2; }
        double centerY() const { return m_y + m_h/2; }
        double endX() const { return m_x + m_w; }
        double endY() const { return m_y + m_h; }

        double centerAbsX() const { return m_x + m_w/2 + (m_parent?m_parent->centerAbsX():0); }
        double centerAbsY() const { return m_y + m_h/2 + (m_parent?m_parent->centerAbsY():0); }
        double endAbsX() const { return m_x + m_w + (m_parent?m_parent->centerAbsX():0); }
        double endAbsY() const { return m_y + m_h + (m_parent?m_parent->centerAbsY():0); }


        double width() const { return m_w; }
        void setWidth(double val) { m_w = val; }
        double height() const { return m_h; }
        void setHeight(double val) { m_h = val; }
        void setDim(double _w, double _h) { m_w = _w; m_h = _h; }


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
