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

Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phone_nb = "";
	secret = "";
	indexNow = 0;
}

Contact::~Contact()
{
}

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

int Contact::getIndex()
{
	return indexNow;
}

void Contact::setIndex(int incr)
{
	this->indexNow += incr;
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

std::string Contact::cutStr(std::string str)
{
	std::string tmp;

	if (str.size() == 10)
		return tmp;
	else if (str.size() < 9)
	{
		for (int i = 0; i < 10 - str.size(); i++)
			tmp.push_back(' ');
		tmp += str;
	}
	else
	{
		for (int i = 0; i < 9; i++)
			tmp.push_back(str.at(i));
		tmp.push_back('.');
	}
	return tmp;
}

std::string Contact::affInfo(void)
{
	std::string tmp;

	tmp += this->cutStr(this->getFname());
	tmp.push_back('|');
	tmp += this->cutStr(this->getLname());
	tmp.push_back('|');
	tmp += this->cutStr(this->getNickname());
	tmp.push_back('|');

	return tmp;
}