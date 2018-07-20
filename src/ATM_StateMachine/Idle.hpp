#pragma once
#include "State.hpp"

namespace FSM
{

class Idle : public DeviceState
{
public:
    Idle(StateTransitionFunc stateTransitionFunc,
         std::shared_ptr<std::string> sharedTaskName)
        :DeviceState(stateTransitionFunc, sharedTaskName)
    {}

    void runTask(const Message& msg) override
    {
        switch(msg.type) {
            case MessageId::CardInsertion: 
                stateTransition(State::VALIDATING); 
                break;
            default: {
                std::cout << "no state change" << std::endl;
                break;
            }
        }
    }
};

}
