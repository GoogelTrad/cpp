/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:40:03 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/20 23:40:03 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	this->setType("Wrong Cat");
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong Cat sounds" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	this->type = copy.type;

	return *this;
}