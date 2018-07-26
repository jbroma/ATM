#pragma once
#include "../MessagePort.h"
#include "../Observer.hpp"

class ATM_MessagePort : public Messenger, public Observer {
    
    public:
    ATM_MessagePort() = default;
    void addMessage(const Message& message) override {}
	std::vector<Message> collectMessages(const std::string& receiver) {}

    






};