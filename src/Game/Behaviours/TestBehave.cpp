#include "TestBehave.h"

#include "GameObject.h"

TestBehave::TestBehave(GameObject *attachTo)
	:Behaviour(attachTo), a(0)
{
	//ctor
}

TestBehave::~TestBehave()
{
	//dtor
}

void TestBehave::start()
{
	a = 600;
}

void TestBehave::update()
{
	a--;
	if (a <= 0)
	{
		attachedObject()->setToRemove();
	}
	else if ((a % 200) == 0)
	{
		attachedObject()->getTransform().setAbsPos(500, 400);
	}
}


