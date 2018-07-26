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
        MessageId new_message_type;
        std::stringstream new_message_content;
        if(msg.type == MessageId::PinVerification) {
            if(_bankConnection->isPinValid(msg.content)) {
                new_message_type = MessageId::PinVerified;
                new_message_content << "Pin verfied";
                stateTransition(State::PROCESSING);
            }
            else {
                new_message_type = MessageId::IncorrectPin;
                new_message_content << "Incorrect Pin";
                stateTransition(State::IDLE);
            }
        }
        //else throw std::exception();
        
        _port->addMessage({new_message_type,new_message_content.str()});
    }
};