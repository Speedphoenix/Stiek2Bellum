#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

/**
    This file contains
    constants and others stuff to configure the game

    Things and constants for testing purposes are in debugNerrors.h
*/


/********************************************************************
                                ALLEG
********************************************************************/

const int defaultDispWidth = 800;
const int defaultDispHeight = 600;


/********************************************************************
                                MAP
********************************************************************/

///the size of a (square) tile
const int tileSide = 75;

///converts coordinates in number of tiles
inline int tileCoord(int pixels)
{
    return ((int) (pixels / tileSide));
}

/********************************************************************
                            GRAPHICALS
********************************************************************/

#define RES_DIR "res/"


/********************************************************************
                            BASIC OPERATORS
********************************************************************/

#define XOR(a, b) ( (a) ? !(b) : (b) )
#define ABS(a) ( ((a) < 0) ? -1 * (a) : (a) )
#define MIN(a, b) ( ((a) < (b)) ? (a) : (b) )
#define MAX(a, b) ( ((a) > (b)) ? (a) : (b) )



#endif // CONFIG_H_INCLUDED

