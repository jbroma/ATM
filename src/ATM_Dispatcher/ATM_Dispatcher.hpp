#pragma once
#include "../Dispatcher.h"
#include "../MessagePort.h"
#include "ATM_Handler.hpp"
#include <iostream>

class ATM_Dispatcher : public Dispatcher {

    public:
    ATM_Dispatcher(std::shared_ptr<MessagePort> port);
    void forwardMessage(const Message& msg) override;
    void registerComponent(std::set<MessageId> types, std::shared_ptr<Component> component) override;
    virtual ~ATM_Dispatcher() = default;

    private:
    
    std::shared_ptr<MessagePort> _port;
    std::unique_ptr<Handler> next;
};