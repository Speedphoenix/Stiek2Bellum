#include "GameMap.h"
GameMap * GameMap::m_currentInstance = nullptr;

GameMap::GameMap(long _width, long _height)
	:m_width(_width), m_height(_height)
{
	if (!m_currentInstance)
		m_currentInstance = this;
}

GameMap::~GameMap()
{
	//dtor
}

