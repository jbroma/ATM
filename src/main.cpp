#include <iostream>
#include "ATM_StateMachine/ATM_StateMachine.hpp"
#include "Message.h"
#include "ATM_MessagePort/ATM_MessagePort.hpp"
#include "ATM_Dispatcher/ATM_Dispatcher.hpp"
#include "Bank.h"

int main()
{
    //proper init
    auto bank = std::make_shared<Bank>();
    auto port = std::make_shared<ATM_MessagePort>();
    //ATM_Dispatcher dispatcher(port);
    auto atm = std::make_unique<ATM_StateMachine>(bank,port);
    //iks


    // std::cout << "Hello world" << std::endl;
    // auto device = std::make_unique<FSM::Device>();
    // device->handle({MessageId::CardInsertion, "wolololo"});

   //ATM FSM test
   Message WrongCard(CardInsertion, "134");
   Message CorrectCard(CardInsertion, "123456");
   Message WrongPIN(PinVerification, "1111");
   Message CorrectPIN(PinVerification, "9876");
   Message Balance( AccountBalance, "sfdsf");
   Message WrongWithdraw(Withdraw, "3000000");
   Message CorrectWithdraw(Withdraw, "20");
   try {
       atm.handle(WrongCard);
   }
   catch(...){}
   atm.handle(CorrectCard);
   try{
       atm.handle(WrongPIN);
   }
   catch(...){}
   atm.handle(CorrectPIN);
   atm.handle(Balance);
   atm.handle(CorrectCard);
   atm.handle(CorrectPIN);
   atm.handle(CorrectWithdraw);
   atm.handle(CorrectCard);
   atm.handle(CorrectPIN);
   atm.handle(WrongWithdraw);
    return 0;
}
