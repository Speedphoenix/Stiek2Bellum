#include "S2BContainer.h"
#include "Events.h"
#include "GameObjects/Unit.h"

//from allegro5
#include "allegro5/keycodes.h"
#include "allegro5/events.h"

#include "debugNerrors.h"

S2BContainer::S2BContainer(long _width, long _height)
	:GameContainer(), m_testUnit(new Unit(100.0, 100.0)), m_map(_width, _height), m_camera()
{

}

S2BContainer::~S2BContainer()
{

}


void S2BContainer::start()
{
	m_testUnit->maketest();

	GameContainer::start();
}


void S2BContainer::onKeyboardEvent(const KeyboardEvent& event)
{
	if (event.keycode == ALLEGRO_KEY_ESCAPE)
		m_finished = true;
}

void S2BContainer::onMouseEvent(const MouseEvent& event)
{
	if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
	{
		m_testUnit->setDest(event.x, event.y);
	}
}

void S2BContainer::onTouchEvent(const TouchEvent& event)
{

}


void S2BContainer::playerUpdate()
{
	//may move the camera here...
}

