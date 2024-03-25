/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:47:53 by cmichez           #+#    #+#             */
/*   Updated: 2024/03/21 18:11:16 by cmichez          ###   ########.fr       */
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

int PmergeMe::fillVector(char **av, double &durationVector)
{
	auto start = std::chrono::high_resolution_clock::now();	
	for (int i = 1; av[i]; i++)
	{
		int num = std::atoi(av[i]);
		if(num < 0)
			return -1;
		this->stack.push_back(num);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> duration = end - start;
	durationVector = duration.count();
	//std::cout << "Time to fill " << this->stack.size() << " elements with std::vector = " << microseconds / 1000 << "us\n";
	return 1;
}

void PmergeMe::sortVector(char **av)
{
	int index = 0;
	double durationVector;

	if (!this->fillVector(av, durationVector))
	{
		std::cout << "Error!" << std::endl;
		return;
	}
	std::vector<std::vector<int>> arr;

	auto start = std::chrono::high_resolution_clock::now();	
	
	recursDivVector(arr, this->stack, index);
	this->stack = mergeSortedVector(arr);
	
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> duration = end - start;
	double microseconds = duration.count();

	std::cout << "After : ";
	for(int i = 0 ; i < 4; i++)
	{
		std::cout << this->stack[i] << " ";
	}
	if (this->stack[4])
		std::cout << "[...]\n";
	else
		std::cout << "\n";

	std::cout << "Time to fill " << this->stack.size() << " elements with std::vector = " << durationVector / 1000 << "us\n";
	std::cout << "Time to sort " << this->stack.size() << " elements with std::vector = " << microseconds / 1000 << "us\n";
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

/********************************************************/
/****************Partie Deque****************************/
/********************************************************/

int PmergeMe::fillDeque(char **av)
{
	auto start = std::chrono::high_resolution_clock::now();	
	for (int i = 1; av[i]; i++)
	{
		int num = std::atoi(av[i]);
		if (num < 0)
			return -1;
		this->myDeque.push_back(num);
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> duration = end - start;
	double microseconds = duration.count();
	std::cout << "Time to fill " << this->myDeque.size() << " elements with std::deque = " << microseconds * 1000 / CLOCKS_PER_SEC << "us\n";
	return 1;
}

void PmergeMe::sortDeque(char **av)
{
	int index = 0;
	if(this->fillDeque(av) == -1)
	{
		std::cout << "Error!" << std::endl;
		return;
	}
	
	std::deque<std::deque<int>> arr;
	
	auto start = std::chrono::high_resolution_clock::now();	
	
	recursDivDeque(arr, this->myDeque, index);
	this->myDeque = mergeSortedDeque(arr);
	
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> duration = end - start;
	double microseconds = duration.count();
	std::cout << "Time to sort " << this->myDeque.size() << " elements with std::deque = " << microseconds * 1000 / CLOCKS_PER_SEC << "us\n";
}

void PmergeMe::recursDivDeque(std::deque<std::deque<int>> &arr, std::deque<int> toDiv, int &index)
{
	std::deque<int> firstPart;
	std::deque<int> secondPart;

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
		recursDivDeque(arr, firstPart, index);
		recursDivDeque(arr, secondPart, index);
	}
	else 
	{
		arr.push_back(toDiv);
		index++;
	}
}

std::deque<int> PmergeMe::mergeSortedDeque(std::deque<std::deque<int>> &arr)
{
	std::deque<int> res;

	for(int i = 0; i < arr.size(); i++)
		res = recursSortDeque(res, arr[i]);

	return res;
}

std::deque<int> PmergeMe::recursSortDeque(std::deque<int> v1, std::deque<int> v2)
{
	std::deque<int> res;

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