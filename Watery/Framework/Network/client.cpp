//
// Created by Mike Smith on 2017/6/18.
//

#include <iostream>
#include "client.h"

Client::Client(const std::string &server_ip, unsigned short port) : Network(server_ip, port) {}

void Client::send(const std::string &str)
{
	_socket->send_to(asio::buffer(str.c_str(), str.size() + 1), *_endpoint);
}

const std::string Client::receive(void)
{
	char buffer[1024];
	
	_socket->receive_from(asio::buffer(buffer, 1024), *_endpoint);
	return std::string(buffer);
}
