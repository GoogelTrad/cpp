/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:44:15 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/25 22:44:15 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	int a = 5;
	int b = 10;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "a swap = " << a << ", b swap = " << b << std::endl;

	std::cout << std::endl;

	a = 5;
	b = 10;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min = " << min(a, b) << std::endl;
	std::cout << "max = " << max(a, b) << std::endl;
}