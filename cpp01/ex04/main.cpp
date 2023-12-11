/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 23:32:50 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/27 23:32:50 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Numbers of arg invalid\n";
		return 0;
	}

	std::string filename;
	std::string replace;
	std::string s1;
	std::string s2;

	filename = av[1];
	s1 = av[2];
	s2 = av[3];


	std::fstream fd;
	std::ifstream fds;

	fds.open(filename, std::fstream::in);
	if (!fds)
	{
		std::cout << filename << " does not exist\n";
		return 0;
	}

	char c;
	while (fds.get(c))
		replace += c;
	
	fds.close();

	size_t tmp;
	if (s1.compare(s2) != 0)
	{
		tmp = replace.find(s1);
		while (tmp != std::string::npos)
		{
			replace.erase(tmp, s1.size()).insert(tmp, s2);
			tmp = replace.find(s1);
		}
	}
	fd.open(filename + ".replace", std::fstream::out);
	fd << replace;

	fd.close();
}