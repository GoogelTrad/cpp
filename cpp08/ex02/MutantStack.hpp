/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:47:47 by cmichez           #+#    #+#             */
/*   Updated: 2024/02/22 18:47:47 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <iterator>
#include <list>


template <typename T>
class MutantStack : public std::stack<T>
{
public:

	MutantStack()
	{
	}

	MutantStack(const MutantStack &copy)
	{
		this = copy;
	}

	~MutantStack()
	{
	}

	MutantStack &operator=(const MutantStack &copy)
	{
		this = copy;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	
};
