#pragma once
#include "State.hpp"

class Idle : public DeviceState
{
public:
    Idle(StateTransitionFunc stateTransitionFunc,
        std::shared_ptr<Bank> bank,
        std::shared_ptr<Messenger> port)
        :DeviceState(stateTransitionFunc, bank, port)
    {}

    void runTask(const Message& msg) override
    {
        MessageId new_message_type;
        std::stringstream new_message_content;
        if(msg.type == MessageId::CardInsertion) {
                if(_bankConnection->isCardActive(msg.content)) {
                    new_message_content << msg.content << " : VALID";
                    new_message_type = MessageId::PinVerification;
                    stateTransition(State::VALIDATING);
                }
                else {
                    new_message_content << msg.content << " : INVALID";
                    new_message_type = MessageId::CardBanned;
                    _port->addMessage({new_message_type,new_message_content.str()});
                    new_message_content.str(std::string{});
                    new_message_content.clear();
                    new_message_content << "Card Ejection";
                    new_message_type = MessageId::CardEjection;
                }
        }
        //else throw std::exception();
        _port->addMessage({new_message_type,new_message_content.str()});
    }
};