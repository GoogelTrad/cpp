/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:22 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/06 16:25:00 by cmichez          ###   ########.fr       */
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
	void operator=(const Fixed &copie);
	Fixed(const Fixed &copie);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	~Fixed();
};

std::ostream &operator<<(std::ostream &stream, const Fixed &val);