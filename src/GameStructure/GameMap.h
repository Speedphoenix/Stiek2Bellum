#ifndef GAMEMAP_H
#define GAMEMAP_H

const int tileSide = 75;

inline int tileCoord(int pixels)
{
    return ((int) (pixels / tileSide));
}

class GameMap
{
    protected:
        long m_width;
        long m_height;

    public:
        GameMap(long _width, long _height);
        virtual ~GameMap();

        long width() const { return m_width; }
        void setWidth(long val) { m_width = val; }
        long height() const { return m_height; }
        void setHeight(long val) { m_height = val; }
};

#endif // GAMEMAP_H
