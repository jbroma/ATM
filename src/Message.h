#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

enum MessageId
{
    CardInsertion ,
    PinVerification,
    PinVerified,
    Withdraw,
    AccountBalance,
    CancelTransaction,
    CardEjection,
    IncorrectPin,
    CardValid,
    CardBanned,
    LackOfFounds,
};

struct Message
{
    MessageId type;
    std::string content;
};

#endif //MESSAGE_H
