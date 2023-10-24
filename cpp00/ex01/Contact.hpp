/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:41:32 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/23 23:41:32 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_nb;
	std::string secret;
public:
	Contact();
	std::string getFname();
	std::string getLname();
	std::string getNickname();
	std::string getPhone();
	std::string getSecret();
	void setFname(std::string first_name);
	void setLname(std::string last_name);
	void setNickname(std::string nickname);
	void setPhone(std::string phone_nb);
	void setSecret(std::string secret);
	~Contact();
};

Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_nb = "";
	secret = "";
}

Contact::~Contact()
{
}

#endif