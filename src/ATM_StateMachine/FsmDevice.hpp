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
#include "../ATM_MessagePort/ATM_MessagePort.hpp"

namespace FSM
{

class Device : public Component
{
public:

    Device(const Bank& bankConnection, const ATM_MessagePort& port ) : _bank(bankConnection), _port(port)
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

        auto sharedName = std::make_shared<std::string>();

        allStates[State::IDLE] = std::make_shared<Idle>(transition, sharedName);
        allStates[State::VALIDATING] = std::make_shared<Validating>(transition, sharedName);
        allStates[State::PROCESSING] = std::make_shared<Processing>(transition, sharedName);
    }

    std::map<State, std::shared_ptr<DeviceState>> allStates;
    std::shared_ptr<DeviceState> currentState;
    const Bank& _bank;
    const ATM_MessagePort& _port;
};

}
