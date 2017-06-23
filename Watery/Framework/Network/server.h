//
// Created by Mike Smith on 2017/6/18.
//

#ifndef WATERY_SERVER_H
#define WATERY_SERVER_H

#include <map>
#include <string>
#include "network.h"

class Server : public Network
{
private:
	std::map<std::string, asio::ip::udp::endpoint *> _clients;
	void add_client(const asio::ip::udp::endpoint &client);

public:
	Server(const std::string &ip, unsigned short port);
	virtual ~Server(void) override;
	virtual const std::string receive(void) override;
	virtual void send(const std::string &str) override;
};

#endif  // WATERY_SERVER_H
