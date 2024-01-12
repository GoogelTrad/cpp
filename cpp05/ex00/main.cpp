/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:09:35 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/06 16:09:35 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat *Bob = new Bureaucrat(1, "BoB");
		std::cout << *Bob << std::endl;
		Bob->downGrade();
		std::cout << *Bob << std::endl;
		Bob->upGrade();
		std::cout << *Bob << std::endl;
		delete Bob;
	}
	catch(const Bureaucrat::GradeTooHighExecption &e) {
		std::cerr << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowExecption &e) {
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat *Henry = new Bureaucrat(0, "Henry");
		std::cout << *Henry << std::endl;
		delete Henry;
	}
	catch(const Bureaucrat::GradeTooHighExecption &e) {
		std::cerr << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowExecption &e) {
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat *Alex = new Bureaucrat(160, "Alex");
		std::cout << *Alex << std::endl;
		delete Alex;
	}
	catch(const Bureaucrat::GradeTooHighExecption &e) {
		std::cerr << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowExecption &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}