#ifndef TESTBEHAVE_H
#define TESTBEHAVE_H

#include <Behaviour.h>

class TestBehave : public Behaviour
{
    protected:
        int a;

    public:
        TestBehave(GameObject *attachTo);
        virtual ~TestBehave();

        virtual void start();
        virtual void update();
};

#endif // TESTBEHAVE_H
