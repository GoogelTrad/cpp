/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 01:15:25 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/11 01:15:25 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class ScalarConverter
{
private:

public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	~ScalarConverter();

	ScalarConverter &operator=(const ScalarConverter &copy);

	static void convert(std::string str);
};

