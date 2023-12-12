/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:22 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/12 15:18:03 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <ostream>
#include <cmath>

class Fixed
{
private:
	static const int bits = 8;
	int entier;
public:
	Fixed();
	Fixed(const int convert);
	Fixed(const float val);
	Fixed(const Fixed &copie);
	
	void operator=(const Fixed &copie);
	bool operator>(const Fixed &copie) const;
	bool operator<(const Fixed &copie) const;
	bool operator>=(const Fixed &copie) const;
	bool operator<=(const Fixed &copie) const;
	bool operator==(const Fixed &copie) const;
	bool operator!=(const Fixed &copie) const;

	Fixed operator+(const Fixed &copie);
	Fixed operator-(const Fixed &copie);
	Fixed operator*(const Fixed &copie);
	Fixed operator/(const Fixed &copie);
	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	
	const static Fixed &min(const Fixed &first, const Fixed &second);
	const static Fixed &max(const Fixed &first, const Fixed &second);
	const static Fixed &min(Fixed &first, Fixed &second);
	const static Fixed &max(Fixed &first, Fixed &second);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	
	~Fixed();
};

std::ostream &operator<<(std::ostream &stream, const Fixed &val);