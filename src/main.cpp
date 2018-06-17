#include "GameContainer.h"
#include "SpritesContainer.h"

#include "allegroImplem.h"
#include "colors.h"
#include "debugNerrors.h"

using namespace std;

int main(int argc, char* argv[])
{
    try
    {
        initAlleg(ALLEGRO_WINDOWED, 1200, 800); // or pass ALLEGRO_FULLSCREEN_WINDOW as a param
    }
    catch (const char* e)
    {
        cerr << endl << e << endl;
    }

    GameContainer theGame(60, 45);
    SpritesContainer sprites;

    sprites.maketest();
    theGame.maketest();
    theGame.start();

    while(!theGame.shouldStop())
    {
        theGame.update(1);

        al_rest(0.02);
    }

    closeAlleg();
    return 0;
}


