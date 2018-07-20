#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

enum MessageId
{
    CardInsertion ,
    PinVerification,
    Withdraw,
    AccountBalance,
    CancelTransaction,
    CardEjection,
    IncorrectPin,
    CardBanned,
    LackOfFounds,
};

struct Message
{
    MessageId type;
    std::string content;
};

#endif //MESSAGE_H
