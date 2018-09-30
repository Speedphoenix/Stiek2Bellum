#include "GameObjects/Unit.h"

#include "Camera.h"
#include "game_config.h"
#include "debugNerrors.h"
#include "GameContainer.h"

///FOR TESTING PURPOSES
void Unit::maketest()
{
	m_animator.maketest();
}

Unit::Unit(const Transform& source, int _owner)
	:GameObject(source), m_animator(this), m_collider(this, source), m_destination(source), m_speed(0), m_maxSpeed(defaultUnitSpeed),
	m_owner(_owner), m_dead(false), m_testBehave(this)
{
	m_destination.setMoving(false);
}

Unit::Unit(double _x, double _y, int _owner, double _w, double _h)	//m_transform is set initialised in the parent constructor
	:GameObject(_x, _y, _w, _h), m_animator(this), m_collider(this, m_transform), m_destination(_x + _w/2, _y + _h/2, 0, 0, false),
	m_speed(0), m_maxSpeed(defaultUnitSpeed), m_owner(_owner), m_dead(false), m_testBehave(this)
{
	//ctor
}

Unit::~Unit()
{
	//dtor
}

void Unit::start()
{
	m_animator.launch();
}

void Unit::update()
{
	if (m_collider.getCollidingList().size() != 0)
	{
		// do something
	}

	if (!m_transform.hasSamePos(m_destination))
	{
		m_transform.headTowards(m_destination, m_maxSpeed);

		m_transform.setMoving(true);

		m_speed = m_transform.speed();

		//the false here stands for loop play (don't only play once)
		m_animator.makeActive(false);
	}
	else
	{
		m_transform.setMoving(false);

		m_speed = 0.0;

		m_animator.makeIdle();
	}

	double factor = GameContainer::deltaTime();

	if (m_transform.isMoving())
	{
		m_transform.translate(factor);
	}
}

void Unit::draw()
{
	const Transform& camera = Camera::getCurrentView();

	if (m_transform.touches(camera))
	{
		double relx = 0, rely = 0;
		m_transform.getRelativeCoords(camera, relx, rely);

		m_animator.draw(relx, rely);
	}
	//m_animator.getImg();
}

