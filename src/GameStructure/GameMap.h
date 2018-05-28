#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "config.h"

class GameMap
{
    protected:
        long m_width;
        long m_height;

    public:
        GameMap(long _width, long _height);
        virtual ~GameMap();

        long width() const { return m_width * tileSide; }
        void setWidth(long val) { m_width = tileCoord(val); }
        long height() const { return m_height * tileSide; }
        void setHeight(long val) { m_height = tileCoord(val); }

        long tileWidth() const { return m_width; }
        void setTileWidth(long val) { m_width = val; }
        long tileHeight() const { return m_height; }
        void setTileHeight(long val) { m_height = val; }
};

#endif // GAMEMAP_H
