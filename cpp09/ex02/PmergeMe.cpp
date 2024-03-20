/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:47:53 by cmichez           #+#    #+#             */
/*   Updated: 2024/03/21 00:16:37 by cmichez          ###   ########.fr       */
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
}

void PmergeMe::sortVector(char **av)
{
	int index = 0;
	this->fillVector(av);
	std::vector<std::vector<int>> arr;
	recursDivVector(arr, this->stack, index);
	this->stack = mergeSortedVector(arr);
	//for (int i = 0; i < this->stack.size(); i++)
	//	std::cout << "stack[i] = " << this->stack[i] << std::endl;
}

void PmergeMe::recursDivVector(std::vector<std::vector<int>> &arr, std::vector<int> toDiv, int &index)
{
	std::vector<int> firstPart;
	std::vector<int> secondPart;

	if(toDiv.size() > 1)
	{
		for(int i = 0; i < toDiv.size() / 2; i++)
			firstPart.push_back(toDiv[i]);
		for(int i = toDiv.size() / 2; i < toDiv.size(); i++)
		{
			if (!toDiv[i])
				break;
			secondPart.push_back(toDiv[i]);
		}
		recursDivVector(arr, firstPart, index);
		recursDivVector(arr, secondPart, index);
	}
	else 
	{
		arr.push_back(toDiv);
		index++;
	}
}

std::vector<int> PmergeMe::mergeSortedVector(std::vector<std::vector<int>> &arr)
{
	std::vector<int> res;

	for(int i = 0; i < arr.size(); i++)
		res = recursSortVector(res, arr[i]);

	return res;
}

std::vector<int> PmergeMe::recursSortVector(std::vector<int> v1, std::vector<int> v2)
{
	std::vector<int> res;

	int i = 0;
	int j = 0;

	while(i < v1.size() && j < v2.size())
	{
		if(v1[i] < v2[j])
			res.push_back(v1[i++]);
		else
			res.push_back(v2[j++]);
	}
	while(i < v1.size())
		res.push_back(v1[i++]);
	while(j < v2.size())
		res.push_back(v2[j++]);

	return res;
}