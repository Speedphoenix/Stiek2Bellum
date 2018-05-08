#ifndef GAMEMAP_H
#define GAMEMAP_H


class GameMap
{
    protected:
        long m_width;
        long m_height;

    public:
        GameMap(long _width, long _height);
        virtual ~GameMap();

        long width() const { return m_width; }
        void SetWidth(long val) { m_width = val; }
        long height() const { return m_height; }
        void SetHeight(long val) { m_height = val; }
};

#endif // GAMEMAP_H
