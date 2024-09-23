/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:47:01 by cmichez           #+#    #+#             */
/*   Updated: 2024/09/04 18:50:10 by cmichez          ###   ########.fr       */
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
	std::vector<int> generateVectorJacob(int n);
	void divVector(std::vector<std::vector<int> > &arr, std::vector<int> &toDiv, int &struggle);
	void makePendMainVector(std::vector<std::vector<int> > &arr, std::vector<int> &main, std::vector<int> &pend);
	void sortOddVector(std::vector<std::vector<int> > &arr);
	void sortBinarySearchVector(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &jacob, int &struggle);

	//Partie Deque
	int fillDeque(char **av);
	void sortDeque(char **av);
	std::deque<int> generateDequeJacob(int n);
	void divDeque(std::deque<std::deque<int> > &arr, std::deque<int> &toDiv, int &struggle);
	void makePendMainDeque(std::deque<std::deque<int> > &arr, std::deque<int> &main, std::deque<int> &pend);
	void sortOddDeque(std::deque<std::deque<int> > &arr);
	void sortBinarySearchDeque(std::deque<int> &main, std::deque<int> &pend, std::deque<int> &jacob, int &struggle);

};
