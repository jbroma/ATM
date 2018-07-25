#pragma once
#include "State.hpp"
#include <memory>

class Validating : public DeviceState
{
public:
    Validating(StateTransitionFunc stateTransitionFunc,
        std::shared_ptr<Bank> bank,
        std::shared_ptr<Messenger> port)
        :DeviceState(stateTransitionFunc, bank, port)
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