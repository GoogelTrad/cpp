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
	Bureaucrat *Bob = new Bureaucrat(42, "Bob");
	std::cout << *Bob << std::endl;

	Bureaucrat *Boss = new Bureaucrat(5, "CEO");
	std::cout << *Boss << std::endl;

	try
	{
		Form *A = new Form("Fired", 40, 20);
		std::cout << *A << std::endl;

		//Bob->signForm(A);
		//std::cout << *A << std::endl;

		Boss->signForm(A);
		std::cout << *A << std::endl;

		delete A;
		delete Bob;
		delete Boss;
	}
	catch(Form::GradeTooLowExecption& e) {
		std::cout << "Error " << e.what() << std::endl;
	}
	
	return 0;
}