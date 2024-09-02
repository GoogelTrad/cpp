/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:47:53 by cmichez           #+#    #+#             */
/*   Updated: 2024/09/02 20:30:01 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	this->stack = copy.stack;
	this->myDeque = copy.myDeque;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	this->stack = copy.stack;
	this->myDeque = copy.myDeque;

	return *this;
}

/********************************************************/
/****************Partie Vector***************************/
/********************************************************/

std::vector<int> PmergeMe::generateVectorJacob(int n)
{
	std::vector<int> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
		if (jacob[i] > n)
			break;
	}

	return jacob;
}

int PmergeMe::fillVector(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		int num = std::atoi(av[i]);
		if(num < 0)
			return -1;
		this->stack.push_back(num);
	}

	return 1;
}

void PmergeMe::sortVector(char **av)
{
	int index = 0;

	std::clock_t start = std::clock();
	if (!this->fillVector(av))
	{
		std::cout << "Error!" << std::endl;
		return;
	}

	std::vector<int> jacob = generateVectorJacob(this->stack.size());
	std::vector<std::vector<int> > arr;
	for(unsigned int i = 0 ; i < jacob.size(); i++)
	{
		std::cout << jacob[i] << " ";
	}
	recursDivVector(arr, this->stack, index);
	this->stack = mergeSortedVector(arr);
	
	std::clock_t end = std::clock();

	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "After : ";
	for(unsigned int i = 0 ; i < 4; i++)
	{
		std::cout << this->stack[i] << " ";
	}
	if (this->stack[4])
		std::cout << "[...]\n";
	else
		std::cout << "\n";
	std::cout << "Time to process a range of " << this->stack.size() << " elements with std::vector = " << elapsed_time * 1000 << "us" << std::endl; 

}

void PmergeMe::recursDivVector(std::vector<std::vector<int> > &arr, std::vector<int> toDiv, int &index)
{
	std::vector<int> firstPart;
	std::vector<int> secondPart;

	if(toDiv.size() > 1)
	{
		for(unsigned int i = 0; i < toDiv.size() / 2; i++)
			firstPart.push_back(toDiv[i]);
		for(unsigned int i = toDiv.size() / 2; i < toDiv.size(); i++)
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

std::vector<int> PmergeMe::mergeSortedVector(std::vector<std::vector<int> > &arr)
{
	std::vector<int> res;

	for(unsigned int i = 0; i < arr.size(); i++)
		res = recursSortVector(res, arr[i]);

	return res;
}

std::vector<int> PmergeMe::recursSortVector(std::vector<int> v1, std::vector<int> v2)
{
	std::vector<int> res;

	unsigned int i = 0;
	unsigned int j = 0;

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

/********************************************************/
/****************Partie Deque****************************/
/********************************************************/

int PmergeMe::fillDeque(char **av)
{
	for (unsigned int i = 1; av[i]; i++)
	{
		int num = std::atoi(av[i]);
		if (num < 0)
			return -1;
		this->myDeque.push_back(num);
	}

	return 1;
}

void PmergeMe::sortDeque(char **av)
{
	int index = 0;
	std::clock_t start = std::clock();
	if(this->fillDeque(av) == -1)
	{
		std::cout << "Error!" << std::endl;
		return;
	}
	
	std::deque<std::deque<int> > arr;
	
	recursDivDeque(arr, this->myDeque, index);
	this->myDeque = mergeSortedDeque(arr);

	std::clock_t end = std::clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->stack.size() << " elements with std::deque = " << elapsed_time * 1000 << "us" << std::endl; 
	
}

void PmergeMe::recursDivDeque(std::deque<std::deque<int> > &arr, std::deque<int> toDiv, int &index)
{
	std::deque<int> firstPart;
	std::deque<int> secondPart;

	if(toDiv.size() > 1)
	{
		for(unsigned int i = 0; i < toDiv.size() / 2; i++)
			firstPart.push_back(toDiv[i]);
		for(unsigned int i = toDiv.size() / 2; i < toDiv.size(); i++)
		{
			if (!toDiv[i])
				break;
			secondPart.push_back(toDiv[i]);
		}
		recursDivDeque(arr, firstPart, index);
		recursDivDeque(arr, secondPart, index);
	}
	else 
	{
		arr.push_back(toDiv);
		index++;
	}
}

std::deque<int> PmergeMe::mergeSortedDeque(std::deque<std::deque<int> > &arr)
{
	std::deque<int> res;

	for(unsigned int i = 0; i < arr.size(); i++)
		res = recursSortDeque(res, arr[i]);

	return res;
}

std::deque<int> PmergeMe::recursSortDeque(std::deque<int> v1, std::deque<int> v2)
{
	std::deque<int> res;

	unsigned int i = 0;
	unsigned int j = 0;

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