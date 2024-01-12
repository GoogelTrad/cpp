/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:51:39 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/23 22:51:39 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int ac, char **av)
{
	int i = 1;
	int j;

	if (ac > 1)
	{
		while (av[i])
		{
			j = 0;
			if (av[i][j] == ' ' && (j == 0 || j == (strlen(av[i]) - 1)))
				j++;
			while (av[i][j])
				std::cout << static_cast<char>(std::toupper(av[i][j++]));
			if (av[i + 1])
				std::cout << " ";
			else
				std::cout << std::endl;
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBERABLE FEEDBACK NOISE *" << std::endl;
	return 1;
}