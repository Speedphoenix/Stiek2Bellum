#include "allegroImplem.h"
#include "GameContainer.h"

using namespace std;

int main(int argc, char* argv[])
{
    initAlleg(); // or pass ALLEGRO_FULLSCREEN_WINDOW as a param

    GameContainer theGame(300, 225);

    bool finished = false;


    while(!finished)
    {

        finished = theGame.stop();
        al_rest(2.5);
    }

    closeAlleg();
    return 0;
}


