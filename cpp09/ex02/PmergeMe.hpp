/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:47:01 by cmichez           #+#    #+#             */
/*   Updated: 2024/03/21 00:06:39 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <vector>

#define K 2

class PmergeMe
{
private:
	std::vector<int> stack;
public:
	PmergeMe();
	PmergeMe(const PmergeMe &copy);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &copy);

	void fillVector(char **av);
	void sortVector(char **av);	
	void recursDivVector(std::vector<std::vector<int>> &arr, std::vector<int> toDiv, int &index);
	std::vector<int> recursSortVector(std::vector<int> v1, std::vector<int> v2);
	std::vector<int> mergeSortedVector(std::vector<std::vector<int>> &arr);
};
