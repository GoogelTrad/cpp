/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 01:15:17 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/11 01:15:17 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	*this = copy;
	return *this;
}

void ScalarConverter::convert(std::string str)
{
	int toInt = 0;
	double toDouble = 0;
	float toFloat = 0;

	if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		std::cout << "char : '" << str[0] << "'" << std::endl;
		std::cout << "int : " << static_cast<int>(str[0]) << std::endl;
		std::cout << "double : " << static_cast<double>(str[0]) << ".0" << std::endl;
		std::cout << "float : " << static_cast<float>(str[0]) << ".0f" << std::endl;
		return ;
	}
	toInt = std::atoi(str.c_str());
	if (str[str.size() - 1] == 'f')
	{
		toFloat = std::atof(str.c_str());
		toDouble = static_cast<double>(toFloat);
	}
	else
	{
		toDouble = std::atof(str.c_str());
		toFloat = static_cast<double>(toDouble);
	}
	std::cout << "char : ";
	if (!(toInt > 31 && toInt < 128))
		std::cout << "impossible" << std::endl;
	else
		std::cout << "'" << static_cast<char>(toInt) << "'" << std::endl;
	if (std::isinf(toDouble) || std::isnan(toDouble))
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << toInt << std::endl;
	if (toInt == toFloat)
	{
		std::cout << "double : " << toDouble << ".0" << std::endl;
		std::cout << "float : " << toFloat << ".0f" << std::endl;
	}
	else
	{
		std::cout << "double : " << toDouble << std::endl;
		std::cout << "float : " << toFloat << "f" << std::endl;
	}
}