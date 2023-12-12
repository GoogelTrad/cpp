/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:35 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/11 19:22:21 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->setRawBits(0);
}

Fixed::Fixed(const int convert)
{
	std::cout << "Int constructor called\n";
	this->entier = convert << this->bits;
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called\n";
	this->entier = roundf(val * (1 << this->bits));
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
	return this->entier;
}

void Fixed::setRawBits(int const raw)
{
	this->entier = raw;
}

float Fixed::toFloat(void) const
{
	return (float) this->entier / (1 << this->bits);
}

int Fixed::toInt(void) const
{
	return (int) this->entier >> this->bits;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &val)
{
	stream << val.toFloat();
	return stream;
}