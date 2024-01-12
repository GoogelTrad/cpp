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
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat *Boss = new Bureaucrat(1, "CEO");
	std::cout << *Boss << std::endl;

	try
	{
		Intern Slave;
		AForm *form = Slave.makeForm("robotomy request", "Bob");

		std::cout << *form << std::endl;

		form->beSigned(*Boss);
		Boss->executeForm(*form);
		std::cout << std::endl << *form << std::endl;

		delete form;
		delete Boss;
	}
	catch(AForm::GradeTooLowExecption& e) {
		std::cout << "Error " << e.what() << std::endl;
	}
	catch(AForm::GradeTooLowExecute &e) {
		std::cout << "Error " << e.what() << std::endl;
	}
	catch(AForm::FormNotSigned &e) {
		std::cout << "Error " << e.what() << std::endl;
	}
	catch(Intern::InvalidFormNameExecption &e) {
		std::cout << "Error " << e.what() << std::endl;
	}
	
	return 0;
}