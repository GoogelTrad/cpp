/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 21:39:53 by cmichez           #+#    #+#             */
/*   Updated: 2024/03/02 21:39:53 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stack>

class RPN
{
private:
	std::stack<double> stack;
public:
	RPN();
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
	~RPN();
};

