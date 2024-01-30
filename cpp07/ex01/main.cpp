/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:01:33 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/25 23:01:33 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print_char(char c)
{
	std::cout << c;
}

void toUpper(char *str)
{
	while (str && *str)
		print_char(std::toupper(*str++));
	std::cout << std::endl;
}

void square(int nb)
{
	std::cout << "Result of the square root for " << nb << " is " << nb * nb << std::endl;
}

int main(void)
{
	int root[] = {2, 4, 6, 9};

	::iter(root, 4, square);

	char *s = (char *)"coucou";

	::iter(&s, 1, toUpper);
}