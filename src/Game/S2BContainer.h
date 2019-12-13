#ifndef S2BCONTAINER_H
#define S2BCONTAINER_H

#include "GameContainer.h"
#include "GameMap.h"
#include "Camera.h"

struct KeyboardEvent;
struct MouseEvent;
struct TouchEvent;

class Unit;

/** The game container specific to Stiek2Bellum */
class S2BContainer : public GameContainer
{
	///FOR TESTING PURPOSES
	protected:
		Unit *m_testUnit;

	protected:
		GameMap m_map;
		Camera m_camera;

		virtual void onKeyboardEvent(const KeyboardEvent& event);
		virtual void onMouseEvent(const MouseEvent& event);
		virtual void onTouchEvent(const TouchEvent& event);

		virtual void playerUpdate();

	public:
		S2BContainer(long _width, long _height);
		virtual ~S2BContainer();

		//no copy ctor or assignment
		S2BContainer(const S2BContainer&) = delete;
		S2BContainer& operator=(const S2BContainer&) = delete;

		// TODO: this changed to the init protected func
		virtual void start();

		virtual double maximumX() { return mapWidth(); }
		virtual double maximumY() { return mapHeight(); }

		void setMap(const GameMap& val) { m_map = val; }

		long mapWidth() const { return m_map.width(); }
		long mapHeight() const { return m_map.height(); }

		long mapTileWidth() const { return m_map.tileWidth(); }
		long mapTileHeight() const { return m_map.tileHeight(); }

};

#endif // S2BCONTAINER_H
