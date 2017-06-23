//
// Created by Mike Smith on 2017/6/18.
//

#include "network.h"

Network::Network(const std::string &ip, unsigned short port)
{
	_io_service = new asio::io_service;
	_socket = new asio::ip::udp::socket(*_io_service);
	_endpoint = new asio::ip::udp::endpoint(asio::ip::address_v4::from_string(ip), port);
	_socket->open(_endpoint->protocol());
}

Network::~Network(void)
{
	delete _io_service;
	delete _socket;
	delete _endpoint;
}
