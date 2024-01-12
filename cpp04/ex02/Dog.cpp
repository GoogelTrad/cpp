/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:33:37 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/19 15:33:37 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	cerveau = new Brain();
	std::cout << "Default Dog constructor called" << std::endl;
	this->setType("Dog");
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete cerveau;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog sounds" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	this->type = copy.type;

	return *this;
}