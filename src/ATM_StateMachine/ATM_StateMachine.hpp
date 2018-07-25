#pragma once
#include <string>
#include <memory>
#include <map>
#include <functional>
#include "State.hpp"
#include "Idle.hpp"
#include "Validating.hpp"
#include "Processing.hpp"
#include "../Component.h"
#include "../Bank.h"
#include "../MessagePort.h"

class ATM_StateMachine : public Component
{
public:

    ATM_StateMachine(std::shared_ptr<Bank> bank, std::shared_ptr<Messenger> port ) : _bank(bank), _port(port)
    {
        createStatesMap();
        currentState = allStates[State::IDLE];
    }

    void handle(const Message& msg) override
    {
        currentState->runTask(msg);
    }

private:
    void createStatesMap()
    {
        StateTransitionFunc transition = [this](State state)
        {
            this->currentState = allStates[state];
        };

        allStates[State::IDLE] = std::make_shared<Idle>(transition, _bank, _port);
        allStates[State::VALIDATING] = std::make_shared<Validating>(transition, _bank, _port);
        allStates[State::PROCESSING] = std::make_shared<Processing>(transition, _bank, _port);
    }

    std::map<State, std::shared_ptr<DeviceState>> allStates;
    std::shared_ptr<DeviceState> currentState;
    std::shared_ptr<Bank> _bank;
    std::shared_ptr<Messenger> _port;
};
