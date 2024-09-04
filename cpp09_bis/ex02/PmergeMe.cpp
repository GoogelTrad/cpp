/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:47:53 by cmichez           #+#    #+#             */
/*   Updated: 2024/09/04 18:58:26 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe() : isStruggle(false)
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	for(unsigned int i = 0; i < copy.stack.size(); i++)
		this->stack[i] = copy.stack[i];
	for(unsigned int i = 0; i < copy.myDeque.size(); i++)
		this->myDeque[i] = copy.myDeque[i];
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	std::cout << "coucou copy\n";
	for(unsigned int i = 0; i < copy.stack.size(); i++)
		this->stack[i] = copy.stack[i];
	for(unsigned int i = 0; i < copy.myDeque.size(); i++)
		this->myDeque[i] = copy.myDeque[i];

	return *this;
}

/********************************************************/
/****************Partie Vector***************************/
/********************************************************/

std::vector<int> PmergeMe::generateVectorJacob(int n)
{
	int index;
	std::vector<int> jacob;
	std::vector<int> combinaison;
	jacob.push_back(0);
	jacob.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
		if (jacob[i] > n)
			break;
	}
	jacob.erase(jacob.begin());
	jacob.erase(jacob.begin());
	
	for(int i = 1; combinaison.size() < (static_cast<unsigned int> (n)); i++)
	{
		index = jacob[i] - 1;
		combinaison.push_back(jacob[i]);
		while(index != jacob[i - 1])
		{
			combinaison.push_back(index);
			index--;
		}
	}
	
	return combinaison;
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
	if (!this->fillVector(av))
	{
		std::cout << "Error!" << std::endl;
		return;
	}

	std::vector<std::vector<int> > arr;
	std::vector<int> main;
	std::vector<int> pend;
	int struggle;

	std::clock_t start = std::clock();
	divVector(arr, this->stack, struggle);
	sortOddVector(arr);
	makePendMainVector(arr, main, pend);
	std::vector<int> jacob = generateVectorJacob(pend.size());
	sortBinarySearchVector(main, pend, jacob, struggle);
	std::swap(main, this->stack);

	std::clock_t end = std::clock();

	std::cout << "After : ";
	for(unsigned int i = 0; i < 5; i++)
		std::cout << this->stack[i] << " ";
	if (this->stack[5])
		std::cout << "[...]";
	std::cout << "\n";
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->stack.size() << " elements with std::vector = " << elapsed_time * 1000 << "us" << std::endl; 

}

void PmergeMe::sortBinarySearchVector(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &jacob, int &struggle)
{
	for(unsigned int i = 0; i < jacob.size(); i++)
	{
		if (static_cast<unsigned int>(jacob[i] - 1) < pend.size())
			main.insert(std::lower_bound(main.begin(), main.end(), pend[jacob[i] - 1]), pend[jacob[i] - 1]);
	}
	if (this->isStruggle)
		main.insert(std::lower_bound(main.begin(), main.end(), struggle), struggle);
}

void PmergeMe::divVector(std::vector<std::vector<int> > &arr, std::vector<int> &toDiv, int &struggle)
{
	std::vector<int> tmp;
	if (toDiv.size() > 1)
	{
		for(unsigned int i = 0; i < 2; i++)
		{
			if (toDiv[i])	
				tmp.push_back(toDiv[i]);
		}
	}
	else
	{
		struggle = toDiv[0];
		this->isStruggle = true;
	}
	if (tmp.size())
		arr.push_back(tmp);
	for(unsigned int i = 0; i < 2; i++)
	{
		if (!toDiv.empty())
			toDiv.erase(toDiv.begin());
	}
	if (!toDiv.empty())
		divVector(arr, toDiv, struggle);
	
	for(unsigned int i = 0; i < arr.size(); i++)
	{
		if (arr[i].size() > 1 && arr[i][1] && arr[i][0] && arr[i][0] < arr[i][1])
			std::swap(arr[i][0], arr[i][1]);
	}
}

void PmergeMe::sortOddVector(std::vector<std::vector<int> > &arr)
{
	for (unsigned int i = 0; i < arr.size() - 1; i++)
	{
		if((arr[i + 1].size() > 1) && arr[i][0] > arr[i + 1][0])
			std::swap(arr[i], arr[i + 1]);
	}
	for (unsigned int i = 0; i < arr.size() - 1; i++)
	{
		if((arr[i + 1].size() > 1) && arr[i][0] > arr[i + 1][0])
			sortOddVector(arr);
	}
}

