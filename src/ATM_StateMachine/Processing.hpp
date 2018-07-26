#pragma once
#include "State.hpp"
#include <string>
#include <memory>

class Processing : public DeviceState
{
public:
    Processing(StateTransitionFunc stateTransitionFunc,
        std::shared_ptr<Bank> bank,
        std::shared_ptr<Messenger> port)
        :DeviceState(stateTransitionFunc, bank, port)
    {}

    void runTask(const Message& msg) override
    {
        MessageId new_message_type;
        std::stringstream new_message_content;
        switch(msg.type) {
            case MessageId::Withdraw: {
                if(_bankConnection->isWidthdrawAccepted(msg.content)) {
                    new_message_type = MessageId::CardEjection;
                    new_message_content << "Withdraw accepted";
                }
                else {
                    new_message_type = MessageId::LackOfFounds;
                    new_message_content << "Withdraw denied: Lack of Funds";
                }
                stateTransition(State::IDLE);
                break;
            }
            case MessageId::AccountBalance: {
                new_message_type = MessageId::CardEjection;
                new_message_content << "Your account balance is :" << _bankConnection->getAccountBalance();
                stateTransition(State::IDLE);
                break;
            }
            case MessageId::CancelTransaction: {
                new_message_type = MessageId::CardEjection;
                new_message_content << "Transaction cancelled";
                stateTransition(State::IDLE);
                break;
            }
                
            default: {
                //throw std::exception();
            }
        }
        _port->addMessage({new_message_type,new_message_content.str()});
    }
};
