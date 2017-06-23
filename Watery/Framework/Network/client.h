/// @file client.h
/// @brief Header file for class Client.
/// @author YJY
/// @date June 18, 2017

#ifndef WATERY_CLIENT_H
#define WATERY_CLIENT_H

#include "network.h"

class Client : public Network
{
public:
	Client(const std::string &server_ip, unsigned short port);
	virtual ~Client(void) override {}
	virtual void send(const std::string &str) override;
	virtual const std::string receive(void) override;
};

#endif  // WATERY_CLIENT_H
