#pragma once
#include "../MessagePort.h"
#include "../Observer.hpp"

class ATM_MessagePort : public Messenger, public Observer {
    
    void addMessage(const Message& message) override {
        send(message);
    };

    






};