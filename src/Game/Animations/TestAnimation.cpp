#include "TestAnimation.h"

#include "SpritesContainer.h"
#include "Frame.h"

#include "colors.h"
#include "allegroImplem.h"
#include "game_config.h"

using namespace std;

TestAnimation::TestAnimation()
{
    //ctor
}

TestAnimation::~TestAnimation()
{
    //dtor
}

///FOR TESTING PURPOSES
void TestAnimation::maketest(int type)
{
    SpritesContainer* sprites = SpritesContainer::instance();

    ALLEGRO_BITMAP* btm;
    ALLEGRO_BITMAP* parent = sprites->at(TEST_SHEETNAME);

    vector<Frame*>& inDirec = m_frames[Direc::E];

    switch (type)
    {
        case 0: //idle
        {
            inDirec.push_back(new Frame(parent, 0, 0, 75, 75));
//            inDirec.push_back(new Frame(parent, 4*75, 0, 75, 75));
//            inDirec.push_back(new Frame(parent, 0, 0, 75, 75));
            inDirec.push_back(new Frame(parent, 5*75, 75, 75, 75));
            m_lapse = defaultIdleLapse;
        }
    break;

        case 1: //active
        {
            for (int i=0;i<6;i++)
            {
                inDirec.push_back(new Frame(parent, i*75, 0, 75, 75));
            }
            m_lapse = defaultActiveLapse;
        }
    break;

        case 2: //attack idle
        {
            inDirec.push_back(new Frame(parent, 75, 75, 5*75, 75));
            m_lapse = defaultIdleLapse;
        }
    break;

        case 3: //attack active
        {
            for (int i=0;i<6;i++)
            {
                inDirec.push_back(new Frame(parent, i*75, 75, 75, 75));
            }
            m_lapse = defaultActiveLapse;
        }
    break;

        default:
        //the default flag, never know
        al_set_new_bitmap_flags(ALLEGRO_CONVERT_BITMAP);

        btm = al_create_bitmap(75, 75);

        al_set_target_bitmap(btm);
        al_clear_to_color(col::olds::GRASS);
        al_draw_filled_rectangle(20, 20, 55, 55, col::olds::UI_ACC);

        inDirec.push_back(new Frame(btm));
    break;
    }

    m_currDirection = Direc::E;
}
