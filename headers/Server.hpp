/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:37:00 by ezequeil          #+#    #+#             */
/*   Updated: 2022/12/09 22:35:48 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP


#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include "Socket.hpp"
#include "Channel.hpp"

class Server: public Socket {

	private:
		std::map<String, Channel *> _channels;

	public:
		Server();
		Server(std::string name, int port);
		~Server();
		void send(Client *client, std::string data, std::string color = "\033[0m");
		void connect(Client *client, String data);
		void msg(Client *client, String data);
		void help(Client *client, String data);
		void nick(Client *client, String data);
		void join(Client *client, String data);
		void execute(Client *client, std::string event, String data = "");
		void response(Client *client);
		void leave(Client *client, String data);
	
};

typedef void (Server::*functionsd)(void *data);

#endif
