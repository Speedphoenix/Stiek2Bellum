#ifndef ALLEGROIMPLEM_H_INCLUDED
#define ALLEGROIMPLEM_H_INCLUDED

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include <iostream>

#define E(x) {std::cerr << std::endl << #x ": " << x << std::endl;}

#define XOR(a, b) ( (a) ? !(b) : (b) )

extern ALLEGRO_DISPLAY *currentDisplay;

const int defaultDispFlags = ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE;
const int defaultDispWidth = 800;
const int defaultDispHeight = 600;

void initAlleg(int flags = 0, int w = 800, int h = 600, const char* window_name = "");

void closeAlleg();

void toggleFullscreen();

#endif //ALLEGROIMPLEM_H_INCLUDED

