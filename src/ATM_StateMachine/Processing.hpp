#pragma once
#include "State.hpp"
#include <string>
#include <memory>

namespace FSM
{

class Processing : public DeviceState
{
public:
    Processing(StateTransitionFunc stateTransitionFunc,
          std::shared_ptr<std::string> sharedTaskName)
        : DeviceState(stateTransitionFunc, sharedTaskName)

    {}

    void runTask(const Message& msg) override
    {
        switch(msg.type) {
            case MessageId::Withdraw: 
            case MessageId::AccountBalance: 
            case MessageId::CancelTransaction:
                stateTransition(State::IDLE); break;
            default: {
                std::cout << "no state change" << std::endl;
                break;
            }
        }
    }
};

}
