#pragma once
#include <functional>
#include <map>
#include "Message.h"

typedef std::function<void (const Message& msg)> HandlerFunc;

class Observer
{
public:
    Observer()
        :nextAvailableId(0)
    {}

    unsigned connect(HandlerFunc handler)
    {
        handlers[nextAvailableId] = handler;
        return nextAvailableId++;
    }

    void disconnect(unsigned id)
    {
        handlers.erase(id);
    }

    void send(const Message& msg)
    {
        for (auto h : handlers)
        {
            h.second(msg);
        }
    }

private:
    std::map<unsigned, HandlerFunc> handlers;
    unsigned nextAvailableId;
};