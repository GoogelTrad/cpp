/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:59:43 by cmichez           #+#    #+#             */
/*   Updated: 2024/02/22 18:33:31 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


class Span
{
private:
	unsigned int N;
	std::vector<int> values;
public:
	Span(unsigned int _N);
	~Span();

	void addNumber(int toAdd);
	int shortestSpan(void);
	int longestSpan(void);
	void multiplAdd(std::vector<int>::iterator start, std::vector<int>::iterator end);

	Span operator=(const Span &copy);
	Span(const Span &copy);
};

