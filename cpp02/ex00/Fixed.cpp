/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:35 by cmichez           #+#    #+#             */
/*   Updated: 2024/02/24 01:56:01 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copie)
{
	std::cout << "Copy constructor called" << std::endl;
	entier = copie.getRawBits();
}

void Fixed::operator=(const Fixed &copie)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->setRawBits(copie.getRawBits());
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->entier;
}

void Fixed::setRawBits(int const raw)
{
	this->entier = raw;
}