#include "ATM_Dispatcher.hpp"

ATM_Dispatcher::ATM_Dispatcher(const Messenger& port) : _port(port) {}

void ATM_Dispatcher::forwardMessage(const Message& message) {
    //types
}

void ATM_Dispatcher::registerComponent(std::set<MessageId> types, std::shared_ptr<Component> component) {
    if(next)
        next->add(std::make_unique<ATM_Handler>(types,component));
    else
        next = std::make_unique<ATM_Handler>(types,component); 
}
