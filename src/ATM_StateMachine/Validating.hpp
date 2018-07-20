#pragma once
#include "State.hpp"
#include <memory>

namespace FSM
{

class Validating : public DeviceState
{
public:
    Validating(StateTransitionFunc stateTansitionFunc,
         std::shared_ptr<std::string> sharedTaskName)
        :DeviceState(stateTansitionFunc, sharedTaskName)
    {}

    void runTask(const Message& msg) override
    {
        switch(msg.type) {
            case MessageId::PinVerification: 
            {
                
                stateTransition(State::PROCESSING); 
                break;
            }
                
            case MessageId::IncorrectPin: 
            case MessageId::CardBanned: 
                stateTransition(State::IDLE); break;
            default: {
                std::cout << "no action" << std::endl;
                break;
            }
        }
    }
};

}
