#ifndef STATE_H
#define STATE_H

// do not remove QDebug from the includes the derived state
// classes most probably print debugging messages
#include <QDebug>

class SodaMachine;

class StateInterface
{
public:
    virtual void enter() = 0;
    virtual void exit() = 0;

protected:


};

Q_DECLARE_INTERFACE(StateInterface, "de.slopjong.StateInterface/1.0")

#endif // STATE_H
