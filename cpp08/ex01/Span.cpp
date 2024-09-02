/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:00:00 by cmichez           #+#    #+#             */
/*   Updated: 2024/08/30 16:16:25 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int _N) : N(_N)
{
}

Span::Span(const Span &copy)
{
	this->N = copy.N;
	this->values = copy.values;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &copy)
{
	this->N = copy.N;
	this->values = copy.values;
	return *this;
}

void Span::addNumber(int toAdd)
{
	if (this->values.size() == this->N)
		throw std::overflow_error("Maximum range reached!");
	this->values.push_back(toAdd);
}

int Span::shortestSpan(void)
{
	if (this->values.size() < 2)
		throw std::overflow_error("Not enought elements!");
	
	int diff = (*std::max_element(this->values.begin(), this->values.end())
		- *std::min_element(this->values.begin(), this->values.end()));
		
	int tmp;
	for(unsigned int i = 0; i < this->N; i++)
	{
		tmp = this->values[i];
		for (unsigned int j = i + 1; j < this->N; j++)
		{
			if (std::abs(tmp - this->values[j]) > 0 && std::abs(tmp - this->values[j]) < diff)
				diff = std::abs(tmp - this->values[j]);
		}
	}

	return diff;
}

int Span::longestSpan(void)
{
	if (this->values.size() < 2)
		throw std::overflow_error("Not enought elements!");
	int min = *std::min_element(this->values.begin(), this->values.end());
	int max = *std::max_element(this->values.begin(), this->values.end());
	
	return (max - min);
}

void Span::multiplAdd(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator i = start; i != end; i++)
		this->addNumber(*i);
}