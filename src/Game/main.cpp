
#include "allegroImplem.h"
#include "colors.h"
#include "debugNerrors.h"

#include "S2BContainer.h"
#include "SpritesContainer.h"

#include "Unit.h"

using namespace std;


namespace test {
	void maketestSprites();
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
		ES(e)
	}

	SpritesContainer sprites;
	S2BContainer theGame(60, 45);

	test::maketestSprites();
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

void maketestSprites()
{
	//the default flags, just in case it was changed somewhere
	al_set_new_bitmap_flags(ALLEGRO_CONVERT_BITMAP);

	SpritesContainer::instance()->addSprite(TEST_SHEETNAME, al_load_bitmap(TEST_SPRITESHEET));
}

///FOR TESTING PURPOSES
void maketest()
{
	//this will automatically add the unit to this GameContainer
	Unit* newUnit = new Unit(0.0, 0.0);

	newUnit->maketest();

	//gameContainer's map is already a test from its constructor
	//default camera should work just fine
}

}

