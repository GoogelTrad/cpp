/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:43:26 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/25 18:43:26 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	std::srand(static_cast<unsigned>(time(0)));
	int random = std::rand();
	if (random % 3 == 0)
		return new A;
	else if (random % 2 == 0)
		return new B;
	else 
		return new C;
}

void identify(Base *p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "Class A" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "Class B" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "Class C" << std::endl;
	else
		std::cout << "NULL" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "Class A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void) dynamic_cast<B&>(p);
			std::cout << "Class B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void) dynamic_cast<C&>(p);
				std::cout << "Class C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Unknow" << std::endl;
			}
		}
	}
}

int main(void)
{
	Base *coucou;

	coucou = generate();
	identify(coucou);
	identify(*coucou);

	return 0;
}