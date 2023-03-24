/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:32:55 by edos-san          #+#    #+#             */
/*   Updated: 2023/03/20 21:15:26 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "File.hpp"
#include "Console.hpp"
#include "Channel.hpp"

typedef std::string String;

typedef struct pollfd t_socket;

class Client {

	private:		  
		int					  _fd;
		int					  _index_fd;
		std::string 		  _nickname;
		std::string			  _username;
		std::string			  _realname;
		std::string			  _password;

		Console				  _console;
		Channel 			 *_channel;

	public:
		Client();
		Client(int fd, int index);
		~Client();
		bool isConnect;
		void receiver();
		bool run();
		void setNickname(const std::string& nickname);
		bool	isValid();

		void setChannel(Channel *channel)
		{
			_channel = channel;
		};

		Channel *getChannel()
		{
			return _channel;
		};

		std::string &getNickname(){
			return _nickname;
		};

		std::string &getPassword(){
			return _password;
		};

		void setPassword(const std::string& data){
			_password = data;
		};

		void setRealname(const std::string& realname){
			_realname = realname;
		};

		void setUsername(const std::string& username){
			_username = username;
		};

		std::string &getUsername(){
			return _username;
		};

		int getFd(){
			return _fd;
		};

		int getIndexFd(){
			return _index_fd;
		};

		static bool isNickname(std::map<int, Client *> clients, Client *client);
};
#endif
