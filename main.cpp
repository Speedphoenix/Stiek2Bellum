#include <allegro5/allegro5.h>
#include <iostream>

using namespace std;

ALLEGRO_DISPLAY *initial();

int main()
{
    ALLEGRO_DISPLAY *display = initial();
    cout << "Hello world!" << endl;

    al_destroy_display(display);
    return 0;
}

ALLEGRO_DISPLAY *initial()
{
    ALLEGRO_DISPLAY *display;

    if (!al_init())
        throw "Could not initialize Allegro 5";

    display = al_create_display(800, 600);

    if (!display)
        throw "Could not create display";

    return display;
}

