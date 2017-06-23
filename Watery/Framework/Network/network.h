//
// Created by Mike Smith on 2017/6/18.
//

#ifndef WATERY_NETWORK_H
#define WATERY_NETWORK_H

#include "../ASIO/asio.hpp"

class Network
{
protected:
	asio::io_service *_io_service;
	asio::ip::udp::endpoint *_endpoint;
	asio::ip::udp::socket *_socket;

public:
	Network(const std::string &ip, unsigned short port);
	virtual ~Network(void);
	virtual void send(const std::string &str) = 0;
	virtual const std::string receive(void) = 0;
};

#endif  // WATERY_NETWORK_H
