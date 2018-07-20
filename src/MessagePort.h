#pragma once

#include <string>
#include <vector>
#include "Message.h"

class Messenger
{
public:
	virtual ~Messenger() = default;

	virtual void addMessage(const Message& message) = 0;
	virtual std::vector<Message> collectMessages(const std::string& receiver) = 0;
	
	//onMessageReceived
};