void PmergeMe::makePendMainVector(std::vector<std::vector<int> > &arr, std::vector<int> &main, std::vector<int> &pend)
{

	for (unsigned int i = 0; i < arr.size(); i++)
	{
		if(arr[i][0] > arr[i][1])
		{
			main.push_back(arr[i][0]);
			pend.push_back(arr[i][1]);
		}
		else
		{
			pend.push_back(arr[i][0]);
			main.push_back(arr[i][1]);			
		}
	}
	if(pend[0] < main[0])
		main.insert(main.begin(), pend[0]);
}

/********************************************************/
/****************Partie Deque****************************/
/********************************************************/


std::deque<int> PmergeMe::generateDequeJacob(int n)
{
	int index;
	std::deque<int> jacob;
	std::deque<int> combinaison;
	jacob.push_back(0);
	jacob.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		jacob.push_back(jacob[i - 1] + 2 * jacob[i - 2]);
		if (jacob[i] > n)
			break;
	}
	jacob.erase(jacob.begin());
	jacob.erase(jacob.begin());
	
	for(int i = 1; combinaison.size() < (static_cast<unsigned int> (n)); i++)
	{
		index = jacob[i] - 1;
		combinaison.push_back(jacob[i]);
		while(index != jacob[i - 1])
		{
			combinaison.push_back(index);
			index--;
		}
	}
	
	return combinaison;
}

int PmergeMe::fillDeque(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		int num = std::atoi(av[i]);
		if(num < 0)
			return -1;
		this->myDeque.push_back(num);
	}

	return 1;
}

void PmergeMe::sortDeque(char **av)
{
	if (!this->fillDeque(av))
	{
		std::cout << "Error!" << std::endl;
		return;
	}

	std::deque<std::deque<int> > arr;
	std::deque<int> main;
	std::deque<int> pend;
	int struggle;

	std::clock_t start = std::clock();
	divDeque(arr, this->myDeque, struggle);
	sortOddDeque(arr);
	makePendMainDeque(arr, main, pend);
	std::deque<int> jacob = generateDequeJacob(pend.size());
	sortBinarySearchDeque(main, pend, jacob, struggle);
	std::swap(main, this->myDeque);

	std::clock_t end = std::clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << this->myDeque.size() << " elements with std::deque = " << elapsed_time * 1000 << "us" << std::endl; 

}

void PmergeMe::sortBinarySearchDeque(std::deque<int> &main, std::deque<int> &pend, std::deque<int> &jacob, int &struggle)
{
	for(unsigned int i = 0; i < jacob.size(); i++)
	{
		if (static_cast<unsigned int>(jacob[i] - 1) < pend.size())
			main.insert(std::lower_bound(main.begin(), main.end(), pend[jacob[i] - 1]), pend[jacob[i] - 1]);
	}
	if (this->isStruggle)
		main.insert(std::lower_bound(main.begin(), main.end(), struggle), struggle);
}

void PmergeMe::divDeque(std::deque<std::deque<int> > &arr, std::deque<int> &toDiv, int &struggle)
{
	std::deque<int> tmp;
	if (toDiv.size() > 1)
	{
		for(unsigned int i = 0; i < 2; i++)
		{
			if (toDiv[i])	
				tmp.push_back(toDiv[i]);
		}
	}
	else
	{
		struggle = toDiv[0];
		this->isStruggle = true;
	}
	if (tmp.size())
		arr.push_back(tmp);
	for(unsigned int i = 0; i < 2; i++)
	{
		if (!toDiv.empty())
			toDiv.erase(toDiv.begin());
	}
	if (!toDiv.empty())
		divDeque(arr, toDiv, struggle);
	
	for(unsigned int i = 0; i < arr.size(); i++)
	{
		if (arr[i].size() > 1 && arr[i][1] && arr[i][0] && arr[i][0] < arr[i][1])
			std::swap(arr[i][0], arr[i][1]);
	}
}

void PmergeMe::sortOddDeque(std::deque<std::deque<int> > &arr)
{
	for (unsigned int i = 0; i < arr.size() - 1; i++)
	{
		if((arr[i + 1].size() > 1) && arr[i][0] > arr[i + 1][0])
			std::swap(arr[i], arr[i + 1]);
	}
	for (unsigned int i = 0; i < arr.size() - 1; i++)
	{
		if((arr[i + 1].size() > 1) && arr[i][0] > arr[i + 1][0])
			sortOddDeque(arr);
	}
}

void PmergeMe::makePendMainDeque(std::deque<std::deque<int> > &arr, std::deque<int> &main, std::deque<int> &pend)
{

	for (unsigned int i = 0; i < arr.size(); i++)
	{
		if(arr[i][0] > arr[i][1])
		{
			main.push_back(arr[i][0]);
			pend.push_back(arr[i][1]);
		}
		else
		{
			pend.push_back(arr[i][0]);
			main.push_back(arr[i][1]);			
		}
	}
	if(pend[0] < main[0])
		main.insert(main.begin(), pend[0]);
}