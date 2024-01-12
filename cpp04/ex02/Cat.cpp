/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:32:48 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/19 15:32:48 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	cerveau = new Brain();
	std::cout << "Default Cat constructor called" << std::endl;
	this->setType("Cat");
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete cerveau;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat sounds" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	this->type = copy.type;

	return *this;
}