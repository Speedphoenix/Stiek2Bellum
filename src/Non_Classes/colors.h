#ifndef COLORS_H_INCLUDED
#define COLORS_H_INCLUDED

#include "allegroImplem.h"

namespace col
{

const ALLEGRO_COLOR white   = al_map_rgb(255,255,255);  //!< #FFFFFF
const ALLEGRO_COLOR black   = al_map_rgb(0,0,0);        //!< #000000
const ALLEGRO_COLOR red     = al_map_rgb(255,0,0);      //!< #FF0000
const ALLEGRO_COLOR green   = al_map_rgb(0,255,0);      //!< #00FF00
const ALLEGRO_COLOR blue    = al_map_rgb(0,0,255);      //!< #0000FF
const ALLEGRO_COLOR mag     = al_map_rgb(255,0,255);    //!< #FF00FF


///colors used for the original Stiek Bellum. Most were used in the minimap
namespace olds
{
    const ALLEGRO_COLOR UI_FOND     = al_map_rgb(1,87,155);     //!< #01579B
    const ALLEGRO_COLOR UI_ACC      = al_map_rgb(79,195,247);   //!< #4FC3F7
    const ALLEGRO_COLOR SAND        = al_map_rgb(194,132,80);   //!< #C28450
    const ALLEGRO_COLOR BRIDGE      = al_map_rgb(122,61,0);     //!< #7A3D00
    const ALLEGRO_COLOR GRASS       = al_map_rgb(110,130,51);   //!< #6E8233
    const ALLEGRO_COLOR WATER       = al_map_rgb(48,140,187);   //!< #308CBB
    const ALLEGRO_COLOR MOUNTAIN    = al_map_rgb(83,83,83);     //!< #535353
    const ALLEGRO_COLOR ROCK        = al_map_rgb(128,128,128);  //!< #808080
    const ALLEGRO_COLOR TREEL       = al_map_rgb(78,145,101);   //!< #4E9165
    const ALLEGRO_COLOR TREEP       = al_map_rgb(58,99,58);     //!< #3A633A
    const ALLEGRO_COLOR PEASANT     = al_map_rgb(34,93,255);    //!< #225DFF
}

}


#endif // COLORS_H_INCLUDED


