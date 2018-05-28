#include "GameContainer.h"

#include "allegroImplem.h"

#include "debugNerrors.h"

using namespace std;

int main(int argc, char* argv[])
{
    try
    {
        initAlleg(); // or pass ALLEGRO_FULLSCREEN_WINDOW as a param
    }
    catch (const char* e)
    {
        cerr << endl << e << endl;
    }


    GameContainer theGame(60, 45);


    theGame.maketest();
    theGame.start();

    bool finished = false;


    while(!finished)
    {
        theGame.update(1);

        finished = theGame.shouldStop();
        al_rest(0.02);
    }

    closeAlleg();
    return 0;
}


