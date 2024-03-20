/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student-42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:47:53 by cmichez           #+#    #+#             */
/*   Updated: 2024/03/20 01:04:53 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	this->stack = copy.stack;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	this->stack = copy.stack;

	return *this;
}

void PmergeMe::fillVector(char **av)
{

	for (int i = 1; av[i]; i++)
	{
		int num = std::atoi(av[i]);
		this->stack.push_back(num);
	}
	for(int i = 0; i < this->stack.size(); i++)
		std::cout << "tmp[i] = " << this->stack[i] << std::endl;
}

void PmergeMe::sortVector(char **av)
{
	this->fillVector(av);
	recursSortVector(this->stack);
}

void PmergeMe::recursDivVector(std::vector<int> toDiv)
{
	std::vector<int> firstPart;
	std::vector<int> secondPart;
	if(toDiv.size() >= K * 2)
	{
		int mid = toDiv.size() / 2;
		for(int i = 0; i < mid; i++)
			firstPart.push_back(toDiv[i]);
		for (int i = mid; i < (mid * 2); i++)
			secondPart.push_back(toDiv[i]);
		recursDivVector(firstPart);
		recursDivVector(secondPart);
	}
	else
	{
		//recursSortVector(firstPart);
		//recursSortVector(secondPart);
	}
}