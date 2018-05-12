#ifndef SHADOW_H
#define SHADOW_H

#include <Animation.h>


class Shadow : public Animation
{
    protected:
        Animation* m_Original;
        bool m_canEvolve;

    public:
        Shadow();
        virtual ~Shadow();

        Animation* original() { return m_Original; }
        void setOriginal(Animation* val) { m_Original = val; }
        bool canEvolve() { return m_canEvolve; }
        void setCanEvolve(bool val) { m_canEvolve = val; }
};

#endif // SHADOW_H
