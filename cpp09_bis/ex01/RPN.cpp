/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:39:48 by cmichez           #+#    #+#             */
/*   Updated: 2024/03/02 21:39:48 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &copy)
{
	this->stack = copy.stack;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &copy)
{
	this->stack = copy.stack;
	return *this;
}

bool RPN::isOp(std::string op)
{
	if (op == "+" || op == "-" || op == "*" || op == "/")
		return true;
	else
		return false;
}

double RPN::doOp(std::string operateur, double x1, double x2)
{
	if(operateur == "+")
		return (x2 + x1);
	else if (operateur == "-")
		return (x2 - x1);
	else if (operateur == "*")
		return (x2 * x1);
	else if (operateur == "/")
	{
		if (x1 == 0)
			throw std::invalid_argument("Error! Division by 0!");
		return (x2 / x1);
	}
	else
		throw std::invalid_argument("Error! Invalid operator!");
}

double RPN::calcRes(std::string av)
{
	std::stringstream ss(av);
	std::string equation;

	while(ss >> equation)
	{
		if(isOp(equation))
		{
			if (this->stack.size() < 2)
				throw std::invalid_argument("Error! Not enough arguments!");
			double x1 = this->stack.top();
			this->stack.pop();
			double x2 = this->stack.top();
			this->stack.pop();
			this->stack.push(doOp(equation, x1, x2));
		}
		else 
		{
			if (equation.size() > 1 || equation.c_str()[0] < 48 || equation.c_str()[0] > 57)
				throw std::invalid_argument("Error! Invalid argument!");
			double val = static_cast<double>(std::atof(equation.c_str()));
			this->stack.push(val);
		}
	}
	if (this->stack.size() != 1)
		throw std::invalid_argument("Error! Invalid expression!");
	return this->stack.top();
}