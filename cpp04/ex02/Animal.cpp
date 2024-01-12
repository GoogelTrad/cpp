/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:31:04 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/19 15:31:04 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Default Animal constructor called" << std::endl;
	type = "Animal";
}

Animal::Animal(const Animal &copy) : type(copy.getType())
{
	std::cout << "Copy Animal constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::setType(std::string type)
{
	this->type = type;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal sounds" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	this->type = copy.type;

	return *this;
}