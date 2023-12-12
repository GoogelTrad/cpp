/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:35 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/11 19:06:35 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->setRawBits(0);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &copie)
{
	std::cout << "Copie constructor called\n";
	entier = copie.entier;
}

void Fixed::operator=(const Fixed &copie)
{
	std::cout << "Copy assigment operator called\n";
	this->setRawBits(copie.getRawBits());
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return this->entier;
}

void Fixed::setRawBits(int const raw)
{
	this->entier = raw;
}