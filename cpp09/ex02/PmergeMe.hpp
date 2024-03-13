/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student-42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:47:01 by cmichez           #+#    #+#             */
/*   Updated: 2024/03/12 21:52:30 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <vector>

class PmergeMe
{
private:
	std::vector<int> stack;
public:
	PmergeMe();
	~PmergeMe();
};
