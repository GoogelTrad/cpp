/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:35 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/12 15:50:18 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->setRawBits(0);
}

Fixed::Fixed(const int convert)
{
	this->entier = convert << this->bits;
}

Fixed::Fixed(const float val)
{
	this->entier = roundf(val * (1 << this->bits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &copie)
{
	entier = copie.entier;
}

void Fixed::operator=(const Fixed &copie)
{
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

//Operateur de comparaison

bool Fixed::operator>(const Fixed &copie) const
{
	return (this->entier > copie.getRawBits());
}

bool Fixed::operator>=(const Fixed &copie) const
{
	return (this->entier >= copie.getRawBits());
}

bool Fixed::operator<=(const Fixed &copie) const
{
	return (this->entier <= copie.getRawBits());
}

bool Fixed::operator<(const Fixed &copie) const
{
	return (this->entier < copie.getRawBits());
}

bool Fixed::operator==(const Fixed &copie) const
{
	return (this->entier == copie.getRawBits());
}

bool Fixed::operator!=(const Fixed &copie) const
{
	return (this->entier != copie.getRawBits());
}

//Operateur arithmetique

Fixed Fixed::operator+(const Fixed &copie)
{
	return ((Fixed)(this->toFloat() + copie.toFloat()));
}

Fixed Fixed::operator-(const Fixed &copie)
{
	return ((Fixed)(this->toFloat() - copie.toFloat()));
}

Fixed Fixed::operator*(const Fixed &copie)
{
	return ((Fixed)((float)this->toFloat() * (float)copie.toFloat()));
}

Fixed Fixed::operator/(const Fixed &copie)
{
	return ((Fixed)((float)this->toFloat() / (float)copie.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	this->entier++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed fixed(*this);
	++(this->entier);

	return fixed;
}

Fixed &Fixed::operator--(void)
{
	this->entier--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed fixed(*this);
	--(this->entier);

	return fixed;	
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first < second)
		return first;
	else
		return second;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first > second)
		return first;
	else
		return second;
}

const Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first < second)
		return first;
	else
		return second;
}

const Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
		return first;
	else
		return second;
}