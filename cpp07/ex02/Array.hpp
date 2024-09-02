/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:42:29 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/26 16:42:29 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
private:
	unsigned int len;
	T *arr;
public:
	Array() : len(0)
	{
		this->arr = new T[0];
	}

	Array(unsigned int len) : len(len)
	{
		this->arr = new T[len];
	}

	Array(const Array &copy)
	{
		len = copy.len;
		arr = new T[len];
		for(unsigned int i = 0; i < len; i++)
			arr[i] = copy.arr[i];
	}

	Array &operator=(const Array &copy)
	{
		len = copy.len;
		arr = new T[len];
		for(unsigned int i = 0; i < len; i++)
			arr[i] = copy.arr[i];

		return *this;
	}

	~Array()
	{
		delete[] this->arr;
	}

	class ArrayException : public std::exception
	{
		const char* what(void) const throw() {
			return "Array Exception!";
		}
	};

	T &operator[](unsigned int i) const
	{
		if (i >= len)
			throw ArrayException();
		return arr[i];
	}

	int size(void) const
	{
		return this->len;
	}
};