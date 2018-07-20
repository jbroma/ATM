#pragma once
#include "HandlerBase.hpp"

class ATM_Handler : public Handler {
    
    std::set<MessageId> _types;
    std::shared_ptr<Component> _comp;

    public:
    ATM_Handler(std::set<MessageId> types, std::shared_ptr<Component> comp) : _types(types), _comp(comp) {}

    void handle(const Message& msg) override { 
        if(_types.find(msg.type) != _types.end())
            _comp->handle(msg);
        else next->handle(msg);
    }
};