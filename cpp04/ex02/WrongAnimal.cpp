/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:38:58 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/20 23:38:58 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "Wrong Animal";
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.getType())
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong Animals sounds" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->type = copy.type;

	return *this;
}