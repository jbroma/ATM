#pragma once
#include <string>
#include <functional>
#include <iostream>
#include <memory>
#include <map>
#include "../Message.h"

namespace FSM
{

enum State
{
    IDLE = 1,
    VALIDATING = 2,
    PROCESSING = 3
};


typedef std::function<void (State)> StateTransitionFunc;

class DeviceState
{
public:
    DeviceState(StateTransitionFunc stateTransitionFunc,
                std::shared_ptr<std::string> taskName)
        : stateTransitionFunc(stateTransitionFunc),
          taskName(taskName)
    {}

    virtual void runTask(const Message& msg) = 0;

    virtual ~DeviceState() {}

private:
   StateTransitionFunc stateTransitionFunc;

protected:
    void stateTransition(State newState)
    {
        //std::cout << "DEBUGLOG: state transition to:" << newState << "\n";
        stateTransitionFunc(newState);
    }
    std::shared_ptr<std::string> taskName;
};

}

