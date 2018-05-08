#include "allegroImplem.h"
#include "GameContainer.h"

using namespace std;

int main(int argc, char* argv[])
{
    initAlleg(); // or ALLEGRO_FULLSCREEN_WINDOW

    while(1)
    {
        al_rest(2.5);
        //toggleFullscreen();
    }

    closeAlleg();
    return 0;
}


