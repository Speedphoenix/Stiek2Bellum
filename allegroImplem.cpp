#include "allegroImplem.h"

ALLEGRO_DISPLAY *currentDisplay;

void initAlleg()
{
    if (!al_init())
        throw "Could not initialize Allegro 5";

    srand(time(nullptr));

    al_init_image_addon();
    al_install_keyboard();
    al_install_mouse();

    currentDisplay = al_create_display(800, 600);

    if (!currentDisplay)
        throw "Could not create display";

}

void closeAlleg()
{
    al_destroy_display(currentDisplay);
}

