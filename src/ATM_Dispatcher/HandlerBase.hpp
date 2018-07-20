#pragma once
#include <set>
#include "../Message.h"

class Handler {

protected:
      std::unique_ptr<Handler> next;

public:
    
    void add(std::unique_ptr<Handler> link) {
        if(next)
            next->add(std::move(link));
        else
            next = std::move(link);
    }

    virtual void handle(const Message &m) {
            next->handle(m);
    }

    virtual ~Handler() = default;
};