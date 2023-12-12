/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:09 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/12 15:31:20 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;

	std::cout << "b = " << b << std::endl;

	std::cout << "div = " << Fixed(10) / Fixed(5) << std::endl;
	std::cout << "add = " << Fixed(10) + Fixed(5) << std::endl;
	std::cout << "minus = " << Fixed(10) - Fixed(5) << std::endl;
	
	std::cout << "max = " << Fixed::max( a, b ) << std::endl;
	
	return 0;
}