/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:41:34 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/23 23:41:34 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFname()
{
	return first_name;
}

std::string Contact::getLname()
{
	return last_name;
}

std::string Contact::getNickname()
{
	return nickname;
}

std::string Contact::getPhone()
{
	return phone_nb;
}

std::string Contact::getSecret()
{
	return secret;
}

void Contact::setFname(std::string first_name)
{
	this->first_name = first_name;
}

void Contact::setLname(std::string last_name)
{
	this->last_name = last_name;
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contact::setPhone(std::string phone_nb)
{
	this->phone_nb = phone_nb;
}

void Contact::setSecret(std::string secret)
{
	this->secret = secret;
}