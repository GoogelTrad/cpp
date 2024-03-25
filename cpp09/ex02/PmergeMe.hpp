/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:47:01 by cmichez           #+#    #+#             */
/*   Updated: 2024/03/21 12:49:36 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <chrono>

#define K 2

class PmergeMe
{
private:
	std::vector<int> stack;
	std::deque<int> myDeque;
public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &copy);

	//Partie Vecteur
	int fillVector(char **av, double &durationVector);
	void sortVector(char **av);	
	void recursDivVector(std::vector<std::vector<int>> &arr, std::vector<int> toDiv, int &index);
	std::vector<int> recursSortVector(std::vector<int> v1, std::vector<int> v2);
	std::vector<int> mergeSortedVector(std::vector<std::vector<int>> &arr);

	//Partie Deque
	int fillDeque(char **av);
	void sortDeque(char **av);
	void recursDivDeque(std::deque<std::deque<int>> &arr, std::deque<int> toDiv, int &index);
	std::deque<int> recursSortDeque(std::deque<int> v1, std::deque<int> v2);
	std::deque<int> mergeSortedDeque(std::deque<std::deque<int>> &arr);
};
