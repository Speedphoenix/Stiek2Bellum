
#include "allegroImplem.h"
#include "colors.h"
#include "debugNerrors.h"

#include "S2BContainer.h"
#include "TestSpritesContainer.h"

#include "GameObjects/Unit.h"

using namespace std;


namespace test {
    void maketest();
}

int main(int argc, char* argv[])
{
    try
    {
        initAlleg(ALLEGRO_WINDOWED, defaultDispWidth, defaultDispHeight); // or pass ALLEGRO_FULLSCREEN_WINDOW as a param
    }
    catch (const char* e)
    {
        cerr << endl << e << endl;
    }

    TestSpritesContainer sprites;
    S2BContainer theGame(60, 45);

    sprites.maketest();
    test::maketest();
    theGame.start();

    double elapsed = 0.02;

    while(!theGame.shouldStop())
    {

        theGame.update(elapsed*10);

        al_rest(elapsed);
    }

    closeAlleg();
    return 0;
}


namespace test {

///FOR TESTING PURPOSES
void maketest()
{
    //this will automatically add the unit to this GameContainer
    Unit* newUnit = new Unit(10.0, 10.0);

    newUnit->maketest();

    //gameContainer's map is already a test from its constructor
    //default camera should work just fine
}

}

