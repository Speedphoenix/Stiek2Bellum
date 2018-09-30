#ifndef TESTANIMATION_H
#define TESTANIMATION_H

#include <DiscreetAnimation.h>


class TestAnimation : public DiscreetAnimation
{
	///FOR TESTING PURPOSES
	public:
		void maketest(int type = 0);

	public:
		TestAnimation();
		virtual ~TestAnimation();
};

#endif // TESTANIMATION_H
