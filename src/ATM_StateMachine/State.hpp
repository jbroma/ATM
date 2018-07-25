#pragma once
#include <string>
#include <functional>
#include <iostream>
#include <memory>
#include <map>
#include <sstream>
#include "../Message.h"
#include "../Bank.h"
#include "../MessagePort.h"

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
                std::shared_ptr<Bank> bank,
                std::shared_ptr<Messenger> port)
        : _stateTransitionFunc(stateTransitionFunc),
        _bankConnection(bank),
        _port(port)
    {}

    virtual void runTask(const Message& msg) = 0;

    virtual ~DeviceState() {}

private:
   StateTransitionFunc _stateTransitionFunc;
   

protected:
    void stateTransition(State newState)
    {
        //std::cout << "DEBUGLOG: state transition to:" << newState << "\n";
        _stateTransitionFunc(newState);
    }
    std::shared_ptr<Bank> _bankConnection;
    std::shared_ptr<Messenger> _port;
};
