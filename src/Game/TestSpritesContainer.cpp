#include "TestSpritesContainer.h"

#include "allegroImplem.h"
#include "game_config.h"

using namespace std;

TestSpritesContainer::TestSpritesContainer()
{
    //ctor
}

TestSpritesContainer::~TestSpritesContainer()
{
    //dtor
}

void TestSpritesContainer::maketest()
{
    //the default flags, just in case it was changed somewhere
    al_set_new_bitmap_flags(ALLEGRO_CONVERT_BITMAP);

    m_sprites[TEST_SHEETNAME] = al_load_bitmap(TEST_SPRITESHEET);
}

