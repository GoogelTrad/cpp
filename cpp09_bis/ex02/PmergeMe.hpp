/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:47:01 by cmichez           #+#    #+#             */
/*   Updated: 2024/09/04 18:25:54 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <algorithm> 

#define K 2

class PmergeMe
{
private:
	std::vector<int> stack;
	std::deque<int> myDeque;
	bool isStruggle;
public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &copy);

	//Partie Vecteur
	int fillVector(char **av);
	void sortVector(char **av);	
	void recursDivVector(std::vector<std::vector<int> > &arr, std::vector<int> toDiv, int &index);
	std::vector<int> generateVectorJacob(int n);
	std::vector<int> recursSortVector(std::vector<int> v1, std::vector<int> v2);
	std::vector<int> mergeSortedVector(std::vector<std::vector<int> > &arr);
	void divVector(std::vector<std::vector<int> > &arr, std::vector<int> &toDiv, int &struggle);
	void makePendMainVector(std::vector<std::vector<int> > &arr, std::vector<int> &main, std::vector<int> &pend);
	void mergeVector(std::vector<int> &main, std::vector<int> &pend);
	void sortOddVector(std::vector<std::vector<int> > &arr);
	void sortBinarySearchVector(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &jacob, int &struggle);

	//Partie Deque
	int fillDeque(char **av);
	void sortDeque(char **av);
	void recursDivDeque(std::deque<std::deque<int> > &arr, std::deque<int> toDiv, int &index);
	std::deque<int> recursSortDeque(std::deque<int> v1, std::deque<int> v2);
	std::deque<int> mergeSortedDeque(std::deque<std::deque<int> > &arr);
};
