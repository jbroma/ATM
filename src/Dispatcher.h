#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "Message.h"
#include "Component.h"
#include <set>
#include <memory>

class Dispatcher
{
public:
    virtual ~Dispatcher() = default;

    // this is equivalent to adding new link in a chain
    virtual void registerComponent(std::set<MessageId> types, std::shared_ptr<Component> component) = 0; //how about reference instead of shared_ptr?
    
    // this is the function to be called when its not possible to handle the message
    virtual void forwardMessage(const Message& message) = 0;
};

#endif //DISPATCHER_H
