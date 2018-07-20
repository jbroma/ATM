#include <iostream>
#include "ATM_StateMachine/FsmDevice.hpp"
#include "Message.h"
#include "ATM_MessagePort/ATM_MessagePort.hpp"
#include "ATM_Dispatcher/ATM_Dispatcher.hpp"
#include "Bank.h"

int main()
{
    //proper init
    ATM_MessagePort port;
    ATM_Dispatcher dispatcher(port);
    auto bank = std::make_unique<Bank>();
    FSM::Device dev(bank,port);
    //iks


    // std::cout << "Hello world" << std::endl;
    // auto device = std::make_unique<FSM::Device>();
    // device->handle({MessageId::CardInsertion, "wolololo"});
    return 0;
}
