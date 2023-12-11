/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:22 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/01 00:08:06 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
private:
	static const int bits = 8;
	int entier;
public:
	Fixed();
	void operator=(const Fixed &copie);
	Fixed(const Fixed &copie);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	~Fixed();
};

