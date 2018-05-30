#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "config.h"

class GameMap
{
    protected:
        long m_width;   //!< in tiles, not pixels
        long m_height;  //!< in tiles, not pixels

    public:
        GameMap(long _width, long _height);
        virtual ~GameMap();

        //the dimentions expressed in pixels
        long width() const { return m_width * tileSide; }
        void setWidth(long val) { m_width = tileCoord(val); }
        long height() const { return m_height * tileSide; }
        void setHeight(long val) { m_height = tileCoord(val); }
        void setDim(long widthVal, long heightVal) { setWidth(widthVal); setHeight(heightVal); }

        //the dimensions expressed in tiles
        long tileWidth() const { return m_width; }
        void setTileWidth(long val) { m_width = val; }
        long tileHeight() const { return m_height; }
        void setTileHeight(long val) { m_height = val; }
        void setTileDim(long widthVal, long heightVal) { setTileWidth(widthVal); setTileHeight(heightVal); }
};

#endif // GAMEMAP_H
