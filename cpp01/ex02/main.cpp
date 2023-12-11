/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:43:48 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/27 16:43:48 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << &str << std::endl;
	std::cout << "stringPTR " << ptr << std::endl;
	std::cout << "stringREF " << &ref << std::endl;

	std::cout << str << std::endl;
	std::cout << "stringPTR " << *ptr << std::endl;
	std::cout << "stringREF " << ref << std::endl;	
}