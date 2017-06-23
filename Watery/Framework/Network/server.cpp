//
// Created by Mike Smith on 2017/6/18.
//

#include <iostream>
#include "server.h"

Server::Server(const std::string &ip, unsigned short port) : Network(ip, port)
{
	_socket->bind(*_endpoint);
}

Server::~Server(void)
{
	for (auto client_item : _clients)
	{
		delete client_item.second;
	}
}

const std::string Server::receive(void)
{
	char buffer[1024];
	asio::ip::udp::endpoint sender;
	
	_socket->receive_from(asio::buffer(buffer, 1024), sender);
	add_client(sender);
	
	return std::string(buffer);
}

void Server::add_client(const asio::ip::udp::endpoint &client)
{
	std::string client_ip = client.address().to_string();
	
	if (!_clients.count(client_ip))
	{
		_clients.emplace(client_ip, new asio::ip::udp::endpoint(client));
		std::cout << "Added client: " << client_ip << std::endl;
	}
}

void Server::send(const std::string &str)
{
	for (auto client_item : _clients)
	{
		_socket->send_to(asio::buffer(str.c_str(), str.size() + 1), *client_item.second);
	}
}
