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
        switch(msg.type) {
            case MessageId::CardInsertion: 
            {
                if(_bankConnection->isCardActive(msg.content)) {
                    std::cout << "card valid" << std::endl;
                    stateTransition(State::VALIDATING); 
                }
                else 
                    std::cout << "card invalid" << std::endl;
                // logg info that card is invalid
                break;
            }
                
            default: {
                std::cout << "no state change" << std::endl;
                //logg the unexepcted behaviour
                break;
            }
        }
    }
};