#include "TestAnimator.h"

#include "TestAnimation.h"

using namespace std;

TestAnimator::TestAnimator(GameObject* attachTo, double lapse, GeneralState startState, double startDirection)
	:Animator(attachTo, lapse, startState, startDirection)
{
	//ctor
}

TestAnimator::~TestAnimator()
{
	//dtor
}

///FOR TESTING PURPOSES
void TestAnimator::maketest()
{
	//this method doesn't really care about optimization
	Transition newAnimKey;

	TestAnimation* newAnim;

	newAnimKey = Transition(Walking, Anim::Idle, false);
	newAnim = new TestAnimation();
	newAnim->maketest(0); //idle
	m_animations[newAnimKey] = newAnim;

	newAnimKey = Transition(Walking, Anim::Active, false);
	newAnim = new TestAnimation();
	newAnim->maketest(1); //active
	m_animations[newAnimKey] = newAnim;

	newAnimKey = Transition(Attacking, Anim::Idle, false);
	newAnim = new TestAnimation();
	newAnim->maketest(2); //active
	m_animations[newAnimKey] = newAnim;

	newAnimKey = Transition(Attacking, Anim::Active, false);
	newAnim = new TestAnimation();
	newAnim->maketest(3); //active
	m_animations[newAnimKey] = newAnim;

	m_currState = Transition(Walking, Anim::Idle, false);
}
