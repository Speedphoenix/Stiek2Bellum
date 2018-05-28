#ifndef CAMERA_H
#define CAMERA_H

#include "Transform.h"
#include "config.h"

const double maxZoom = 2.0;//for the moment
const double minZoom = 0.5;

union ALLEGRO_EVENT;

class Camera
{
    //statics
    protected:
        static Camera * m_currentCamera;
    public:
        static Camera * currentCamera() { return m_currentCamera; }
        static void setCurrentCamera(Camera* what) { m_currentCamera = what; }
        static const Transform& getCurrentView() { return m_currentCamera->m_takenView; }


    //non-statics
    protected:
        Transform m_displayedDims;  //!< the dimensions of the display
        Transform m_takenView;      //!< the transform of what is seen on screen. what is taken from the game

        //zoom equation: dims of zone taken = dim of 'screen' * zoomFactor
        double m_zoomFactor; // equal to takenView/displayedDims

    //non-static methods
    protected:
        void calcTakenView();      //sets the width etc of takenView depending on the displayedView and the zoomFactor
        void blockBorders();
        void blockZoom();

        const TransformBase * m_follow = nullptr;

    public:
        Camera();
        virtual ~Camera();


        virtual void update();


        void moveCamera(double dx, double dy);
        void setCameraPos(double x, double y);
        void setCameraPos(const TransformBase& where);
        void setCameraCenterPos(double x, double y);
        void setCameraCenterPos(const TransformBase& where);

        //resizes the displayed view depending on the current display (from allegroImplem)
        void resizeView();
        void resizeView(const ALLEGRO_EVENT& event);

        ///WARNING: increasing the zoom value will zoom OUT, decreasing will zoom IN
        void addZoom(double val);
        void setZoom(double val);
        double getZoom() const { return m_zoomFactor; }

        void setFollowingTransform(TransformBase* what) { m_follow = what; }
        const TransformBase* getFollowingTransform() const { return m_follow; }
};

#endif // CAMERA_H
