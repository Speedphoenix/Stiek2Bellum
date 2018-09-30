#ifndef TESTANIMATOR_H
#define TESTANIMATOR_H

#include <Animator.h>

#include "game_config.h"

class TestAnimator : public Animator
{
	public:
		TestAnimator(GameObject* attachTo, double lapse = defaultIdleLapse, GeneralState startState = Walking, double startDirection = 0);
		virtual ~TestAnimator();

		///FOR TESTING PURPOSES
		void maketest();
};

#endif // TESTANIMATOR_H
